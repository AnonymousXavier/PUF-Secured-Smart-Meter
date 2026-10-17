import streamlit as st
import time
import socket
import subprocess
import sys
import psycopg2
import pandas as pd
import warnings

# ==========================================
# 1. PAGE CONFIGURATION
# ==========================================
st.set_page_config(page_title="Smart Meter Dashboard", layout="wide")

# ==========================================
# 2. MAIN DASHBOARD: STATE & SERVER
# ==========================================
st.title("⚡ Smart Meter Dashboard")

if 'last_packet_time' not in st.session_state:
    st.session_state.last_packet_time = None
if 'missed_beats' not in st.session_state:
    st.session_state.missed_beats = 0
if 'meter_online' not in st.session_state:
    st.session_state.meter_online = False
    
if 'server_process' not in st.session_state:
    st.session_state.server_process = None

def is_server_running():
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        try:
            s.bind(("0.0.0.0", 7556))
            return False 
        except OSError:
            return True  

server_online = is_server_running()

col_server, col_meter = st.columns(2)

with col_server:
    if server_online:
        st.markdown("""
            <div style="display: flex; align-items: center; margin-bottom: 10px;">
                <div style="width: 22px; height: 22px; background-color: #00ff00; border-radius: 50%; box-shadow: 0 0 15px #00ff00, inset 0 0 5px #ffffff; margin-right: 12px; border: 2px solid #003300;"></div>
                <span style="font-weight: bold; font-size: 1.2rem; color: #00ff00; letter-spacing: 1px;">SERVER ONLINE</span>
            </div>
        """, unsafe_allow_html=True)
        if st.button("🛑 STOP SERVER", type="secondary"):
            if st.session_state.server_process is not None:
                st.session_state.server_process.terminate()
                st.session_state.server_process = None
            time.sleep(1)
            st.rerun()
    else:
        st.markdown("""
            <div style="display: flex; align-items: center; margin-bottom: 10px;">
                <div style="width: 22px; height: 22px; background-color: #8b0000; border-radius: 50%; box-shadow: inset 0 0 8px #000000; margin-right: 12px; border: 2px solid #330000;"></div>
                <span style="font-weight: bold; font-size: 1.2rem; color: #ff4b4b; letter-spacing: 1px;">SERVER OFFLINE</span>
            </div>
        """, unsafe_allow_html=True)
        if st.button("▶️ START SERVER", type="primary"):
            st.session_state.server_process = subprocess.Popen([sys.executable, "server.py"])
            time.sleep(1) 
            st.rerun()
            
    st.write("") 
    if st.button("🧹 WIPE DATABASE", type="secondary"):
        try:
            wipe_conn = psycopg2.connect("dbname=smart_meter_db user=postgres password=Xav@2007ier host=localhost port=5432")
            wipe_cursor = wipe_conn.cursor()
            wipe_cursor.execute("TRUNCATE TABLE meter_readings;")
            wipe_conn.commit()
            wipe_cursor.close()
            wipe_conn.close()
        except Exception:
            pass
        st.rerun()

    if st.button("🔄 FORCE RESET WALLET (0 NGN)", type="primary"):
        try:
            reset_conn = psycopg2.connect("dbname=smart_meter_db user=postgres password=Xav@2007ier host=localhost port=5432")
            reset_cursor = reset_conn.cursor()
            reset_cursor.execute("UPDATE virtual_wallets SET balance_ngn = 0.0000, total_kwh = 0.0000 WHERE device_id = 1;")
            reset_conn.commit()
            reset_cursor.close()
            reset_conn.close()
            st.success("Wallet forcefully reset to ₦1,000.00 and 0 kWh!")
        except Exception as e:
            st.error(f"Reset failed: {e}")
        st.rerun()

st.divider()

# ==========================================
# 3. DATABASE FETCH & UI RENDERING
# ==========================================
try:
    pg_conn = psycopg2.connect("dbname=smart_meter_db user=postgres password=Xav@2007ier host=localhost port=5432")
    
    # Fetch Telemetry
    query = "SELECT recorded_at, voltage, current, power, packet_state, puf_key FROM meter_readings ORDER BY recorded_at DESC LIMIT 50;"
    with warnings.catch_warnings():
        warnings.simplefilter("ignore", UserWarning)
        df = pd.read_sql_query(query, pg_conn)
        
    # Fetch Wallet Data
    wallet_query = "SELECT balance_ngn, total_kwh, tariff_rate FROM virtual_wallets WHERE device_id = 1"
    with warnings.catch_warnings():
        warnings.simplefilter("ignore", UserWarning)
        wallet_df = pd.read_sql_query(wallet_query, pg_conn)
        
        current_balance = float(wallet_df.iloc[0]['balance_ngn'])
        total_units = float(wallet_df.iloc[0]['total_kwh'])
        tariff = float(wallet_df.iloc[0]['tariff_rate'])
        
        # Calculate Available Units based on the ledger
        available_units = current_balance / tariff if tariff > 0 else 0.0
        
    pg_conn.close()
except Exception:
    df = pd.DataFrame()
    current_balance, total_units, tariff, available_units = 0.0, 0.0, 225.0, 0.0

if not df.empty:
    df = df.sort_values(by="recorded_at")
    latest = df.iloc[-1]
    
    current_latest_time = str(latest['recorded_at'])
    if current_latest_time == st.session_state.last_packet_time:
        st.session_state.missed_beats += 1
    else:
        st.session_state.missed_beats = 0
        st.session_state.last_packet_time = current_latest_time
        
    st.session_state.meter_online = (st.session_state.missed_beats < 8) and server_online 

    with col_meter:
        if st.session_state.meter_online:
            st.markdown("""
                <div style="display: flex; align-items: center; margin-bottom: 10px; justify-content: flex-end;">
                    <span style="font-weight: bold; font-size: 1.2rem; color: #00e5ff; margin-right: 12px; letter-spacing: 1px;">METER CONNECTED</span>
                    <div style="width: 22px; height: 22px; background-color: #00e5ff; border-radius: 50%; box-shadow: 0 0 15px #00e5ff, inset 0 0 5px #ffffff; border: 2px solid #003344;"></div>
                </div>
            """, unsafe_allow_html=True)
        else:
            st.markdown("""
                <div style="display: flex; align-items: center; margin-bottom: 10px; justify-content: flex-end;">
                    <span style="font-weight: bold; font-size: 1.2rem; color: #666666; margin-right: 12px; letter-spacing: 1px;">METER DISCONNECTED</span>
                    <div style="width: 22px; height: 22px; background-color: #333333; border-radius: 50%; box-shadow: inset 0 0 8px #000000; border: 2px solid #111111;"></div>
                </div>
            """, unsafe_allow_html=True)

    # --- METRICS UI ---
    st.subheader("Billing & Usage")
    col_avail, col_tot, col_tar, col_bal = st.columns(4)
    col_avail.metric("Available Units", f"{available_units:.4f} kWh")
    col_tot.metric("Total Consumed", f"{total_units:.4f} kWh")
    col_tar.metric("Current Tariff", f"₦ {tariff:.2f} / kWh")
    col_bal.metric("Ledger Balance", f"₦ {current_balance:,.2f}")

    st.divider()
    
    st.subheader("Live Electrical Reading")
    col1, col2, col3 = st.columns(3)
    col1.metric("Live Voltage", f"{latest['voltage']:.4f} V")
    col2.metric("Live Current", f"{latest['current']:.4f} A")
    simulated_power = latest['power'] * 1000000 
    col3.metric("Live Power (Simulated Load)", f"{simulated_power:.2f} W")
    
    st.divider()
    
    st.subheader("Power Consumption Over Time")
    df['power'] = df['power'] * 1000000
    st.line_chart(df.set_index("recorded_at")["power"])
    
    st.subheader("Tabulated Meter Data")
    st.dataframe(df.tail(10), width="stretch")
else:
    st.warning("Waiting for meter readings... Is the ESP32 online?")

time.sleep(0.5)
st.rerun()