import socket
import json
import psycopg2
import sys

DB_CONFIG = {
    "dbname": "smart_meter_db",
    "user": "postgres",
    "password": "Xav@2007ier", 
    "host": "localhost",
    "port": "5432"
}

def start_server():
    HOST = "0.0.0.0"
    PORT = 7556

    try:
        db_conn = psycopg2.connect(**DB_CONFIG)
        db_cursor = db_conn.cursor()
        print("Connected to PostgreSQL Database Successfully.")
    except Exception as e:
        print(f"Database connection failed: {e}")
        return

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind((HOST, PORT))
    print(f"Cloud Server Listening On Port {PORT}...")
    
    while True:
        try:
            # FIX 1: Maximize buffer to prevent WinError 10040 from large bot packets
            packet, addr = s.recvfrom(65535) 
            
            # FIX 2: Silently drop non-JSON or non-UTF-8 garbage packets
            try:
                data = json.loads(packet.decode('utf-8'))
            except (json.JSONDecodeError, UnicodeDecodeError):
                continue 
            
            # --- THE GRACEFUL SHUTDOWN COMMAND ---
            if data.get('type') == 'SHUTDOWN':
                print("Shutdown signal received! Closing gracefully...")
                break
                
            if data.get('type') == 'METER_DATA':
                voltage = data.get('voltage', 0.0)
                current = data.get('current', 0.0)
                power = voltage * current
                device_id = data.get('id', 1)
                puf_key = data.get('key', 'UNKNOWN_PUF')
                state = data.get('state', 'NEW')
                timestamp = data.get('timestamp') 

                # Log the raw telemetry
                insert_query = """
                    INSERT INTO meter_readings (device_id, puf_key, voltage, current, power, packet_state, recorded_at)
                    VALUES (%s, %s, %s, %s, %s, %s, %s)
                """
                db_cursor.execute(insert_query, (device_id, puf_key, voltage, current, power, state, timestamp))
                
                # Virtual Wallet & Unit Logic
                relay_command = "ON"
                if state == 'NEW':
                    db_cursor.execute("SELECT balance_ngn, tariff_rate, total_kwh FROM virtual_wallets WHERE device_id = %s", (device_id,))
                    wallet = db_cursor.fetchone()
                    
                    if wallet:
                        balance, tariff, total_kwh = wallet
                        total_kwh = total_kwh if total_kwh is not None else 0.0 
                        
                        if balance > 0:
                            # FIX 3: Multiply the 0.0025W load by 1,000,000 to act like a 2.5kW heavy appliance
                            simulated_power_for_billing = power * 1000000 
                            
                            energy_kwh = (simulated_power_for_billing / 1000.0) * (0.2 / 3600.0)
                            cost = energy_kwh * float(tariff)
                            
                            new_balance = float(balance) - cost
                            new_total_kwh = float(total_kwh) + energy_kwh
                            
                            db_cursor.execute("UPDATE virtual_wallets SET balance_ngn = %s, total_kwh = %s WHERE device_id = %s", 
                                              (new_balance, new_total_kwh, device_id))
                            
                            print(f"Live: {voltage:.2f}V, {current:.4f}A | Wallet: {new_balance:.4f} NGN | Units: {new_total_kwh:.6f} kWh")
                            
                            out_packet = json.dumps({
                                "type": "CONFIRM", 
                                "relay": relay_command,
                                "balance": round(new_balance, 2),
                                "units": round(new_total_kwh, 4)
                            })
                            s.sendto(out_packet.encode('utf-8'), addr)
                            
                        else:
                            relay_command = "OFF"
                            print(f"DEVICE {device_id} OUT OF FUNDS. INITIATING CUTOFF.")
                            out_packet = json.dumps({
                                "type": "CONFIRM", 
                                "relay": relay_command,
                                "balance": 0.00,
                                "units": round(float(total_kwh), 4)
                            })
                            s.sendto(out_packet.encode('utf-8'), addr)
                            
                elif state == 'OLD':
                    print(f"Recovered Offline Data Saved to DB from: {timestamp}")
                
                db_conn.commit()
                
        except Exception as e:
            # Catch any other database/socket level errors
            print(f"System Error: {e}")
            if 'db_conn' in locals():
                db_conn.rollback()
                
    s.close()
    db_cursor.close()
    db_conn.close()
    print("Server fully offline.")
    sys.exit(0)

if __name__ == '__main__':
    start_server()
