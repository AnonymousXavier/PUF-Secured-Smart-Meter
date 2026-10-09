This file is a merged representation of the entire codebase, combined into a single document by Repomix.

# File Summary

## Purpose
This file contains a packed representation of the entire repository's contents.
It is designed to be easily consumable by AI systems for analysis, code review,
or other automated processes.

## File Format
The content is organized as follows:
1. This summary section
2. Repository information
3. Directory structure
4. Repository files (if enabled)
5. Multiple file entries, each consisting of:
  a. A header with the file path (## File: path/to/file)
  b. The full contents of the file in a code block

## Usage Guidelines
- This file should be treated as read-only. Any changes should be made to the
  original repository files, not this packed version.
- When processing this file, use the file path to distinguish
  between different files in the repository.
- Be aware that this file may contain sensitive information. Handle it with
  the same level of security as you would the original repository.

## Notes
- Some files may have been excluded based on .gitignore rules and Repomix's configuration
- Binary files are not included in this packed representation. Please refer to the Repository Structure section for a complete list of file paths, including binary files
- Files matching patterns in .gitignore are excluded
- Files matching default ignore patterns are excluded
- Files are sorted by Git change count (files with more changes are at the bottom)

# Directory Structure
````
data/
  portal.html
include/
  README
lib/
  README
src/
  .theia/
    launch.json
  .vscode/
    c_cpp_properties.json
  server/
    dashboard.py
    recovered_meter_data.csv
    server.py
  CaptivePortal.cpp
  CaptivePortal.h
  DisplayData.h
  DisplayManager.cpp
  DisplayManager.h
  Final Year Project.cpp
  MeterLogic.cpp
  MeterLogic.h
  NetworkingModule.cpp
  NetworkingModule.h
  repomix-output.md
  RTCManager.cpp
  RTCManager.h
  StorageManager.cpp
  StorageManager.h
test/
  README
.gitignore
platformio.ini
recovered_meter_data.csv
````

# Files

## File: data/portal.html
````html
<!DOCTYPE html>
<html>
<head>
  <title>Smart Meter Portal</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { background-color: #121212; color: #00ff00; font-family: monospace; padding: 20px; }
    h2 { border-bottom: 1px solid #00ff00; padding-bottom: 10px; }
    p { color: #888; font-size: 0.9em; margin-bottom: 20px; }
    label { display: block; margin-top: 15px; font-weight: bold; }
    input { display: block; margin-top: 5px; margin-bottom: 15px; width: 100%; padding: 10px; background: #222; color: #00ff00; border: 1px solid #00ff00; box-sizing: border-box; }
    button { background: #00ff00; color: #000; padding: 15px; border: none; font-weight: bold; width: 100%; cursor: pointer; margin-top: 10px; }
    button:hover { background: #00cc00; }
  </style>
</head>
<body>
  <h2>⚡ PUF METER CONFIG</h2>
  <p>Leave fields blank to keep current hardware settings.</p>
  
  <form action="/config" method="GET">
    <label>WiFi SSID:</label>
    <input type="text" name="wifi_ssid" placeholder="Enter new network name">
    
    <label>WiFi Password:</label>
    <input type="password" name="wifi_password" placeholder="Enter new password">
    
    <label>Target Server IP (Play.gg):</label>
    <input type="text" name="server_ip" placeholder="e.g. 147.185.221.231">
    
    <!-- MISSING THIS BLOCK -->
    <label>Target Port (Play.gg):</label>
    <input type="number" name="server_port" placeholder="e.g. 48178">
    <!-- ------------------ -->
    
    <label>RTC Hardware Time:</label>
    <input type="datetime-local" name="rtc_time">
    
    <button type="submit">UPDATE FIRMWARE</button>
  </form>
</body>
</html>
````

## File: include/README
````
This directory is intended for project header files.

A header file is a file containing C declarations and macro definitions
to be shared between several project source files. You request the use of a
header file in your project source file (C, C++, etc) located in `src` folder
by including it, with the C preprocessing directive `#include'.

```src/main.c

#include "header.h"

int main (void)
{
 ...
}
```

Including a header file produces the same results as copying the header file
into each source file that needs it. Such copying would be time-consuming
and error-prone. With a header file, the related declarations appear
in only one place. If they need to be changed, they can be changed in one
place, and programs that include the header file will automatically use the
new version when next recompiled. The header file eliminates the labor of
finding and changing all the copies as well as the risk that a failure to
find one copy will result in inconsistencies within a program.

In C, the convention is to give header files names that end with `.h'.

Read more about using header files in official GCC documentation:

* Include Syntax
* Include Operation
* Once-Only Headers
* Computed Includes

https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html
````

## File: lib/README
````
This directory is intended for project specific (private) libraries.
PlatformIO will compile them to static libraries and link into the executable file.

The source code of each library should be placed in a separate directory
("lib/your_library_name/[Code]").

For example, see the structure of the following example libraries `Foo` and `Bar`:

|--lib
|  |
|  |--Bar
|  |  |--docs
|  |  |--examples
|  |  |--src
|  |     |- Bar.c
|  |     |- Bar.h
|  |  |- library.json (optional. for custom build options, etc) https://docs.platformio.org/page/librarymanager/config.html
|  |
|  |--Foo
|  |  |- Foo.c
|  |  |- Foo.h
|  |
|  |- README --> THIS FILE
|
|- platformio.ini
|--src
   |- main.c

Example contents of `src/main.c` using Foo and Bar:
```
#include <Foo.h>
#include <Bar.h>

int main (void)
{
  ...
}

```

The PlatformIO Library Dependency Finder will find automatically dependent
libraries by scanning project source files.

More information about PlatformIO Library Dependency Finder
- https://docs.platformio.org/page/librarymanager/ldf.html
````

## File: src/.theia/launch.json
````json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  "version": "0.2.0",
  "configurations": [
  
  ]
}
````

## File: src/.vscode/c_cpp_properties.json
````json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ]
        }
    ],
    "version": 4
}
````

## File: src/server/dashboard.py
````python
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
# 2. SIDEBAR VENDING STATION
# ==========================================
with st.sidebar:
    st.header("💳 Vending Station")
    st.write("Simulate purchasing units via a payment gateway.")
    
    # Fetch tariff rate quickly for the preview
    try:
        temp_conn = psycopg2.connect("dbname=smart_meter_db user=postgres password=Xav@2007ier host=localhost port=5432")
        temp_df = pd.read_sql_query("SELECT tariff_rate FROM virtual_wallets WHERE device_id = 1", temp_conn)
        current_tariff = float(temp_df.iloc[0]['tariff_rate'])
        temp_conn.close()
    except Exception:
        current_tariff = 225.0
        
    topup_amount = st.number_input("Top-Up Amount (₦)", min_value=100.0, step=100.0, value=1000.0)
    preview_units = topup_amount / current_tariff
    
    st.info(f"Equivalent: **{preview_units:.2f} kWh** at ₦{current_tariff}/kWh")
    
    if st.button("🔌 Purchase Units", type="primary", use_container_width=True):
        try:
            vend_conn = psycopg2.connect("dbname=smart_meter_db user=postgres password=Xav@2007ier host=localhost port=5432")
            vend_cursor = vend_conn.cursor()
            # Add the top-up amount directly to the database balance
            vend_cursor.execute("UPDATE virtual_wallets SET balance_ngn = balance_ngn + %s WHERE device_id = 1", (topup_amount,))
            vend_conn.commit()
            vend_cursor.close()
            vend_conn.close()
            
            st.success(f"Successfully added ₦{topup_amount:,.2f}!")
            time.sleep(1) # Let the user see the success message before refresh
            st.rerun()
        except Exception as e:
            st.error(f"Transaction failed: {e}")

# ==========================================
# 3. MAIN DASHBOARD: STATE & SERVER
# ==========================================
st.title("⚡ PUF Smart Meter Live Telemetry")

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
    if st.button("🧹 WIPE DATABASE (FIX GHOST DATA)", type="secondary"):
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

st.divider()

# ==========================================
# 4. DATABASE FETCH & UI RENDERING
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
    
    st.subheader("Live Electrical Telemetry")
    col1, col2, col3 = st.columns(3)
    col1.metric("Live Voltage", f"{latest['voltage']:.4f} V")
    col2.metric("Live Current", f"{latest['current']:.4f} A")
    # Simulate the heavy appliance multiplier visually on the dashboard
    simulated_power = latest['power'] * 1000000 
    col3.metric("Live Power (Simulated Load)", f"{simulated_power:.2f} W")
    
    st.divider()
    
    st.subheader("Power Consumption Over Time")
    # Apply the same visual multiplier to the graph
    df['power'] = df['power'] * 1000000
    st.line_chart(df.set_index("recorded_at")["power"])
    
    st.subheader("Raw Telemetry & Audit Log")
    st.dataframe(df.tail(10), width="stretch")
else:
    st.warning("Waiting for telemetry data... Is the ESP32 online?")

time.sleep(0.5)
st.rerun()
````

## File: src/server/recovered_meter_data.csv
````
Timestamp,Voltage,Current,Power
2026-08-10 12:00:05,4.998779,0.0005,0.0024993895
2026-08-10 12:00:10,4.998779,0.0005,0.0024993895
2026-08-10 12:00:15,4.998779,0.0005,0.0024993895
2026-08-10 12:00:20,4.998779,0.0005,0.0024993895
2026-08-10 12:00:25,4.998779,0.0005,0.0024993895
2026-08-10 12:00:30,4.998779,0.0005,0.0024993895
2026-08-10 12:00:36,4.998779,0.0005,0.0024993895
2026-08-10 12:00:41,4.998779,0.0005,0.0024993895
2026-08-10 12:00:46,4.998779,0.0005,0.0024993895
2026-08-10 12:00:51,4.998779,0.0005,0.0024993895
2026-08-10 12:00:56,4.588623,0.0005,0.0022943115
2026-08-10 12:01:01,4.998779,0.0005,0.0024993895
2026-08-10 12:01:06,4.888916,0.0005,0.002444458
2026-08-10 12:01:12,4.998779,0.0005,0.0024993895
2026-08-10 12:01:17,4.949951,0.0005,0.0024749755
2026-08-10 12:01:22,4.998779,0.0005,0.0024993895
2026-08-10 12:01:27,4.979248,0.0005,0.002489624
2026-08-10 12:01:32,4.998779,0.0005,0.0024993895
2026-08-10 12:01:37,4.998779,0.0005,0.0024993895
2026-08-10 12:01:42,4.998779,0.0005,0.0024993895
2026-08-10 12:01:47,4.998779,0.0005,0.0024993895
2026-08-10 12:01:53,4.998779,0.0005,0.0024993895
2026-08-10 12:01:58,4.998779,0.0005,0.0024993895
2026-08-10 12:02:03,4.998779,0.0005,0.0024993895
2026-08-10 12:02:08,4.87915,0.0005,0.0024395750000000003
2026-08-10 12:02:13,4.731445,0.0005,0.0023657225
2026-08-10 12:02:18,4.837646,0.0005,0.002418823
2026-08-10 12:02:23,4.998779,0.0005,0.0024993895
2026-08-10 12:02:29,4.837646,0.0005,0.002418823
2026-08-10 12:02:34,4.93042,0.0005,0.00246521
2026-08-10 12:02:39,4.998779,0.0005,0.0024993895
2026-08-10 12:02:44,4.998779,0.0005,0.0024993895
2026-08-10 12:02:49,4.898682,0.0005,0.002449341
2026-08-10 12:02:54,4.969482,0.0005,0.002484741
2026-08-10 12:03:00,4.783936,0.0005,0.002391968
2026-08-10 12:03:05,4.898682,0.0005,0.002449341
2026-08-10 12:03:34,4.998779,0.0005,0.0024993895
2026-08-10 12:03:39,4.998779,0.0005,0.0024993895
2026-08-10 12:03:44,4.998779,0.0005,0.0024993895
2026-08-10 12:03:50,4.998779,0.0005,0.0024993895
2026-08-10 12:03:55,4.998779,0.0005,0.0024993895
2026-08-10 12:04:00,4.998779,0.0005,0.0024993895
2026-08-10 12:04:05,4.998779,0.0005,0.0024993895
2026-08-10 12:04:10,4.998779,0.0005,0.0024993895
2026-08-10 12:04:16,4.998779,0.0005,0.0024993895
2026-08-10 12:04:21,4.998779,0.0005,0.0024993895
2026-08-10 12:04:26,4.998779,0.0005,0.0024993895
2026-08-10 12:04:31,4.998779,0.0005,0.0024993895
2026-08-10 12:04:36,4.998779,0.0005,0.0024993895
2026-08-10 12:04:41,4.998779,0.0005,0.0024993895
2026-08-10 12:04:47,4.998779,0.0005,0.0024993895
````

## File: src/server/server.py
````python
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
````

## File: src/CaptivePortal.cpp
````cpp
#include "CaptivePortal.h"
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <LittleFS.h>

#include "NetworkingModule.h"
#include "RTCManager.h"


const byte DNS_PORT = 53;
DNSServer dnsServer;
WebServer server(80);

void setup_portal() {
  // 1. Enable dual mode: Station (Client to Python) + Access Point (For Phones)
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("Smart Meter");

  // 2. Start DNS Server to hijack all requests and route to the ESP32's AP IP
  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

  // 3. Serve the HTML dashboard when a user connects (The Captive Portal Trigger)
  server.onNotFound([]() {
    if (LittleFS.exists("/portal.html")) {
      File file = LittleFS.open("/portal.html", "r");
      server.streamFile(file, "text/html");
      file.close();
    } else {
      server.send(200, "text/plain", "Dashboard missing from flash memory! Upload LittleFS image.");
    }
  });

  // 4. Handle the Configuration form submission
  server.on("/config", HTTP_GET, []() {
    // Extract ALL the variables from the URL
    String new_ssid = server.arg("wifi_ssid");
    String new_pass = server.arg("wifi_password");
    String new_ip = server.arg("server_ip");
    String new_port = server.arg("server_port"); // <--- MISSING THIS LINE
    String new_time = server.arg("rtc_time"); 
    
    Serial.println("--- NEW CONFIGURATION RECEIVED ---");
    Serial.println("WiFi SSID: " + new_ssid);
    Serial.println("Target Server IP: " + new_ip);
    Serial.println("Target Server Port: " + new_port); // <--- Add this print to check it
    Serial.println("----------------------------------");

    // Pass the NEW PORT to the hardware!
    update_network_config(new_ssid, new_pass, new_ip, new_port); // <--- ADD new_port HERE
    update_rtc_time(new_time);

    String htmlResponse = "<h2>Configuration Saved!</h2>";
    htmlResponse += "<p>Network: " + new_ssid + "</p>";
    htmlResponse += "<p>IP updated to: " + new_ip + ":" + new_port + "</p>";
    htmlResponse += "<br><a href='/'>Return to Dashboard</a>";
    
    server.send(200, "text/html", htmlResponse);
  });

  server.begin();
  Serial.println("Captive Portal Started. Connect to 'Smart Meter'");
}

void handle_portal() {
  dnsServer.processNextRequest();
  server.handleClient();
}
````

## File: src/CaptivePortal.h
````c
#pragma once

#include <Arduino.h>

void setup_portal();
void handle_portal();
void update_network_config(String new_ssid, String new_pass, String new_ip);
````

## File: src/DisplayData.h
````c
#pragma once
#include <Arduino.h>

struct SystemState {
    String IP;
    bool isWifiConnected;
    bool isServerOnline;
    String totalPowerUsed;
    unsigned long offlineDownTime;
    // --- NEW FIELDS ---
    float availableUnits;
    bool isRelayOn;
};
````

## File: src/DisplayManager.cpp
````cpp
#include "DisplayManager.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int LCD_SDA_PIN = 8;
const int LCD_SCL_PIN = 9;
const int BTN_PIN = 4;

DISPLAY_STATES lcd_state = CONNECTING_TO_WIFI;

String text_top;
String text_bottom; 

bool is_btn_held = false;

void setup_lcd(){
  pinMode(BTN_PIN, OUTPUT);
  Wire.begin(LCD_SDA_PIN, LCD_SCL_PIN);

  lcd.init();
  lcd.backlight();
}

void update_lcd(SystemState systemState){
  if (digitalRead(BTN_PIN) == HIGH){
    if (!is_btn_held) {
      lcd_state = static_cast<DISPLAY_STATES>((lcd_state + 1) % COUNT);
      is_btn_held = true;
    }
  } else {
    is_btn_held = false;
  }

    switch (lcd_state) {
    case CONNECTING_TO_WIFI:
        if (!systemState.isWifiConnected) {
          // No WiFi = definitely no server
          lcd_print_text("WiFi: Connecting", "Server: Offline "); 
        } else {
          // WiFi is connected! Show the IP on top.
          String topText = systemState.IP;
          
          // Check server status for the bottom row
          String bottomText = systemState.isServerOnline ? "Server: Online " : "Server: Offline ";
          
          lcd_print_text(topText, bottomText);
        }
        break;
    case POWER_USAGE:
        if (systemState.isRelayOn) {
            // Row 1: Live Power
            String pwr_str = "PWR: " + systemState.totalPowerUsed;
            
            // Row 2: Available Units 
            String bal_str = "BAL: " + String(systemState.availableUnits, 4) + " kWh";
            
            lcd_print_text(pwr_str, bal_str);
        } else {
            lcd_print_text("FUNDS EXHAUSTED!", "RELAY DISABLED");
        }
        break;
    case OFFLINE_DOWN_TIME:
        lcd_print_text("BEEN OFFLINE FOR", get_time_info_from_ms(systemState.offlineDownTime));
        break;
    }
}

String get_time_info_from_ms(unsigned long ms_passed){
  char timeString[20]; // Increased buffer size for safety

  // Calculate total units
  unsigned long total_secs = ms_passed / 1000;
  
  // Use modulo (%) to get the remaining parts
  short secs  = total_secs % 60;
  short mins  = (total_secs / 60) % 60;
  short hours = (total_secs / 3600) % 24;
  short days  = total_secs / 86400;

  // Combine into a single format string
  sprintf(timeString, "%02dd %02dh %02dm %02ds", days, hours, mins, secs);

  return String(timeString);
}


void lcd_print_text(const String &text_top, const String &text_bottom){
  const int LCD_COLS = 16; // Change to 20 if using a 20x4 display

  // Process top line
  String padded_top = text_top;
  while(padded_top.length() < LCD_COLS) {
    padded_top += " ";
  }
  lcd.setCursor(0, 0);
  lcd.print(padded_top);

  // Process bottom line
  String padded_bottom = text_bottom;
  while(padded_bottom.length() < LCD_COLS) {
    padded_bottom += " ";
  }
  lcd.setCursor(0, 1);
  lcd.print(padded_bottom);
}
````

## File: src/DisplayManager.h
````c
#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "DisplayData.h"


enum DISPLAY_STATES {CONNECTING_TO_WIFI, POWER_USAGE, OFFLINE_DOWN_TIME, COUNT};

void setup_lcd();
void update_lcd(SystemState systemState);
void lcd_print_text(const String &text_top, const String &text_bottom);
String get_time_info_from_ms(unsigned long ms_passed);
````

## File: src/Final Year Project.cpp
````cpp
#include <Arduino.h>

#include "NetworkingModule.h"
#include "MeterLogic.h"
#include "StorageManager.h"
#include "DisplayManager.h"
#include "DisplayData.h"
#include "RTCManager.h" 
#include "CaptivePortal.h" // 1. Include the new module

SystemState displayState = {
  .IP="", 
  .isWifiConnected=false, 
  .isServerOnline=false,
  .totalPowerUsed="", 
  .offlineDownTime=0ul,
  .availableUnits=0.0f,   // NEW
  .isRelayOn=true         // NEW
};

void setup() {
  setup_lcd();
  setup_network();
  setup_meter();
  setup_storage();
  setup_rtc(); 
  
  setup_portal(); // 2. Spin up the Access Point
}

void update_display_data(){
  displayState.isWifiConnected = WiFi.status() == WL_CONNECTED;
  displayState.IP = WiFi.localIP().toString();
  displayState.isServerOnline = get_server_status(); 
  displayState.totalPowerUsed = String(get_load_value() * 25 / 10000.0) + " W";
  displayState.offlineDownTime = get_time_offline();
  displayState.availableUnits = get_available_units(); // NEW
  displayState.isRelayOn = get_relay_state();          // NEW
}


void loop() {
  handle_network(); 
  update_storage();
  
  handle_portal(); // 3. Listen for connecting phones and button clicks

  if (packet_failed_to_send()) {
    log_data_locally(generate_packet(true)); 
  }

  update_load_consumed(get_load_value());
  update_display_data();
  update_lcd(displayState);
}
````

## File: src/MeterLogic.cpp
````cpp
#include "MeterLogic.h"

const int POTENTIOMETER_PIN = 17;

// --- NEW: Virtual Relay State ---
bool virtual_relay_active = true; 

// We will keep the pin definition just in case you find an LED to use as a proxy
const int PROXY_LED_PIN = 18; 

int load_consumed;

void setup_meter(){
  setup_load();
  
  pinMode(PROXY_LED_PIN, OUTPUT);
  digitalWrite(PROXY_LED_PIN, HIGH); // Default to ON
}

void setup_load() {
  pinMode(POTENTIOMETER_PIN, INPUT);
}

float get_load_value(){
  // --- THE VIRTUAL CUTOFF ---
  if (!virtual_relay_active) {
      return 0.0; // Force load to 0W if funds are exhausted
  }
  
  int sensorValue = analogRead(POTENTIOMETER_PIN);
  float factor = (sensorValue / 4096.0);
  return factor;
}

// --- NEW: Actuation Function ---
void update_relay(bool enable) {
    virtual_relay_active = enable;
    
    // If you have a standard LED, it will turn off when funds run out
    if (enable) {
        digitalWrite(PROXY_LED_PIN, HIGH);
    } else {
        digitalWrite(PROXY_LED_PIN, LOW);
    }
}
````

## File: src/MeterLogic.h
````c
#pragma once

#include <Arduino.h>

void setup_meter();
void setup_load();

float get_load_value();
````

## File: src/NetworkingModule.cpp
````cpp
#include "NetworkingModule.h"
#include "DisplayManager.h"
#include "RTCManager.h" 
#include "StorageManager.h" // NEW: Let networking access the storage

JsonDocument in_packet_doc;

// TIME
unsigned long current_time;
int max_wait_time = 5000; // 5s
const float PACKET_SEND_RATE = 5; // N Per Sec 
long LAST_PACKET_SENT_TIME = millis();
// NEW: Backlog Timing Variables
unsigned long LAST_BACKLOG_TIME = 0;
const float BACKLOG_SEND_RATE = 2.0; // 2 Per Sec

// NEW: Server Health State
bool is_server_online = false;
float server_available_units = 0.0;
bool server_relay_state = true; 

STATES state = IDLE;

// NETWORK
WiFiUDP udp;
String network_ssid = "Realme Note 50";
String network_pass = "12345678";
int target_port = 48178; // Now it can be changed!

IPAddress clientAddress(147, 185, 221, 231); 

bool did_data_fail_to_send = false;

// DATA FOR TRANSFER
const int ID = 1;
float pot_factor;
char PUF_KEY[] = "10111011101";

void setup_network() {
  Serial.begin(115200);


  // Handle WIFI Connection
  // Inside setup_network(), change to this:
  WiFi.begin(network_ssid.c_str(), network_pass.c_str());
 // Begin Attempt to connect to WIFI
  udp.begin(target_port); // Allow Packet Transfer
}

bool can_send_packet() {
  return (millis() - LAST_PACKET_SENT_TIME) >= (1000.0 / PACKET_SEND_RATE);
} 

void handle_network() {
  // ==========================================
  // 1. LIVE DATA HANDLING (Your existing code)
  // ==========================================
  if (state == IDLE) {
    if (can_send_packet()) {
      udp.beginPacket(clientAddress, target_port);
      serializeJson(generate_packet(), udp); 
      udp.endPacket();
      
      Serial.println("Sent Live Packet");
      state = WAITING_FOR_SERVER;
      current_time = millis(); 
      LAST_PACKET_SENT_TIME = current_time;
    } 
  }
    else if (state == WAITING_FOR_SERVER) {
    // Timeout Check
    if (get_ms_passed() > max_wait_time) {
      state = IDLE; 
      Serial.println("Error: Server took too long to respond."); 
      did_data_fail_to_send = true;
      
      // NEW: Server is down! Close the gate.
      is_server_online = false; 
      return; 
    } 
    
    if (udp.parsePacket()) { 
      DeserializationError error = deserializeJson(in_packet_doc, udp);
      if (error || in_packet_doc["type"] != "CONFIRM") {
        state = IDLE;
        return;
      }
      Serial.println("Received valid 'CONFIRM' from server."); 
      
      // --- NEW: PARSE BILLING & RELAY ---
      if (in_packet_doc.containsKey("balance")) {
          float balance = in_packet_doc["balance"].as<float>();
          // Convert the NGN balance back to kWh units for the display
          server_available_units = balance / 225.0; 
      }
      if (in_packet_doc.containsKey("relay")) {
          String relay_cmd = in_packet_doc["relay"].as<String>();
          server_relay_state = (relay_cmd == "ON");
      }

      state = IDLE; 
      did_data_fail_to_send = false;
      is_server_online = true; 
    }
  }


  // ==========================================
  // 2. ASYNCHRONOUS BACKLOG SYNC
  // ==========================================
  
  // NEW: Only run if WiFi is connected, a backlog exists, AND the server is confirmed online!
  if (WiFi.status() == WL_CONNECTED && has_backlog() && is_server_online) {
    
    if (millis() - LAST_BACKLOG_TIME >= (1000.0 / BACKLOG_SEND_RATE)) {
      String offline_packet = read_next_backlog_packet();
      
      if (offline_packet.length() > 0) {
        udp.beginPacket(clientAddress, target_port);
        udp.print(offline_packet); // Send the raw string
        udp.endPacket();
        
        LAST_BACKLOG_TIME = millis();
        Serial.println("Sent Backlog Packet");
      }
    }
  }

}

unsigned long get_ms_passed() { // This increases the max value to 2^32 - 1ms (about 48 Days of inactivity before it stops counting)
  return millis() - current_time;
}

STATES get_network_state() {
  return state;
}

void update_load_consumed(float load){
  pot_factor = load;
}

bool packet_failed_to_send() {
  // If a failure was flagged...
  if (did_data_fail_to_send) {
    // Reset the flag immediately so we don't spam the flash memory!
    did_data_fail_to_send = false; 
    return true;
  }
  return false;
}

JsonDocument generate_packet(bool is_backlog){
  JsonDocument packet;

  packet["type"] = "METER_DATA";
  // The server can use this to route the data
  packet["state"] = is_backlog ? "OLD" : "NEW"; 
  // Crucial: The server needs to know when this OLD data was recorded
  packet["timestamp"] = get_current_timestamp(); 
  
  packet["key"] = PUF_KEY;
  packet["voltage"] = pot_factor * 5.0 ; 
  packet["current"] = 5.0 /  10000.0; 
  packet["id"] = ID;

  return packet;
}

bool get_server_status() {
  return is_server_online;
}

// 3. Update the configuration function at the bottom
void update_network_config(String new_ssid, String new_pass, String new_ip, String new_port) {
  bool wifi_changed = false;

  if (new_ssid.length() > 0 && new_ssid != network_ssid) {
    network_ssid = new_ssid;
    wifi_changed = true;
  }
  
  if (new_pass.length() > 0 && new_pass != network_pass) {
    network_pass = new_pass;
    wifi_changed = true;
  }
  
  if (new_ip.length() > 0) {
    clientAddress.fromString(new_ip); 
    Serial.println("Play.gg IP updated to: " + clientAddress.toString());
  }

  // NEW: Update the target port
  if (new_port.length() > 0) {
    target_port = new_port.toInt();
    Serial.println("Play.gg Port updated to: " + String(target_port));
  }

  if (wifi_changed) {
    Serial.println("Reconnecting WiFi with new credentials...");
    WiFi.disconnect();
    WiFi.begin(network_ssid.c_str(), network_pass.c_str());
  }
}

float get_available_units() {
  return server_available_units;
}

bool get_relay_state() {
  return server_relay_state;
}
````

## File: src/NetworkingModule.h
````c
#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>


enum STATES {IDLE, WAITING_FOR_SERVER};

void setup_network();
void handle_network();
unsigned long get_ms_passed();

// Change the signature to accept the flag with a default value
JsonDocument generate_packet(bool is_backlog = false);


bool packet_failed_to_send();
bool get_server_status();

void update_load_consumed(float load);

STATES get_network_state();
// Change the update function to accept the port
void update_network_config(String new_ssid, String new_pass, String new_ip, String new_port);
// Add to the bottom:
float get_available_units();
bool get_relay_state();
````

## File: src/repomix-output.md
````markdown
This file is a merged representation of the entire codebase, combined into a single document by Repomix.

# File Summary

## Purpose
This file contains a packed representation of the entire repository's contents.
It is designed to be easily consumable by AI systems for analysis, code review,
or other automated processes.

## File Format
The content is organized as follows:
1. This summary section
2. Repository information
3. Directory structure
4. Repository files (if enabled)
5. Multiple file entries, each consisting of:
  a. A header with the file path (## File: path/to/file)
  b. The full contents of the file in a code block

## Usage Guidelines
- This file should be treated as read-only. Any changes should be made to the
  original repository files, not this packed version.
- When processing this file, use the file path to distinguish
  between different files in the repository.
- Be aware that this file may contain sensitive information. Handle it with
  the same level of security as you would the original repository.

## Notes
- Some files may have been excluded based on .gitignore rules and Repomix's configuration
- Binary files are not included in this packed representation. Please refer to the Repository Structure section for a complete list of file paths, including binary files
- Files matching patterns in .gitignore are excluded
- Files matching default ignore patterns are excluded
- Files are sorted by Git change count (files with more changes are at the bottom)

# Directory Structure
```
.theia/
  launch.json
server/
  server.py
CaptivePortal.cpp
CaptivePortal.h
DisplayData.h
DisplayManager.cpp
DisplayManager.h
Final Year Project.cpp
MeterLogic.cpp
MeterLogic.h
NetworkingModule.cpp
NetworkingModule.h
RTCManager.cpp
RTCManager.h
StorageManager.cpp
StorageManager.h
```

# Files

## File: .theia/launch.json
```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  "version": "0.2.0",
  "configurations": [
  
  ]
}
```

## File: server/server.py
```python
import socket
import json

# 0.0.0.0 tells the cloud server to listen on all public network interfaces
UDP_IP = "0.0.0.0" 
UDP_PORT = 7556

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print(f"Cloud Server Listening On Port {UDP_PORT}...");
while True:
    data, addr = sock.recvfrom(1024)
    try:
        packet = json.loads(data.decode('utf-8'))
        
        # Print the data just like your local terminal
        if packet.get('state') == 'OLD':
            print(f"Recovered Offline Data from: {packet.get('timestamp')}")
        else:
            print(f"Live: {packet.get('voltage')}V, {packet.get('current')}A")
            
        # Send the CONFIRM back to the ESP32 using the public IP it connected from
        confirm_msg = json.dumps({"type": "CONFIRM"}).encode('utf-8')
        sock.sendto(confirm_msg, addr)
        
    except Exception as e:
        print(f"Failed to parse packet: {e}")
```

## File: CaptivePortal.cpp
```cpp
#include "CaptivePortal.h"
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <LittleFS.h>

#include "NetworkingModule.h"
#include "RTCManager.h"


const byte DNS_PORT = 53;
DNSServer dnsServer;
WebServer server(80);

void setup_portal() {
  // 1. Enable dual mode: Station (Client to Python) + Access Point (For Phones)
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("Smart Meter");

  // 2. Start DNS Server to hijack all requests and route to the ESP32's AP IP
  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

  // 3. Serve the HTML dashboard when a user connects (The Captive Portal Trigger)
  server.onNotFound([]() {
    if (LittleFS.exists("/portal.html")) {
      File file = LittleFS.open("/portal.html", "r");
      server.streamFile(file, "text/html");
      file.close();
    } else {
      server.send(200, "text/plain", "Dashboard missing from flash memory! Upload LittleFS image.");
    }
  });

  // 4. Handle the Configuration form submission
  server.on("/config", HTTP_GET, []() {
    // Extract ALL the variables from the URL
    String new_ssid = server.arg("wifi_ssid");
    String new_pass = server.arg("wifi_password");
    String new_ip = server.arg("server_ip");
    String new_time = server.arg("rtc_time"); // Format comes in as YYYY-MM-DDTHH:MM
    
    // Print them to the Serial monitor to prove we caught them!
    Serial.println("--- NEW CONFIGURATION RECEIVED ---");
    Serial.println("WiFi SSID: " + new_ssid);
    Serial.println("WiFi Pass: " + String(new_pass.length() > 0 ? "********" : "[OPEN NETWORK]"));
    Serial.println("Target Server IP: " + new_ip);
    Serial.println("New RTC Time: " + new_time);
    Serial.println("----------------------------------");

    Serial.println("Target Server IP: " + new_ip);
    Serial.println("New RTC Time: " + new_time);
    Serial.println("----------------------------------");

    // NEW: Apply the configurations to the hardware!
    update_network_config(new_ssid, new_pass, new_ip);
    update_rtc_time(new_time);

    // Send a success page back to the phone


    // Send a success page back to the phone
    String htmlResponse = "<h2>Configuration Saved!</h2>";
    htmlResponse += "<p>Network: " + new_ssid + "</p>";
    htmlResponse += "<p>IP updated to: " + new_ip + "</p>";
    htmlResponse += "<p>Time updated to: " + new_time + "</p>";
    htmlResponse += "<br><a href='/'>Return to Dashboard</a>";
    
    server.send(200, "text/html", htmlResponse);
  });

  server.begin();
  Serial.println("Captive Portal Started. Connect to 'Smart Meter'");
}

void handle_portal() {
  dnsServer.processNextRequest();
  server.handleClient();
}
```

## File: CaptivePortal.h
```c
#pragma once

#include <Arduino.h>

void setup_portal();
void handle_portal();
void update_network_config(String new_ssid, String new_pass, String new_ip);
```

## File: DisplayData.h
```c
#pragma once
#include <Arduino.h>

struct SystemState {
    String IP;
    bool isWifiConnected;
    bool isServerOnline; // NEW: Track server health
    String totalPowerUsed;
    unsigned long offlineDownTime;
};
```

## File: DisplayManager.cpp
```cpp
#include "DisplayManager.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int LCD_SDA_PIN = 8;
const int LCD_SCL_PIN = 9;
const int BTN_PIN = 4;

DISPLAY_STATES lcd_state = CONNECTING_TO_WIFI;

String text_top;
String text_bottom; 

bool is_btn_held = false;

void setup_lcd(){
  pinMode(BTN_PIN, OUTPUT);
  Wire.begin(LCD_SDA_PIN, LCD_SCL_PIN);

  lcd.init();
  lcd.backlight();
}

void update_lcd(SystemState systemState){
  if (digitalRead(BTN_PIN) == HIGH){
    if (!is_btn_held) {
      lcd_state = static_cast<DISPLAY_STATES>((lcd_state + 1) % COUNT);
      is_btn_held = true;
    }
  } else {
    is_btn_held = false;
  }

    switch (lcd_state) {
    case CONNECTING_TO_WIFI:
        if (!systemState.isWifiConnected) {
          // No WiFi = definitely no server
          lcd_print_text("WiFi: Connecting", "Server: Offline "); 
        } else {
          // WiFi is connected! Show the IP on top.
          String topText = systemState.IP;
          
          // Check server status for the bottom row
          String bottomText = systemState.isServerOnline ? "Server: Online " : "Server: Offline ";
          
          lcd_print_text(topText, bottomText);
        }
        break;
    case POWER_USAGE:
      lcd_print_text("POWER USED: ",  systemState.totalPowerUsed);
      break;
    case OFFLINE_DOWN_TIME:
      lcd_print_text("BEEN OFFLINE FOR", get_time_info_from_ms(systemState.offlineDownTime));
  }
}

String get_time_info_from_ms(unsigned long ms_passed){
  char timeString[20]; // Increased buffer size for safety

  // Calculate total units
  unsigned long total_secs = ms_passed / 1000;
  
  // Use modulo (%) to get the remaining parts
  short secs  = total_secs % 60;
  short mins  = (total_secs / 60) % 60;
  short hours = (total_secs / 3600) % 24;
  short days  = total_secs / 86400;

  // Combine into a single format string
  sprintf(timeString, "%02dd %02dh %02dm %02ds", days, hours, mins, secs);

  return String(timeString);
}


void lcd_print_text(const String &text_top, const String &text_bottom){
  const int LCD_COLS = 16; // Change to 20 if using a 20x4 display

  // Process top line
  String padded_top = text_top;
  while(padded_top.length() < LCD_COLS) {
    padded_top += " ";
  }
  lcd.setCursor(0, 0);
  lcd.print(padded_top);

  // Process bottom line
  String padded_bottom = text_bottom;
  while(padded_bottom.length() < LCD_COLS) {
    padded_bottom += " ";
  }
  lcd.setCursor(0, 1);
  lcd.print(padded_bottom);
}
```

## File: DisplayManager.h
```c
#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "DisplayData.h"


enum DISPLAY_STATES {CONNECTING_TO_WIFI, POWER_USAGE, OFFLINE_DOWN_TIME, COUNT};

void setup_lcd();
void update_lcd(SystemState systemState);
void lcd_print_text(const String &text_top, const String &text_bottom);
String get_time_info_from_ms(unsigned long ms_passed);
```

## File: Final Year Project.cpp
```cpp
#include <Arduino.h>

#include "NetworkingModule.h"
#include "MeterLogic.h"
#include "StorageManager.h"
#include "DisplayManager.h"
#include "DisplayData.h"
#include "RTCManager.h" 
#include "CaptivePortal.h" // 1. Include the new module

SystemState displayState = {
  .IP="", 
  .isWifiConnected=false, 
  .isServerOnline=false,
  .totalPowerUsed="", 
  .offlineDownTime=0ul
};

void setup() {
  setup_lcd();
  setup_network();
  setup_meter();
  setup_storage();
  setup_rtc(); 
  
  setup_portal(); // 2. Spin up the Access Point
}

void update_display_data(){
  displayState.isWifiConnected = WiFi.status() == WL_CONNECTED;
  displayState.IP = WiFi.localIP().toString();
  displayState.isServerOnline = get_server_status(); 
  displayState.totalPowerUsed = String(get_load_value() * 25 / 10000.0) + " W";
  displayState.offlineDownTime = get_time_offline();
}

void loop() {
  handle_network(); 
  update_storage();
  
  handle_portal(); // 3. Listen for connecting phones and button clicks

  if (packet_failed_to_send()) {
    log_data_locally(generate_packet(true)); 
  }

  update_load_consumed(get_load_value());
  update_display_data();
  update_lcd(displayState);
}
```

## File: MeterLogic.cpp
```cpp
#include "MeterLogic.h"

const int POTENTIOMETER_PIN = 17;
const int MAX_VALUE = 32;
const int DECIMAL_PLACE = 1;

int load_consumed;

void setup_meter(){
  setup_load();
}


void setup_load() {
  pinMode(POTENTIOMETER_PIN, INPUT);
}


float get_load_value(){
  int sensorValue = analogRead(POTENTIOMETER_PIN);
  float factor = (sensorValue / 4096.0);
  return factor;
}
```

## File: MeterLogic.h
```c
#pragma once

#include <Arduino.h>

void setup_meter();
void setup_load();

float get_load_value();
```

## File: NetworkingModule.cpp
```cpp
#include "NetworkingModule.h"
#include "DisplayManager.h"
#include "RTCManager.h" 
#include "StorageManager.h" // NEW: Let networking access the storage

JsonDocument in_packet_doc;

// TIME
unsigned long current_time;
int max_wait_time = 5000; // 5s
const float PACKET_SEND_RATE = 5; // N Per Sec 
long LAST_PACKET_SENT_TIME = millis();
// NEW: Backlog Timing Variables
unsigned long LAST_BACKLOG_TIME = 0;
const float BACKLOG_SEND_RATE = 2.0; // 2 Per Sec

// NEW: Server Health State
bool is_server_online = false; 


STATES state = IDLE;

// NETWORK
WiFiUDP udp;
String network_ssid = "realme Note 50";
String network_pass = "12345678";

const int port = 7556;
IPAddress clientAddress(10, 186, 73, 158); 

bool did_data_fail_to_send = false;

// DATA FOR TRANSFER
const int ID = 1;
float pot_factor;
char PUF_KEY[] = "10111011101";

void setup_network() {
  Serial.begin(115200);


  // Handle WIFI Connection
  // Inside setup_network(), change to this:
  WiFi.begin(network_ssid.c_str(), network_pass.c_str());
 // Begin Attempt to connect to WIFI
  udp.begin(port); // Allow Packet Transfer
}

bool can_send_packet() {
  return (millis() - LAST_PACKET_SENT_TIME) >= (1000.0 / PACKET_SEND_RATE);
} 

void handle_network() {
  // ==========================================
  // 1. LIVE DATA HANDLING (Your existing code)
  // ==========================================
  if (state == IDLE) {
    if (can_send_packet()) {
      udp.beginPacket(clientAddress, port);
      serializeJson(generate_packet(), udp); 
      udp.endPacket();
      
      Serial.println("Sent Live Packet");
      state = WAITING_FOR_SERVER;
      current_time = millis(); 
      LAST_PACKET_SENT_TIME = current_time;
    } 
  }
    else if (state == WAITING_FOR_SERVER) {
    // Timeout Check
    if (get_ms_passed() > max_wait_time) {
      state = IDLE; 
      Serial.println("Error: Server took too long to respond."); 
      did_data_fail_to_send = true;
      
      // NEW: Server is down! Close the gate.
      is_server_online = false; 
      return; 
    } 
    
    if (udp.parsePacket()) { 
      DeserializationError error = deserializeJson(in_packet_doc, udp);
      if (error || in_packet_doc["type"] != "CONFIRM") {
        state = IDLE;
        return;
      }
      Serial.println("Received valid 'CONFIRM' from server."); 
      state = IDLE; 
      did_data_fail_to_send = false;
      
      // NEW: Server is alive! Open the gate.
      is_server_online = true; 
    }
  }


  // ==========================================
  // 2. ASYNCHRONOUS BACKLOG SYNC
  // ==========================================
  
  // NEW: Only run if WiFi is connected, a backlog exists, AND the server is confirmed online!
  if (WiFi.status() == WL_CONNECTED && has_backlog() && is_server_online) {
    
    if (millis() - LAST_BACKLOG_TIME >= (1000.0 / BACKLOG_SEND_RATE)) {
      String offline_packet = read_next_backlog_packet();
      
      if (offline_packet.length() > 0) {
        udp.beginPacket(clientAddress, port);
        udp.print(offline_packet); // Send the raw string
        udp.endPacket();
        
        LAST_BACKLOG_TIME = millis();
        Serial.println("Sent Backlog Packet");
      }
    }
  }

}

unsigned long get_ms_passed() { // This increases the max value to 2^32 - 1ms (about 48 Days of inactivity before it stops counting)
  return millis() - current_time;
}

STATES get_network_state() {
  return state;
}

void update_load_consumed(float load){
  pot_factor = load;
}

bool packet_failed_to_send() {
  // If a failure was flagged...
  if (did_data_fail_to_send) {
    // Reset the flag immediately so we don't spam the flash memory!
    did_data_fail_to_send = false; 
    return true;
  }
  return false;
}


JsonDocument generate_packet(bool is_backlog){
  JsonDocument packet;

  packet["type"] = "METER_DATA";
  // The server can use this to route the data
  packet["state"] = is_backlog ? "OLD" : "NEW"; 
  // Crucial: The server needs to know when this OLD data was recorded
  packet["timestamp"] = get_current_timestamp(); 
  
  packet["key"] = PUF_KEY;
  packet["voltage"] = pot_factor * 5.0 ; 
  packet["current"] = 5.0 /  10000.0; 
  packet["id"] = ID;

  return packet;
}


bool get_server_status() {
  return is_server_online;
}

void update_network_config(String new_ssid, String new_pass, String new_ip) {
  if (new_ssid.length() > 0) network_ssid = new_ssid;
  if (new_pass.length() > 0) network_pass = new_pass;
  
  // The IPAddress object has a built-in string parser!
  if (new_ip.length() > 0) clientAddress.fromString(new_ip); 

  Serial.println("Reconnecting WiFi with new credentials...");
  WiFi.disconnect();
  WiFi.begin(network_ssid.c_str(), network_pass.c_str());
}
```

## File: NetworkingModule.h
```c
#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>

enum STATES {IDLE, WAITING_FOR_SERVER};

void setup_network();
void handle_network();
unsigned long get_ms_passed();

// Change the signature to accept the flag with a default value
JsonDocument generate_packet(bool is_backlog = false);


bool packet_failed_to_send();
bool get_server_status();

void update_load_consumed(float load);

STATES get_network_state();
```

## File: RTCManager.cpp
```cpp
#include "RTCManager.h"

// CLOCK MODULE TERMINAL PINS
const int CLK_PIN = 5;
const int DATA_PIN = 7;
const int RESET_PIN = 6;

// Initialize the 3-wire bus
ThreeWire myWire(DATA_PIN, CLK_PIN, RESET_PIN);

// Pass the bus to the RTC object
RtcDS1302<ThreeWire> Rtc(myWire);

void setup_rtc() {
  Rtc.Begin();

  // If the RTC lost power (no battery), its internal state will be halted
  if (!Rtc.GetIsRunning()) {
    Serial.println("RTC was halted, starting it now");
    Rtc.SetIsRunning(true);
  }

  // Disable write protection so we can update the time if needed
  if (Rtc.GetIsWriteProtected()) {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }

  // Check if the time is valid. If not (e.g., first boot with no battery), set a default
  if (!Rtc.IsDateTimeValid()) {
    Serial.println("RTC lost confidence in the DateTime! Setting default...");
    // Format: Year, Month, Day, Hour, Minute, Second
    RtcDateTime compiled = RtcDateTime(2026, 8, 10, 12, 0, 0); 
    Rtc.SetDateTime(compiled);
  }
}

String get_current_timestamp() {
  if (!Rtc.IsDateTimeValid()) {
    return "TIME_ERROR";
  }

  RtcDateTime now = Rtc.GetDateTime();
  char datestring[20];
  
  // Format: YYYY-MM-DD HH:MM:SS
  snprintf_P(datestring, 
             sizeof(datestring),
             PSTR("%04u-%02u-%02u %02u:%02u:%02u"),
             now.Year(),
             now.Month(),
             now.Day(),
             now.Hour(),
             now.Minute(),
             now.Second() );
             
  return String(datestring);
}

void update_rtc_time(String datetime) {
  // Check if it matches the expected "YYYY-MM-DDTHH:MM" length
  if (datetime.length() >= 16) {
    uint16_t year = datetime.substring(0, 4).toInt();
    uint8_t month = datetime.substring(5, 7).toInt();
    uint8_t day = datetime.substring(8, 10).toInt();
    uint8_t hour = datetime.substring(11, 13).toInt();
    uint8_t minute = datetime.substring(14, 16).toInt();

    // Set seconds to 0 since the HTML form doesn't provide them
    RtcDateTime new_time = RtcDateTime(year, month, day, hour, minute, 0);
    Rtc.SetDateTime(new_time);
    
    Serial.println("Hardware Clock Updated!");
  }
}
```

## File: RTCManager.h
```c
#pragma once

#include <Arduino.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>

void setup_rtc();
String get_current_timestamp();
void update_rtc_time(String datetime);
```

## File: StorageManager.cpp
```cpp
#include "StorageManager.h"

unsigned long last_online_time = 0;

// Global file handle and position tracker
File sync_file;
size_t last_file_position = 0;

// NEW: RAM flag to prevent Flash polling spam
bool _backlog_exists = false; 

void setup_storage() {
  if (LittleFS.begin(false)) {
    Serial.println("LittleFS Mount Failed");
    return;
  }
  Serial.println("LittleFS Mounted Successfully");
  
  // Only check Flash memory ONCE on boot
  _backlog_exists = LittleFS.exists("/offline_data.txt"); 
}


bool has_backlog() {
  return _backlog_exists; // Instant RAM check, no VFS errors
}


String read_next_backlog_packet() {
  if (!sync_file) {
    sync_file = LittleFS.open("/offline_data.txt", FILE_READ);
    if (!sync_file) return "";
    sync_file.seek(last_file_position);
  }

  if (sync_file.available()) {
    String packet = sync_file.readStringUntil('\n');
    last_file_position = sync_file.position();
    
    if (!sync_file.available()) {
      sync_file.close();
      LittleFS.remove("/offline_data.txt");
      last_file_position = 0; 
      
      // NEW: Tell the system the backlog is gone
      _backlog_exists = false; 
      
      Serial.println("Backlog fully synced and cleared.");
    }
    return packet;
  }
  
  sync_file.close();
  return "";
}



void update_storage() {
  if (WiFi.status() == WL_CONNECTED) {
    last_online_time = millis();
  }
}

unsigned long get_time_offline() {
  return millis() - last_online_time;
}

void log_data_locally(const JsonDocument& json_packet){
  File log_file = LittleFS.open("/offline_data.txt", FILE_APPEND);
  
  if (!log_file) {
    Serial.println("Error: Failed to open LittleFS for appending.");
    return;
  }

  serializeJson(json_packet, log_file);
  log_file.println(); 
  log_file.close();
  
  // NEW: Tell the system a backlog now exists
  _backlog_exists = true; 
  
  Serial.println("Packet written directly to Flash.");
}
```

## File: StorageManager.h
```c
#pragma once

#include <Arduino.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "NetworkingModule.h"

void setup_storage();
void update_storage();
unsigned long get_time_offline();
bool has_backlog();
String read_next_backlog_packet();


// Replaces the buffer system completely
void log_data_locally(const JsonDocument& json_packet);
```
````

## File: src/RTCManager.cpp
````cpp
#include "RTCManager.h"

// CLOCK MODULE TERMINAL PINS
const int CLK_PIN = 5;
const int DATA_PIN = 7;
const int RESET_PIN = 6;

// Initialize the 3-wire bus
ThreeWire myWire(DATA_PIN, CLK_PIN, RESET_PIN);

// Pass the bus to the RTC object
RtcDS1302<ThreeWire> Rtc(myWire);

void setup_rtc() {
  Rtc.Begin();

  // If the RTC lost power (no battery), its internal state will be halted
  if (!Rtc.GetIsRunning()) {
    Serial.println("RTC was halted, starting it now");
    Rtc.SetIsRunning(true);
  }

  // Disable write protection so we can update the time if needed
  if (Rtc.GetIsWriteProtected()) {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }

  // Check if the time is valid. If not (e.g., first boot with no battery), set a default
  if (!Rtc.IsDateTimeValid()) {
    Serial.println("RTC lost confidence in the DateTime! Setting default...");
    // Format: Year, Month, Day, Hour, Minute, Second
    RtcDateTime compiled = RtcDateTime(2026, 8, 10, 12, 0, 0); 
    Rtc.SetDateTime(compiled);
  }
}

String get_current_timestamp() {
  if (!Rtc.IsDateTimeValid()) {
    return "TIME_ERROR";
  }

  RtcDateTime now = Rtc.GetDateTime();
  char datestring[20];
  
  // Format: YYYY-MM-DD HH:MM:SS
  snprintf_P(datestring, 
             sizeof(datestring),
             PSTR("%04u-%02u-%02u %02u:%02u:%02u"),
             now.Year(),
             now.Month(),
             now.Day(),
             now.Hour(),
             now.Minute(),
             now.Second() );
             
  return String(datestring);
}

void update_rtc_time(String datetime) {
  // Check if it matches the expected "YYYY-MM-DDTHH:MM" length
  if (datetime.length() >= 16) {
    uint16_t year = datetime.substring(0, 4).toInt();
    uint8_t month = datetime.substring(5, 7).toInt();
    uint8_t day = datetime.substring(8, 10).toInt();
    uint8_t hour = datetime.substring(11, 13).toInt();
    uint8_t minute = datetime.substring(14, 16).toInt();

    // Set seconds to 0 since the HTML form doesn't provide them
    RtcDateTime new_time = RtcDateTime(year, month, day, hour, minute, 0);
    Rtc.SetDateTime(new_time);
    
    Serial.println("Hardware Clock Updated!");
  }
}
````

## File: src/RTCManager.h
````c
#pragma once

#include <Arduino.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>

void setup_rtc();
String get_current_timestamp();
void update_rtc_time(String datetime);
````

## File: src/StorageManager.cpp
````cpp
#include "StorageManager.h"

unsigned long last_online_time = 0;

// Global file handle and position tracker
File sync_file;
size_t last_file_position = 0;

// NEW: RAM flag to prevent Flash polling spam
bool _backlog_exists = false; 

void setup_storage() {
  if (LittleFS.begin(false)) {
    Serial.println("LittleFS Mount Failed");
    return;
  }
  Serial.println("LittleFS Mounted Successfully");
  
  // Only check Flash memory ONCE on boot
  _backlog_exists = LittleFS.exists("/offline_data.txt"); 
}


bool has_backlog() {
  return _backlog_exists; // Instant RAM check, no VFS errors
}


String read_next_backlog_packet() {
  if (!sync_file) {
    sync_file = LittleFS.open("/offline_data.txt", FILE_READ);
    if (!sync_file) return "";
    sync_file.seek(last_file_position);
  }

  if (sync_file.available()) {
    String packet = sync_file.readStringUntil('\n');
    last_file_position = sync_file.position();
    
    if (!sync_file.available()) {
      sync_file.close();
      LittleFS.remove("/offline_data.txt");
      last_file_position = 0; 
      
      // NEW: Tell the system the backlog is gone
      _backlog_exists = false; 
      
      Serial.println("Backlog fully synced and cleared.");
    }
    return packet;
  }
  
  sync_file.close();
  return "";
}



void update_storage() {
  if (WiFi.status() == WL_CONNECTED) {
    last_online_time = millis();
  }
}

unsigned long get_time_offline() {
  return millis() - last_online_time;
}

void log_data_locally(const JsonDocument& json_packet){
  File log_file = LittleFS.open("/offline_data.txt", FILE_APPEND);
  
  if (!log_file) {
    Serial.println("Error: Failed to open LittleFS for appending.");
    return;
  }

  serializeJson(json_packet, log_file);
  log_file.println(); 
  log_file.close();
  
  // NEW: Tell the system a backlog now exists
  _backlog_exists = true; 
  
  Serial.println("Packet written directly to Flash.");
}
````

## File: src/StorageManager.h
````c
#pragma once

#include <Arduino.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "NetworkingModule.h"

void setup_storage();
void update_storage();
unsigned long get_time_offline();
bool has_backlog();
String read_next_backlog_packet();


// Replaces the buffer system completely
void log_data_locally(const JsonDocument& json_packet);
````

## File: test/README
````
This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html
````

## File: .gitignore
````
.pio
.vscode/.browse.c_cpp.db*
.vscode/c_cpp_properties.json
.vscode/launch.json
.vscode/ipch
````

## File: platformio.ini
````ini
; PlatformIO Project Configuration File
;
;   Build options: build flags, source filter
;   Upload options: custom upload port, speed and extra flags
;   Library options: dependencies, extra library storages
;   Advanced options: extra scripting
;
; Please visit documentation for the other options and examples
; https://docs.platformio.org/page/projectconf.html

[env:esp32-s3-devkitc-1]
platform = espressif32
board = esp32-s3-devkitc-1
framework = arduino
board_build.filesystem = littlefs 
lib_deps = 
    marcoschwartz/LiquidCrystal_I2C@^1.1.4
    bblanchon/ArduinoJson
    makuna/RTC
monitor_speed=115200
````

## File: recovered_meter_data.csv
````
Timestamp,Voltage,Current,Power
2026-08-10 12:50:10,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:50:16,0.010986,0.0005,5.493e-06
2026-08-10 12:50:21,0.014648,0.0005,7.324e-06
2026-08-10 12:50:26,0.014648,0.0005,7.324e-06
2026-08-10 12:50:36,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:50:46,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:51:07,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:51:12,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:51:17,0.012207,0.0005,6.103500000000001e-06
2026-08-10 12:51:22,0.014648,0.0005,7.324e-06
2026-08-10 12:51:27,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:51:32,0.015869,0.0005,7.9345e-06
2026-08-10 12:51:37,0.025635,0.0005,1.28175e-05
2026-08-10 12:51:43,0.025635,0.0005,1.28175e-05
2026-08-10 12:51:48,0.025635,0.0005,1.28175e-05
2026-08-10 12:51:54,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:52:00,0.028076,0.0005,1.4038e-05
2026-08-10 12:52:05,0.023193,0.0005,1.15965e-05
2026-08-10 12:52:10,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:52:15,0.025635,0.0005,1.28175e-05
2026-08-10 12:52:20,0.028076,0.0005,1.4038e-05
2026-08-10 12:52:25,0.023193,0.0005,1.15965e-05
2026-08-10 12:52:30,0.028076,0.0005,1.4038e-05
2026-08-10 12:52:36,0.026855,0.0005,1.34275e-05
2026-08-10 12:52:41,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:52:46,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:52:51,0.028076,0.0005,1.4038e-05
2026-08-10 12:52:56,0.025635,0.0005,1.28175e-05
2026-08-10 12:53:01,0.025635,0.0005,1.28175e-05
2026-08-10 12:53:06,0.026855,0.0005,1.34275e-05
2026-08-10 12:53:11,0.025635,0.0005,1.28175e-05
2026-08-10 12:53:16,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:53:22,0.025635,0.0005,1.28175e-05
2026-08-10 12:53:27,0.026855,0.0005,1.34275e-05
2026-08-10 12:53:32,0.025635,0.0005,1.28175e-05
2026-08-10 12:53:37,0.025635,0.0005,1.28175e-05
2026-08-10 12:53:42,0.028076,0.0005,1.4038e-05
2026-08-10 12:53:47,0.026855,0.0005,1.34275e-05
2026-08-10 12:53:52,0.026855,0.0005,1.34275e-05
2026-08-10 12:53:57,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:03,0.026855,0.0005,1.34275e-05
2026-08-10 12:54:08,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:13,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:54:18,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:23,0.026855,0.0005,1.34275e-05
2026-08-10 12:54:28,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:33,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:38,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:43,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:48,0.026855,0.0005,1.34275e-05
2026-08-10 12:54:54,0.025635,0.0005,1.28175e-05
2026-08-10 12:54:59,0.025635,0.0005,1.28175e-05
2026-08-10 12:55:04,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:55:09,0.025635,0.0005,1.28175e-05
2026-08-10 12:55:14,0.025635,0.0005,1.28175e-05
2026-08-10 12:55:19,0.026855,0.0005,1.34275e-05
2026-08-10 12:55:24,0.028076,0.0005,1.4038e-05
2026-08-10 12:55:29,0.025635,0.0005,1.28175e-05
2026-08-10 12:55:35,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:55:40,0.025635,0.0005,1.28175e-05
2026-08-10 12:55:45,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:55:50,0.025635,0.0005,1.28175e-05
2026-08-10 12:55:55,0.024414,0.0005,1.2207000000000002e-05
2026-08-10 12:56:00,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 12:56:05,0.025635,0.0005,1.28175e-05
2026-08-10 12:56:10,0.026855,0.0005,1.34275e-05
2026-08-10 12:56:15,0.028076,0.0005,1.4038e-05
2026-08-10 12:56:20,0.025635,0.0005,1.28175e-05
2026-08-10 12:56:26,0.025635,0.0005,1.28175e-05
2026-08-10 12:56:31,0.025635,0.0005,1.28175e-05
2026-08-10 12:56:36,0.028076,0.0005,1.4038e-05
2026-08-10 12:56:41,0.029297,0.0005,1.46485e-05
2026-08-10 12:56:46,0.025635,0.0005,1.28175e-05
2026-08-10 12:56:51,0.026855,0.0005,1.34275e-05
2026-08-10 12:56:56,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:01,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:07,0.026855,0.0005,1.34275e-05
2026-08-10 12:57:12,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:17,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:22,0.028076,0.0005,1.4038e-05
2026-08-10 12:57:27,0.026855,0.0005,1.34275e-05
2026-08-10 12:57:32,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:37,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:42,0.025635,0.0005,1.28175e-05
2026-08-10 12:57:47,0.028076,0.0005,1.4038e-05
2026-08-10 12:57:53,0.028076,0.0005,1.4038e-05
2026-08-10 12:57:58,0.028076,0.0005,1.4038e-05
2026-08-10 12:58:03,0.0354,0.0005,1.77e-05
2026-08-10 12:58:08,0.0354,0.0005,1.77e-05
2026-08-10 12:58:13,0.0354,0.0005,1.77e-05
2026-08-10 12:58:18,0.037842,0.0005,1.8921e-05
2026-08-10 12:58:23,0.037842,0.0005,1.8921e-05
2026-08-10 12:58:28,0.037842,0.0005,1.8921e-05
2026-08-10 12:58:33,0.042725,0.0005,2.13625e-05
2026-08-10 12:58:39,0.040283,0.0005,2.01415e-05
2026-08-10 12:58:44,0.040283,0.0005,2.01415e-05
2026-08-10 12:58:49,0.036621,0.0005,1.83105e-05
2026-08-10 12:58:54,0.042725,0.0005,2.13625e-05
2026-08-10 12:58:59,0.040283,0.0005,2.01415e-05
2026-08-10 12:59:04,0.045166,0.0005,2.2583e-05
2026-08-10 12:59:09,0.037842,0.0005,1.8921e-05
2026-08-10 12:59:14,0.043945,0.0005,2.19725e-05
2026-08-10 12:59:19,0.045166,0.0005,2.2583e-05
2026-08-10 12:59:25,0.042725,0.0005,2.13625e-05
2026-08-10 12:59:30,0.043945,0.0005,2.19725e-05
2026-08-10 12:59:45,0.047607,0.0005,2.38035e-05
2026-08-10 12:59:50,0.045166,0.0005,2.2583e-05
2026-08-10 12:59:56,0.042725,0.0005,2.13625e-05
2026-08-10 13:00:01,0.045166,0.0005,2.2583e-05
2026-08-10 13:00:06,0.040283,0.0005,2.01415e-05
2026-08-10 13:00:11,0.040283,0.0005,2.01415e-05
2026-08-10 13:00:16,0.043945,0.0005,2.19725e-05
2026-08-10 13:00:21,0.045166,0.0005,2.2583e-05
2026-08-10 13:00:26,0.040283,0.0005,2.01415e-05
2026-08-10 13:00:31,0.045166,0.0005,2.2583e-05
2026-08-10 13:00:36,0.045166,0.0005,2.2583e-05
2026-08-10 13:00:42,0.045166,0.0005,2.2583e-05
2026-08-10 13:00:47,0.042725,0.0005,2.13625e-05
2026-08-10 13:00:52,0.040283,0.0005,2.01415e-05
2026-08-10 13:00:57,0.042725,0.0005,2.13625e-05
2026-08-10 13:01:02,0.040283,0.0005,2.01415e-05
2026-08-10 13:01:07,0.042725,0.0005,2.13625e-05
2026-08-10 13:01:12,0.042725,0.0005,2.13625e-05
2026-08-10 13:01:17,0.043945,0.0005,2.19725e-05
2026-08-10 13:01:22,0.045166,0.0005,2.2583e-05
2026-08-10 13:01:28,0.037842,0.0005,1.8921e-05
2026-08-10 13:01:33,0.046387,0.0005,2.31935e-05
2026-08-10 13:01:38,0.042725,0.0005,2.13625e-05
2026-08-10 13:01:43,0.042725,0.0005,2.13625e-05
2026-08-10 13:01:48,0.043945,0.0005,2.19725e-05
2026-08-10 13:01:53,0.042725,0.0005,2.13625e-05
2026-08-10 13:01:58,0.040283,0.0005,2.01415e-05
2026-08-10 13:02:03,0.040283,0.0005,2.01415e-05
2026-08-10 13:02:09,0.042725,0.0005,2.13625e-05
2026-08-10 13:02:14,0.045166,0.0005,2.2583e-05
2026-08-10 13:02:19,0.043945,0.0005,2.19725e-05
2026-08-10 13:02:24,0.042725,0.0005,2.13625e-05
2026-08-10 13:02:29,0.045166,0.0005,2.2583e-05
2026-08-10 13:02:34,0.043945,0.0005,2.19725e-05
2026-08-10 13:02:39,0.045166,0.0005,2.2583e-05
2026-08-10 13:02:44,0.043945,0.0005,2.19725e-05
2026-08-10 13:02:49,0.043945,0.0005,2.19725e-05
2026-08-10 13:02:54,0.042725,0.0005,2.13625e-05
2026-08-10 13:03:00,0.045166,0.0005,2.2583e-05
2026-08-10 13:03:05,0.043945,0.0005,2.19725e-05
2026-08-10 13:03:10,0.042725,0.0005,2.13625e-05
2026-08-10 13:03:15,0.045166,0.0005,2.2583e-05
2026-08-10 13:03:20,0.037842,0.0005,1.8921e-05
2026-08-10 13:03:25,0.043945,0.0005,2.19725e-05
2026-08-10 13:03:35,0.042725,0.0005,2.13625e-05
2026-08-10 13:03:41,0.040283,0.0005,2.01415e-05
2026-08-10 13:03:46,0.042725,0.0005,2.13625e-05
2026-08-10 13:03:51,0.043945,0.0005,2.19725e-05
2026-08-10 13:03:56,0.037842,0.0005,1.8921e-05
2026-08-10 13:04:01,0.043945,0.0005,2.19725e-05
2026-08-10 13:04:06,0.042725,0.0005,2.13625e-05
2026-08-10 13:04:11,0.045166,0.0005,2.2583e-05
2026-08-10 13:04:16,0.043945,0.0005,2.19725e-05
2026-08-10 13:04:21,0.045166,0.0005,2.2583e-05
2026-08-10 13:04:26,0.045166,0.0005,2.2583e-05
2026-08-10 13:04:32,0.047607,0.0005,2.38035e-05
2026-08-10 13:04:37,0.042725,0.0005,2.13625e-05
2026-08-10 13:04:42,0.043945,0.0005,2.19725e-05
2026-08-10 13:04:47,0.045166,0.0005,2.2583e-05
2026-08-10 13:04:52,0.042725,0.0005,2.13625e-05
2026-08-10 13:04:57,0.043945,0.0005,2.19725e-05
2026-08-10 13:05:02,0.042725,0.0005,2.13625e-05
2026-08-10 13:05:07,0.042725,0.0005,2.13625e-05
2026-08-10 13:05:13,0.045166,0.0005,2.2583e-05
2026-08-10 13:05:18,0.045166,0.0005,2.2583e-05
2026-08-10 13:05:23,0.042725,0.0005,2.13625e-05
2026-08-10 13:05:28,0.040283,0.0005,2.01415e-05
2026-08-10 13:05:33,0.043945,0.0005,2.19725e-05
2026-08-10 13:05:38,0.042725,0.0005,2.13625e-05
2026-08-10 13:05:43,0.046387,0.0005,2.31935e-05
2026-08-10 13:05:48,0.040283,0.0005,2.01415e-05
2026-08-10 13:05:53,0.057373,0.0005,2.86865e-05
2026-08-10 13:06:20,0.063477,0.0005,3.17385e-05
2026-08-10 13:06:25,0.063477,0.0005,3.17385e-05
2026-08-10 13:06:30,0.057373,0.0005,2.86865e-05
2026-08-10 13:06:35,0.058594,0.0005,2.9297e-05
2026-08-10 13:06:41,0.057373,0.0005,2.86865e-05
2026-08-10 13:06:46,0.061035,0.0005,3.05175e-05
2026-08-10 13:06:51,0.062256,0.0005,3.1128e-05
2026-08-10 13:06:56,0.057373,0.0005,2.86865e-05
2026-08-10 13:07:01,0.062256,0.0005,3.1128e-05
2026-08-10 13:07:06,0.057373,0.0005,2.86865e-05
2026-08-10 13:07:11,0.063477,0.0005,3.17385e-05
2026-08-10 13:07:16,0.062256,0.0005,3.1128e-05
2026-08-10 13:07:21,0.062256,0.0005,3.1128e-05
2026-08-10 13:07:27,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:07:32,0.062256,0.0005,3.1128e-05
2026-08-10 13:07:37,0.063477,0.0005,3.17385e-05
2026-08-10 13:07:42,0.065918,0.0005,3.2959e-05
2026-08-10 13:07:47,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:07:52,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:07:57,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:03,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:08:08,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:13,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:08:18,0.063477,0.0005,3.17385e-05
2026-08-10 13:08:23,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:28,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:33,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:08:38,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:44,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:08:49,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:54,0.062256,0.0005,3.1128e-05
2026-08-10 13:08:59,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:09:04,0.062256,0.0005,3.1128e-05
2026-08-10 13:09:09,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:09:14,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:09:20,0.064697,0.0005,3.2348500000000004e-05
2026-08-10 13:09:25,0.062256,0.0005,3.1128e-05
2026-08-10 13:09:30,0.058594,0.0005,2.9297e-05
2026-08-10 13:09:35,0.062256,0.0005,3.1128e-05
2026-08-10 13:09:40,0.057373,0.0005,2.86865e-05
2026-08-10 13:09:45,0.062256,0.0005,3.1128e-05
2026-08-10 13:09:50,0.057373,0.0005,2.86865e-05
2026-08-10 13:09:56,0.058594,0.0005,2.9297e-05
2026-08-10 13:10:01,0.059814,0.0005,2.9907e-05
2026-08-10 13:10:06,0.062256,0.0005,3.1128e-05
2026-08-10 13:10:11,0.058594,0.0005,2.9297e-05
2026-08-10 13:10:16,0.062256,0.0005,3.1128e-05
2026-08-10 13:10:21,0.063477,0.0005,3.17385e-05
2026-08-10 13:10:26,0.061035,0.0005,3.05175e-05
2026-08-10 13:10:32,0.063477,0.0005,3.17385e-05
2026-08-10 13:10:37,0.063477,0.0005,3.17385e-05
2026-08-10 13:10:42,0.058594,0.0005,2.9297e-05
2026-08-10 13:10:47,0.058594,0.0005,2.9297e-05
2026-08-10 13:10:52,0.063477,0.0005,3.17385e-05
2026-08-10 13:10:57,0.019531,0.0005,9.7655e-06
2026-08-10 13:11:05,0.023193,0.0005,1.15965e-05
2026-08-10 13:11:10,0.021973,0.0005,1.09865e-05
2026-08-10 13:11:16,0.015869,0.0005,7.9345e-06
2026-08-10 13:11:21,0.020752,0.0005,1.0376e-05
2026-08-10 13:11:26,0.023193,0.0005,1.15965e-05
2026-08-10 13:11:31,0.020752,0.0005,1.0376e-05
2026-08-10 13:11:36,0.014648,0.0005,7.324e-06
2026-08-10 13:11:41,0.014648,0.0005,7.324e-06
2026-08-10 13:11:46,0.01709,0.0005,8.545e-06
2026-08-10 13:11:52,0.020752,0.0005,1.0376e-05
2026-08-10 13:11:57,0.015869,0.0005,7.9345e-06
2026-08-10 13:12:02,0.015869,0.0005,7.9345e-06
2026-08-10 13:12:07,0.015869,0.0005,7.9345e-06
2026-08-10 13:12:12,0.020752,0.0005,1.0376e-05
2026-08-10 13:12:17,0.014648,0.0005,7.324e-06
2026-08-10 13:12:23,0.013428,0.0005,6.7140000000000004e-06
2026-08-10 13:12:28,0.015869,0.0005,7.9345e-06
2026-08-10 13:12:33,0.015869,0.0005,7.9345e-06
2026-08-10 13:12:38,0.014648,0.0005,7.324e-06
2026-08-12 20:20:02,0.015869,0.0005,7.9345e-06
2026-08-12 20:20:07,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:20:12,0.015869,0.0005,7.9345e-06
2026-08-12 20:20:17,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:20:22,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:20:28,0.015869,0.0005,7.9345e-06
2026-08-12 20:20:33,0.015869,0.0005,7.9345e-06
2026-08-12 20:20:38,0.020752,0.0005,1.0376e-05
2026-08-12 20:20:43,0.014648,0.0005,7.324e-06
2026-08-12 20:20:48,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:20:53,0.015869,0.0005,7.9345e-06
2026-08-12 20:20:59,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:21:04,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:21:09,0.015869,0.0005,7.9345e-06
2026-08-12 20:21:33,0.014648,0.0005,7.324e-06
2026-08-12 20:21:38,0.014648,0.0005,7.324e-06
2026-08-12 20:21:43,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:21:48,0.020752,0.0005,1.0376e-05
2026-08-12 20:21:53,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:21:58,0.020752,0.0005,1.0376e-05
2026-08-12 20:22:03,0.014648,0.0005,7.324e-06
2026-08-12 20:22:08,0.004883,0.0005,2.4415000000000003e-06
2026-08-12 20:22:14,0.01709,0.0005,8.545e-06
2026-08-12 20:22:19,0.019531,0.0005,9.7655e-06
2026-08-12 20:22:24,0.020752,0.0005,1.0376e-05
2026-08-12 20:22:29,0.003662,0.0005,1.831e-06
2026-08-12 20:22:34,0.006104,0.0005,3.052e-06
2026-08-12 20:22:39,0.004883,0.0005,2.4415000000000003e-06
2026-08-12 20:22:45,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:22:50,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:22:55,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:23:00,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:23:05,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:10,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:15,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:20,0.018311,0.0005,9.1555e-06
2026-08-12 20:23:26,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:31,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:23:36,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:41,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:46,0.015869,0.0005,7.9345e-06
2026-08-12 20:23:51,0.014648,0.0005,7.324e-06
2026-08-12 20:23:57,0.014648,0.0005,7.324e-06
2026-08-12 20:24:02,0.014648,0.0005,7.324e-06
2026-08-12 20:24:07,0.014648,0.0005,7.324e-06
2026-08-12 20:24:12,0.014648,0.0005,7.324e-06
2026-08-12 20:24:17,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:24:22,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:24:27,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:24:32,0.014648,0.0005,7.324e-06
2026-08-12 20:24:38,0.014648,0.0005,7.324e-06
2026-08-12 20:24:43,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:24:48,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:24:53,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:24:58,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:25:03,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:25:08,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:25:14,0.014648,0.0005,7.324e-06
2026-08-12 20:25:19,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:25:24,0.014648,0.0005,7.324e-06
2026-08-12 20:25:29,0.014648,0.0005,7.324e-06
2026-08-12 20:25:34,0.015869,0.0005,7.9345e-06
2026-08-12 20:25:39,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:25:44,0.014648,0.0005,7.324e-06
2026-08-12 20:25:50,0.015869,0.0005,7.9345e-06
2026-08-12 20:25:55,0.014648,0.0005,7.324e-06
2026-08-12 20:26:00,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:26:05,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:26:10,0.014648,0.0005,7.324e-06
2026-08-12 20:26:15,0.015869,0.0005,7.9345e-06
2026-08-12 20:26:20,0.014648,0.0005,7.324e-06
2026-08-12 20:26:26,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:26:31,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:26:36,0.015869,0.0005,7.9345e-06
2026-08-12 20:26:41,0.014648,0.0005,7.324e-06
2026-08-12 20:26:46,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:26:51,0.015869,0.0005,7.9345e-06
2026-08-12 20:26:57,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:27:02,0.014648,0.0005,7.324e-06
2026-08-12 20:27:07,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:27:12,0.015869,0.0005,7.9345e-06
2026-08-12 20:27:17,0.015869,0.0005,7.9345e-06
2026-08-12 20:27:22,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:27:27,0.002441,0.0005,1.2205e-06
2026-08-12 20:27:32,0.014648,0.0005,7.324e-06
2026-08-12 20:27:38,0.015869,0.0005,7.9345e-06
2026-08-12 20:27:43,0.014648,0.0005,7.324e-06
2026-08-12 20:27:48,0.015869,0.0005,7.9345e-06
2026-08-12 20:27:53,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:27:58,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:28:03,0.014648,0.0005,7.324e-06
2026-08-12 20:28:08,0.015869,0.0005,7.9345e-06
2026-08-12 20:28:14,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:28:19,0.015869,0.0005,7.9345e-06
2026-08-12 20:28:24,0.015869,0.0005,7.9345e-06
2026-08-12 20:28:29,0.015869,0.0005,7.9345e-06
2026-08-12 20:28:34,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:28:39,0.015869,0.0005,7.9345e-06
2026-08-12 20:28:44,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:28:55,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:29:00,0.014648,0.0005,7.324e-06
2026-08-12 20:29:05,0.014648,0.0005,7.324e-06
2026-08-12 20:29:10,0.015869,0.0005,7.9345e-06
2026-08-12 20:29:15,0.014648,0.0005,7.324e-06
2026-08-12 20:29:21,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:29:26,0.015869,0.0005,7.9345e-06
2026-08-12 20:29:31,0.015869,0.0005,7.9345e-06
2026-08-12 20:29:36,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:29:41,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:29:46,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:29:51,0.014648,0.0005,7.324e-06
2026-08-12 20:29:56,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:30:02,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:30:07,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:30:12,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:30:17,0.015869,0.0005,7.9345e-06
2026-08-12 20:30:22,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:30:27,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:30:32,0.014648,0.0005,7.324e-06
2026-08-12 20:30:37,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:30:43,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:30:48,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:30:53,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:30:58,0.012207,0.0005,6.103500000000001e-06
2026-08-12 20:31:03,0.013428,0.0005,6.7140000000000004e-06
2026-08-12 20:31:08,0.015869,0.0005,7.9345e-06
2026-08-12 20:31:14,0.020752,0.0005,1.0376e-05
2026-08-12 20:31:19,0.023193,0.0005,1.15965e-05
2026-08-12 20:31:24,0.020752,0.0005,1.0376e-05
2026-08-12 20:31:29,0.021973,0.0005,1.09865e-05
2026-08-12 20:31:34,0.023193,0.0005,1.15965e-05
2026-08-12 20:31:39,0.020752,0.0005,1.0376e-05
2026-08-12 20:31:44,0.021973,0.0005,1.09865e-05
2026-08-12 20:31:49,0.020752,0.0005,1.0376e-05
2026-08-12 20:31:55,0.015869,0.0005,7.9345e-06
2026-08-12 20:32:00,0.023193,0.0005,1.15965e-05
2026-08-12 20:32:05,0.021973,0.0005,1.09865e-05
2026-08-12 20:32:10,0.023193,0.0005,1.15965e-05
2026-08-12 20:32:15,0.021973,0.0005,1.09865e-05
2026-08-12 20:32:20,0.020752,0.0005,1.0376e-05
2026-08-12 20:32:26,0.015869,0.0005,7.9345e-06
2026-08-12 20:32:31,0.015869,0.0005,7.9345e-06
2026-08-12 20:32:36,0.023193,0.0005,1.15965e-05
2026-08-12 20:32:41,0.020752,0.0005,1.0376e-05
2026-08-12 20:32:46,0.020752,0.0005,1.0376e-05
2026-08-12 20:32:51,0.023193,0.0005,1.15965e-05
2026-08-12 20:32:56,0.015869,0.0005,7.9345e-06
2026-08-12 20:33:01,0.025635,0.0005,1.28175e-05
2026-08-12 20:33:07,0.019531,0.0005,9.7655e-06
2026-08-12 20:33:12,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:33:17,0.028076,0.0005,1.4038e-05
2026-08-12 20:33:22,0.019531,0.0005,9.7655e-06
2026-08-12 20:33:27,0.023193,0.0005,1.15965e-05
2026-08-12 20:33:32,0.023193,0.0005,1.15965e-05
2026-08-12 20:33:38,0.020752,0.0005,1.0376e-05
2026-08-12 20:33:43,0.020752,0.0005,1.0376e-05
2026-08-12 20:33:48,0.023193,0.0005,1.15965e-05
2026-08-12 20:33:53,0.023193,0.0005,1.15965e-05
2026-08-12 20:33:58,0.020752,0.0005,1.0376e-05
2026-08-12 20:34:03,0.020752,0.0005,1.0376e-05
2026-08-12 20:34:08,0.015869,0.0005,7.9345e-06
2026-08-12 20:34:13,0.020752,0.0005,1.0376e-05
2026-08-12 20:34:19,0.020752,0.0005,1.0376e-05
2026-08-12 20:34:24,0.021973,0.0005,1.09865e-05
2026-08-12 20:34:29,0.023193,0.0005,1.15965e-05
2026-08-12 20:34:34,0.023193,0.0005,1.15965e-05
2026-08-12 20:34:39,0.021973,0.0005,1.09865e-05
2026-08-12 20:34:44,0.020752,0.0005,1.0376e-05
2026-08-12 20:34:50,0.020752,0.0005,1.0376e-05
2026-08-12 20:34:55,0.015869,0.0005,7.9345e-06
2026-08-12 20:35:00,0.021973,0.0005,1.09865e-05
2026-08-12 20:35:05,0.018311,0.0005,9.1555e-06
2026-08-12 20:35:10,0.021973,0.0005,1.09865e-05
2026-08-12 20:35:15,0.020752,0.0005,1.0376e-05
2026-08-12 20:35:20,0.023193,0.0005,1.15965e-05
2026-08-12 20:35:26,0.020752,0.0005,1.0376e-05
2026-08-12 20:35:31,0.020752,0.0005,1.0376e-05
2026-08-12 20:35:36,0.014648,0.0005,7.324e-06
2026-08-12 20:35:41,0.023193,0.0005,1.15965e-05
2026-08-12 20:35:46,0.023193,0.0005,1.15965e-05
2026-08-12 20:35:51,0.020752,0.0005,1.0376e-05
2026-08-12 20:35:57,0.025635,0.0005,1.28175e-05
2026-08-12 20:36:02,0.021973,0.0005,1.09865e-05
2026-08-12 20:36:07,0.021973,0.0005,1.09865e-05
2026-08-12 20:36:12,0.021973,0.0005,1.09865e-05
2026-08-12 20:36:17,0.025635,0.0005,1.28175e-05
2026-08-12 20:36:22,0.020752,0.0005,1.0376e-05
2026-08-12 20:36:28,0.020752,0.0005,1.0376e-05
2026-08-12 20:36:33,0.023193,0.0005,1.15965e-05
2026-08-12 20:36:38,0.020752,0.0005,1.0376e-05
2026-08-12 20:36:43,0.020752,0.0005,1.0376e-05
2026-08-12 20:36:48,0.023193,0.0005,1.15965e-05
2026-08-12 20:36:53,0.020752,0.0005,1.0376e-05
2026-08-12 20:36:59,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:37:04,0.020752,0.0005,1.0376e-05
2026-08-12 20:37:09,0.015869,0.0005,7.9345e-06
2026-08-12 20:37:14,0.020752,0.0005,1.0376e-05
2026-08-12 20:37:19,0.023193,0.0005,1.15965e-05
2026-08-12 20:37:25,0.023193,0.0005,1.15965e-05
2026-08-12 20:37:30,0.023193,0.0005,1.15965e-05
2026-08-12 20:37:35,0.023193,0.0005,1.15965e-05
2026-08-12 20:37:40,0.023193,0.0005,1.15965e-05
2026-08-12 20:37:45,0.020752,0.0005,1.0376e-05
2026-08-12 20:37:50,0.023193,0.0005,1.15965e-05
2026-08-12 20:37:56,0.021973,0.0005,1.09865e-05
2026-08-12 20:38:01,0.021973,0.0005,1.09865e-05
2026-08-12 20:38:06,0.020752,0.0005,1.0376e-05
2026-08-12 20:38:11,0.021973,0.0005,1.09865e-05
2026-08-12 20:38:16,0.023193,0.0005,1.15965e-05
2026-08-12 20:38:21,0.023193,0.0005,1.15965e-05
2026-08-12 20:38:27,0.021973,0.0005,1.09865e-05
2026-08-12 20:38:32,0.023193,0.0005,1.15965e-05
2026-08-12 20:38:37,0.020752,0.0005,1.0376e-05
2026-08-12 20:38:42,0.023193,0.0005,1.15965e-05
2026-08-12 20:38:47,0.023193,0.0005,1.15965e-05
2026-08-12 20:38:52,0.021973,0.0005,1.09865e-05
2026-08-12 20:38:58,0.023193,0.0005,1.15965e-05
2026-08-12 20:39:03,0.020752,0.0005,1.0376e-05
2026-08-12 20:39:08,0.021973,0.0005,1.09865e-05
2026-08-12 20:39:13,0.023193,0.0005,1.15965e-05
2026-08-12 20:39:18,0.020752,0.0005,1.0376e-05
2026-08-12 20:39:24,0.019531,0.0005,9.7655e-06
2026-08-12 20:39:29,0.020752,0.0005,1.0376e-05
2026-08-12 20:39:34,0.020752,0.0005,1.0376e-05
2026-08-12 20:39:39,0.023193,0.0005,1.15965e-05
2026-08-12 20:39:44,0.021973,0.0005,1.09865e-05
2026-08-12 20:39:49,0.023193,0.0005,1.15965e-05
2026-08-12 20:39:55,0.008545,0.0005,4.2725e-06
2026-08-12 20:40:00,0.021973,0.0005,1.09865e-05
2026-08-12 20:40:05,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:40:10,0.023193,0.0005,1.15965e-05
2026-08-12 20:40:15,0.021973,0.0005,1.09865e-05
2026-08-12 20:40:21,0.023193,0.0005,1.15965e-05
2026-08-12 20:40:26,0.025635,0.0005,1.28175e-05
2026-08-12 20:40:31,0.025635,0.0005,1.28175e-05
2026-08-12 20:40:36,0.025635,0.0005,1.28175e-05
2026-08-12 20:40:41,0.028076,0.0005,1.4038e-05
2026-08-12 20:40:46,0.028076,0.0005,1.4038e-05
2026-08-12 20:40:52,0.025635,0.0005,1.28175e-05
2026-08-12 20:40:57,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:41:02,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:07,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:12,0.023193,0.0005,1.15965e-05
2026-08-12 20:41:17,0.023193,0.0005,1.15965e-05
2026-08-12 20:41:22,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:41:28,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:33,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:38,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:41:43,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:48,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:54,0.025635,0.0005,1.28175e-05
2026-08-12 20:41:59,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:42:04,0.025635,0.0005,1.28175e-05
2026-08-12 20:42:09,0.026855,0.0005,1.34275e-05
2026-08-12 20:42:14,0.026855,0.0005,1.34275e-05
2026-08-12 20:42:19,0.026855,0.0005,1.34275e-05
2026-08-12 20:42:25,0.023193,0.0005,1.15965e-05
2026-08-12 20:42:30,0.025635,0.0005,1.28175e-05
2026-08-12 20:42:35,0.026855,0.0005,1.34275e-05
2026-08-12 20:42:40,0.025635,0.0005,1.28175e-05
2026-08-12 20:42:45,0.025635,0.0005,1.28175e-05
2026-08-12 20:42:51,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:42:56,0.025635,0.0005,1.28175e-05
2026-08-12 20:43:01,0.008545,0.0005,4.2725e-06
2026-08-12 20:43:06,0.025635,0.0005,1.28175e-05
2026-08-12 20:43:11,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:43:16,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:43:22,0.025635,0.0005,1.28175e-05
2026-08-12 20:43:27,0.025635,0.0005,1.28175e-05
2026-08-12 20:43:32,0.023193,0.0005,1.15965e-05
2026-08-12 20:43:37,0.026855,0.0005,1.34275e-05
2026-08-12 20:43:42,0.025635,0.0005,1.28175e-05
2026-08-12 20:43:47,0.025635,0.0005,1.28175e-05
2026-08-12 20:43:53,0.009766,0.0005,4.8830000000000005e-06
2026-08-12 20:43:58,0.026855,0.0005,1.34275e-05
2026-08-12 20:44:03,0.023193,0.0005,1.15965e-05
2026-08-12 20:44:08,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:44:13,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:44:18,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:44:24,0.025635,0.0005,1.28175e-05
2026-08-12 20:44:29,0.025635,0.0005,1.28175e-05
2026-08-12 20:44:34,0.026855,0.0005,1.34275e-05
2026-08-12 20:44:39,0.025635,0.0005,1.28175e-05
2026-08-12 20:44:44,0.025635,0.0005,1.28175e-05
2026-08-12 20:44:50,0.025635,0.0005,1.28175e-05
2026-08-12 20:44:55,0.028076,0.0005,1.4038e-05
2026-08-12 20:45:00,0.023193,0.0005,1.15965e-05
2026-08-12 20:45:05,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:45:10,0.023193,0.0005,1.15965e-05
2026-08-12 20:45:15,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:45:21,0.020752,0.0005,1.0376e-05
2026-08-12 20:45:26,0.023193,0.0005,1.15965e-05
2026-08-12 20:45:31,0.023193,0.0005,1.15965e-05
2026-08-12 20:45:36,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:45:41,0.026855,0.0005,1.34275e-05
2026-08-12 20:45:46,0.023193,0.0005,1.15965e-05
2026-08-12 20:45:52,0.023193,0.0005,1.15965e-05
2026-08-12 20:45:57,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:46:02,0.023193,0.0005,1.15965e-05
2026-08-12 20:46:07,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 20:46:12,0.010986,0.0005,5.493e-06
2026-08-12 20:46:18,0.053711,0.0005,2.68555e-05
2026-08-12 20:46:23,0.05249,0.0005,2.6245e-05
2026-08-12 20:46:28,0.045166,0.0005,2.2583e-05
2026-08-12 20:46:33,0.037842,0.0005,1.8921e-05
2026-08-12 20:46:38,0.037842,0.0005,1.8921e-05
2026-08-12 20:46:43,0.036621,0.0005,1.83105e-05
2026-08-12 20:46:48,0.037842,0.0005,1.8921e-05
2026-08-12 20:46:54,0.0354,0.0005,1.77e-05
2026-08-12 20:46:59,0.0354,0.0005,1.77e-05
2026-08-12 20:47:04,0.037842,0.0005,1.8921e-05
2026-08-12 20:47:09,0.037842,0.0005,1.8921e-05
2026-08-12 20:47:14,0.037842,0.0005,1.8921e-05
2026-08-12 20:47:20,0.037842,0.0005,1.8921e-05
2026-08-12 20:47:25,0.0354,0.0005,1.77e-05
2026-08-12 20:47:30,0.042725,0.0005,2.13625e-05
2026-08-12 20:47:35,0.043945,0.0005,2.19725e-05
2026-08-12 20:47:40,0.025635,0.0005,1.28175e-05
2026-08-12 20:47:45,0.037842,0.0005,1.8921e-05
2026-08-12 20:47:51,0.037842,0.0005,1.8921e-05
2026-08-12 20:47:56,0.037842,0.0005,1.8921e-05
2026-08-12 20:48:01,0.036621,0.0005,1.83105e-05
2026-08-12 20:48:06,0.0354,0.0005,1.77e-05
2026-08-12 20:48:11,0.037842,0.0005,1.8921e-05
2026-08-12 20:48:17,0.032959,0.0005,1.64795e-05
2026-08-12 20:48:22,0.032959,0.0005,1.64795e-05
2026-08-12 20:48:27,0.030518,0.0005,1.5259e-05
2026-08-12 20:48:32,0.031738,0.0005,1.5869e-05
2026-08-12 20:48:37,0.031738,0.0005,1.5869e-05
2026-08-12 20:48:42,0.031738,0.0005,1.5869e-05
2026-08-12 20:48:48,0.032959,0.0005,1.64795e-05
2026-08-12 20:48:53,0.03418,0.0005,1.709e-05
2026-08-12 20:48:58,0.036621,0.0005,1.83105e-05
2026-08-12 20:49:03,0.030518,0.0005,1.5259e-05
2026-08-12 20:49:08,0.031738,0.0005,1.5869e-05
2026-08-12 20:49:13,0.031738,0.0005,1.5869e-05
2026-08-12 20:49:19,0.03418,0.0005,1.709e-05
2026-08-12 20:49:24,0.031738,0.0005,1.5869e-05
2026-08-12 20:49:29,0.032959,0.0005,1.64795e-05
2026-08-12 20:49:34,0.029297,0.0005,1.46485e-05
2026-08-12 20:49:39,0.030518,0.0005,1.5259e-05
2026-08-12 20:49:44,0.031738,0.0005,1.5869e-05
2026-08-12 20:49:50,0.030518,0.0005,1.5259e-05
2026-08-12 20:49:55,0.030518,0.0005,1.5259e-05
2026-08-12 20:50:00,0.030518,0.0005,1.5259e-05
2026-08-12 20:50:05,0.029297,0.0005,1.46485e-05
2026-08-12 20:50:10,0.030518,0.0005,1.5259e-05
2026-08-12 20:50:16,0.031738,0.0005,1.5869e-05
2026-08-12 20:50:21,0.032959,0.0005,1.64795e-05
2026-08-12 20:50:26,0.030518,0.0005,1.5259e-05
2026-08-12 20:50:31,0.032959,0.0005,1.64795e-05
2026-08-12 20:50:36,0.030518,0.0005,1.5259e-05
2026-08-12 20:50:41,0.030518,0.0005,1.5259e-05
2026-08-12 20:50:47,0.031738,0.0005,1.5869e-05
2026-08-12 20:50:52,0.032959,0.0005,1.64795e-05
2026-08-12 20:50:57,0.032959,0.0005,1.64795e-05
2026-08-12 20:51:02,0.029297,0.0005,1.46485e-05
2026-08-12 20:51:07,0.030518,0.0005,1.5259e-05
2026-08-12 20:51:12,0.014648,0.0005,7.324e-06
2026-08-12 20:51:18,0.031738,0.0005,1.5869e-05
2026-08-12 20:51:24,0.028076,0.0005,1.4038e-05
2026-08-12 20:51:29,0.028076,0.0005,1.4038e-05
2026-08-12 20:51:34,0.032959,0.0005,1.64795e-05
2026-08-12 20:51:39,0.032959,0.0005,1.64795e-05
2026-08-12 20:51:44,0.030518,0.0005,1.5259e-05
2026-08-12 20:51:50,0.030518,0.0005,1.5259e-05
2026-08-12 20:51:55,0.031738,0.0005,1.5869e-05
2026-08-12 20:52:00,0.032959,0.0005,1.64795e-05
2026-08-12 20:52:05,0.030518,0.0005,1.5259e-05
2026-08-12 20:52:10,0.028076,0.0005,1.4038e-05
2026-08-12 20:52:15,0.03418,0.0005,1.709e-05
2026-08-12 20:52:21,0.03418,0.0005,1.709e-05
2026-08-12 20:52:26,0.032959,0.0005,1.64795e-05
2026-08-12 20:52:31,0.031738,0.0005,1.5869e-05
2026-08-12 20:52:36,0.031738,0.0005,1.5869e-05
2026-08-12 20:52:41,0.036621,0.0005,1.83105e-05
2026-08-12 20:52:47,0.036621,0.0005,1.83105e-05
2026-08-12 20:52:52,0.03418,0.0005,1.709e-05
2026-08-12 20:52:57,0.023193,0.0005,1.15965e-05
2026-08-12 20:53:02,0.0354,0.0005,1.77e-05
2026-08-12 20:53:07,0.040283,0.0005,2.01415e-05
2026-08-12 20:53:12,0.037842,0.0005,1.8921e-05
2026-08-12 20:53:18,0.042725,0.0005,2.13625e-05
2026-08-12 20:53:23,0.037842,0.0005,1.8921e-05
2026-08-12 20:53:28,0.037842,0.0005,1.8921e-05
2026-08-12 20:53:33,0.037842,0.0005,1.8921e-05
2026-08-12 20:53:38,0.042725,0.0005,2.13625e-05
2026-08-12 20:53:43,0.047607,0.0005,2.38035e-05
2026-08-12 20:53:49,0.045166,0.0005,2.2583e-05
2026-08-12 20:53:54,0.042725,0.0005,2.13625e-05
2026-08-12 20:53:59,0.037842,0.0005,1.8921e-05
2026-08-12 20:54:04,0.040283,0.0005,2.01415e-05
2026-08-12 20:54:09,0.036621,0.0005,1.83105e-05
2026-08-12 20:54:14,0.042725,0.0005,2.13625e-05
2026-08-12 20:54:20,0.037842,0.0005,1.8921e-05
2026-08-12 20:54:25,0.042725,0.0005,2.13625e-05
2026-08-12 20:54:30,0.037842,0.0005,1.8921e-05
2026-08-12 20:54:35,0.037842,0.0005,1.8921e-05
2026-08-12 20:54:40,0.045166,0.0005,2.2583e-05
2026-08-12 20:54:45,0.03418,0.0005,1.709e-05
2026-08-12 20:54:51,0.037842,0.0005,1.8921e-05
2026-08-12 20:54:56,0.043945,0.0005,2.19725e-05
2026-08-12 20:55:01,0.037842,0.0005,1.8921e-05
2026-08-12 20:55:06,0.045166,0.0005,2.2583e-05
2026-08-12 20:55:11,0.042725,0.0005,2.13625e-05
2026-08-12 20:55:16,0.036621,0.0005,1.83105e-05
2026-08-12 20:55:22,0.042725,0.0005,2.13625e-05
2026-08-12 20:55:27,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 20:55:32,0.042725,0.0005,2.13625e-05
2026-08-12 20:55:37,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 20:55:42,0.042725,0.0005,2.13625e-05
2026-08-12 20:55:48,0.042725,0.0005,2.13625e-05
2026-08-12 20:55:53,0.042725,0.0005,2.13625e-05
2026-08-12 20:55:58,0.042725,0.0005,2.13625e-05
2026-08-12 20:56:03,0.040283,0.0005,2.01415e-05
2026-08-12 20:56:08,0.041504,0.0005,2.0752e-05
2026-08-12 20:56:13,0.037842,0.0005,1.8921e-05
2026-08-12 20:56:19,0.047607,0.0005,2.38035e-05
2026-08-12 20:56:24,0.042725,0.0005,2.13625e-05
2026-08-12 20:56:29,0.043945,0.0005,2.19725e-05
2026-08-12 20:56:34,0.045166,0.0005,2.2583e-05
2026-08-12 20:56:39,0.043945,0.0005,2.19725e-05
2026-08-12 20:56:44,0.040283,0.0005,2.01415e-05
2026-08-12 20:56:50,0.042725,0.0005,2.13625e-05
2026-08-12 20:56:55,0.025635,0.0005,1.28175e-05
2026-08-12 20:57:00,0.040283,0.0005,2.01415e-05
2026-08-12 20:57:05,0.040283,0.0005,2.01415e-05
2026-08-12 20:57:10,0.040283,0.0005,2.01415e-05
2026-08-12 20:57:15,0.042725,0.0005,2.13625e-05
2026-08-12 20:57:21,0.036621,0.0005,1.83105e-05
2026-08-12 20:57:26,0.037842,0.0005,1.8921e-05
2026-08-12 20:57:31,0.040283,0.0005,2.01415e-05
2026-08-12 20:57:36,0.042725,0.0005,2.13625e-05
2026-08-12 20:57:41,0.046387,0.0005,2.31935e-05
2026-08-12 20:57:46,0.025635,0.0005,1.28175e-05
2026-08-12 20:57:52,0.036621,0.0005,1.83105e-05
2026-08-12 20:57:57,0.040283,0.0005,2.01415e-05
2026-08-12 20:58:02,0.042725,0.0005,2.13625e-05
2026-08-12 20:58:07,0.043945,0.0005,2.19725e-05
2026-08-12 20:58:12,0.042725,0.0005,2.13625e-05
2026-08-12 20:58:18,0.042725,0.0005,2.13625e-05
2026-08-12 20:58:23,0.025635,0.0005,1.28175e-05
2026-08-12 20:58:28,0.043945,0.0005,2.19725e-05
2026-08-12 20:58:33,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 20:58:38,0.040283,0.0005,2.01415e-05
2026-08-12 20:58:44,0.045166,0.0005,2.2583e-05
2026-08-12 20:58:49,0.036621,0.0005,1.83105e-05
2026-08-12 20:58:59,0.043945,0.0005,2.19725e-05
2026-08-12 20:59:04,0.043945,0.0005,2.19725e-05
2026-08-12 20:59:09,0.046387,0.0005,2.31935e-05
2026-08-12 20:59:14,0.042725,0.0005,2.13625e-05
2026-08-12 20:59:20,0.037842,0.0005,1.8921e-05
2026-08-12 20:59:25,0.043945,0.0005,2.19725e-05
2026-08-12 20:59:30,0.042725,0.0005,2.13625e-05
2026-08-12 20:59:35,0.045166,0.0005,2.2583e-05
2026-08-12 20:59:40,0.042725,0.0005,2.13625e-05
2026-08-12 20:59:46,0.040283,0.0005,2.01415e-05
2026-08-12 20:59:51,0.043945,0.0005,2.19725e-05
2026-08-12 20:59:56,0.043945,0.0005,2.19725e-05
2026-08-12 21:00:01,0.040283,0.0005,2.01415e-05
2026-08-12 21:00:06,0.043945,0.0005,2.19725e-05
2026-08-12 21:00:11,0.042725,0.0005,2.13625e-05
2026-08-12 21:00:17,0.047607,0.0005,2.38035e-05
2026-08-12 21:00:22,0.037842,0.0005,1.8921e-05
2026-08-12 21:00:27,0.0354,0.0005,1.77e-05
2026-08-12 21:00:32,0.047607,0.0005,2.38035e-05
2026-08-12 21:00:37,0.037842,0.0005,1.8921e-05
2026-08-12 21:00:42,0.042725,0.0005,2.13625e-05
2026-08-12 21:00:48,0.042725,0.0005,2.13625e-05
2026-08-12 21:00:53,0.041504,0.0005,2.0752e-05
2026-08-12 21:00:58,0.040283,0.0005,2.01415e-05
2026-08-12 21:01:03,0.0354,0.0005,1.77e-05
2026-08-12 21:01:08,0.047607,0.0005,2.38035e-05
2026-08-12 21:01:14,0.037842,0.0005,1.8921e-05
2026-08-12 21:01:19,0.046387,0.0005,2.31935e-05
2026-08-12 21:01:24,0.037842,0.0005,1.8921e-05
2026-08-12 21:01:29,0.037842,0.0005,1.8921e-05
2026-08-12 21:01:34,0.037842,0.0005,1.8921e-05
2026-08-12 21:01:39,0.042725,0.0005,2.13625e-05
2026-08-12 21:01:45,0.047607,0.0005,2.38035e-05
2026-08-12 21:01:50,0.036621,0.0005,1.83105e-05
2026-08-12 21:01:55,0.037842,0.0005,1.8921e-05
2026-08-12 21:02:00,0.046387,0.0005,2.31935e-05
2026-08-12 21:02:05,0.045166,0.0005,2.2583e-05
2026-08-12 21:02:10,0.047607,0.0005,2.38035e-05
2026-08-12 21:02:16,0.046387,0.0005,2.31935e-05
2026-08-12 21:02:21,0.043945,0.0005,2.19725e-05
2026-08-12 21:02:26,0.036621,0.0005,1.83105e-05
2026-08-12 21:02:31,0.037842,0.0005,1.8921e-05
2026-08-12 21:02:36,0.037842,0.0005,1.8921e-05
2026-08-12 21:02:41,0.037842,0.0005,1.8921e-05
2026-08-12 21:02:47,0.037842,0.0005,1.8921e-05
2026-08-12 21:02:52,0.036621,0.0005,1.83105e-05
2026-08-12 21:02:57,0.042725,0.0005,2.13625e-05
2026-08-12 21:03:02,0.043945,0.0005,2.19725e-05
2026-08-12 21:03:07,0.037842,0.0005,1.8921e-05
2026-08-12 21:03:12,0.037842,0.0005,1.8921e-05
2026-08-12 21:03:18,0.0354,0.0005,1.77e-05
2026-08-12 21:03:23,0.042725,0.0005,2.13625e-05
2026-08-12 21:03:28,0.047607,0.0005,2.38035e-05
2026-08-12 21:03:33,0.036621,0.0005,1.83105e-05
2026-08-12 21:03:38,0.042725,0.0005,2.13625e-05
2026-08-12 21:03:44,0.0354,0.0005,1.77e-05
2026-08-12 21:03:49,0.042725,0.0005,2.13625e-05
2026-08-12 21:03:54,0.043945,0.0005,2.19725e-05
2026-08-12 21:03:59,0.042725,0.0005,2.13625e-05
2026-08-12 21:04:04,0.042725,0.0005,2.13625e-05
2026-08-12 21:04:10,0.043945,0.0005,2.19725e-05
2026-08-12 21:04:15,0.043945,0.0005,2.19725e-05
2026-08-12 21:04:20,0.037842,0.0005,1.8921e-05
2026-08-12 21:04:25,0.037842,0.0005,1.8921e-05
2026-08-12 21:04:35,0.040283,0.0005,2.01415e-05
2026-08-12 21:04:40,0.036621,0.0005,1.83105e-05
2026-08-12 21:04:46,0.050049,0.0005,2.50245e-05
2026-08-12 21:04:51,0.042725,0.0005,2.13625e-05
2026-08-12 21:04:56,0.042725,0.0005,2.13625e-05
2026-08-12 21:05:01,0.040283,0.0005,2.01415e-05
2026-08-12 21:05:06,0.042725,0.0005,2.13625e-05
2026-08-12 21:05:12,0.042725,0.0005,2.13625e-05
2026-08-12 21:05:17,0.037842,0.0005,1.8921e-05
2026-08-12 21:05:22,0.040283,0.0005,2.01415e-05
2026-08-12 21:05:27,0.037842,0.0005,1.8921e-05
2026-08-12 21:05:32,0.037842,0.0005,1.8921e-05
2026-08-12 21:05:37,0.036621,0.0005,1.83105e-05
2026-08-12 21:05:43,0.037842,0.0005,1.8921e-05
2026-08-12 21:05:48,0.043945,0.0005,2.19725e-05
2026-08-12 21:05:53,0.041504,0.0005,2.0752e-05
2026-08-12 21:05:58,0.041504,0.0005,2.0752e-05
2026-08-12 21:06:03,0.042725,0.0005,2.13625e-05
2026-08-12 21:06:08,0.041504,0.0005,2.0752e-05
2026-08-12 21:06:14,0.045166,0.0005,2.2583e-05
2026-08-12 21:06:19,0.047607,0.0005,2.38035e-05
2026-08-12 21:06:24,0.043945,0.0005,2.19725e-05
2026-08-12 21:06:29,0.040283,0.0005,2.01415e-05
2026-08-12 21:06:34,0.042725,0.0005,2.13625e-05
2026-08-12 21:06:40,0.037842,0.0005,1.8921e-05
2026-08-12 21:06:45,0.037842,0.0005,1.8921e-05
2026-08-12 21:06:50,0.040283,0.0005,2.01415e-05
2026-08-12 21:06:55,0.040283,0.0005,2.01415e-05
2026-08-12 21:07:00,0.042725,0.0005,2.13625e-05
2026-08-12 21:07:05,0.040283,0.0005,2.01415e-05
2026-08-12 21:07:11,0.042725,0.0005,2.13625e-05
2026-08-12 21:07:16,0.042725,0.0005,2.13625e-05
2026-08-12 21:07:21,0.037842,0.0005,1.8921e-05
2026-08-12 21:07:26,0.037842,0.0005,1.8921e-05
2026-08-12 21:07:31,0.042725,0.0005,2.13625e-05
2026-08-12 21:07:36,0.037842,0.0005,1.8921e-05
2026-08-12 21:07:42,0.040283,0.0005,2.01415e-05
2026-08-12 21:07:47,0.043945,0.0005,2.19725e-05
2026-08-12 21:07:52,0.040283,0.0005,2.01415e-05
2026-08-12 21:07:57,0.047607,0.0005,2.38035e-05
2026-08-12 21:08:02,0.042725,0.0005,2.13625e-05
2026-08-12 21:08:07,0.037842,0.0005,1.8921e-05
2026-08-12 21:08:13,0.040283,0.0005,2.01415e-05
2026-08-12 21:08:18,0.042725,0.0005,2.13625e-05
2026-08-12 21:08:23,0.037842,0.0005,1.8921e-05
2026-08-12 21:08:28,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:08:33,0.042725,0.0005,2.13625e-05
2026-08-12 21:08:38,0.047607,0.0005,2.38035e-05
2026-08-12 21:08:44,0.040283,0.0005,2.01415e-05
2026-08-12 21:08:49,0.037842,0.0005,1.8921e-05
2026-08-12 21:08:54,0.042725,0.0005,2.13625e-05
2026-08-12 21:08:59,0.037842,0.0005,1.8921e-05
2026-08-12 21:09:04,0.041504,0.0005,2.0752e-05
2026-08-12 21:09:10,0.037842,0.0005,1.8921e-05
2026-08-12 21:09:15,0.036621,0.0005,1.83105e-05
2026-08-12 21:09:20,0.042725,0.0005,2.13625e-05
2026-08-12 21:09:25,0.042725,0.0005,2.13625e-05
2026-08-12 21:09:30,0.043945,0.0005,2.19725e-05
2026-08-12 21:09:35,0.037842,0.0005,1.8921e-05
2026-08-12 21:09:41,0.047607,0.0005,2.38035e-05
2026-08-12 21:09:46,0.037842,0.0005,1.8921e-05
2026-08-12 21:09:51,0.037842,0.0005,1.8921e-05
2026-08-12 21:09:56,0.042725,0.0005,2.13625e-05
2026-08-12 21:10:01,0.047607,0.0005,2.38035e-05
2026-08-12 21:10:06,0.047607,0.0005,2.38035e-05
2026-08-12 21:10:12,0.042725,0.0005,2.13625e-05
2026-08-12 21:10:17,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:10:22,0.036621,0.0005,1.83105e-05
2026-08-12 21:10:27,0.042725,0.0005,2.13625e-05
2026-08-12 21:10:32,0.045166,0.0005,2.2583e-05
2026-08-12 21:10:37,0.040283,0.0005,2.01415e-05
2026-08-12 21:10:43,0.042725,0.0005,2.13625e-05
2026-08-12 21:10:48,0.041504,0.0005,2.0752e-05
2026-08-12 21:10:53,0.042725,0.0005,2.13625e-05
2026-08-12 21:10:58,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:11:03,0.037842,0.0005,1.8921e-05
2026-08-12 21:11:09,0.040283,0.0005,2.01415e-05
2026-08-12 21:11:14,0.037842,0.0005,1.8921e-05
2026-08-12 21:11:19,0.037842,0.0005,1.8921e-05
2026-08-12 21:11:24,0.043945,0.0005,2.19725e-05
2026-08-12 21:11:29,0.047607,0.0005,2.38035e-05
2026-08-12 21:11:34,0.042725,0.0005,2.13625e-05
2026-08-12 21:11:40,0.042725,0.0005,2.13625e-05
2026-08-12 21:11:45,0.040283,0.0005,2.01415e-05
2026-08-12 21:11:50,0.043945,0.0005,2.19725e-05
2026-08-12 21:11:55,0.036621,0.0005,1.83105e-05
2026-08-12 21:12:00,0.036621,0.0005,1.83105e-05
2026-08-12 21:12:06,0.037842,0.0005,1.8921e-05
2026-08-12 21:12:11,0.042725,0.0005,2.13625e-05
2026-08-12 21:12:16,0.0354,0.0005,1.77e-05
2026-08-12 21:12:21,0.047607,0.0005,2.38035e-05
2026-08-12 21:12:26,0.037842,0.0005,1.8921e-05
2026-08-12 21:12:31,0.037842,0.0005,1.8921e-05
2026-08-12 21:12:37,0.042725,0.0005,2.13625e-05
2026-08-12 21:12:42,0.040283,0.0005,2.01415e-05
2026-08-12 21:12:47,0.042725,0.0005,2.13625e-05
2026-08-12 21:12:52,0.042725,0.0005,2.13625e-05
2026-08-12 21:12:58,0.0354,0.0005,1.77e-05
2026-08-12 21:13:03,0.042725,0.0005,2.13625e-05
2026-08-12 21:13:08,0.043945,0.0005,2.19725e-05
2026-08-12 21:13:13,0.042725,0.0005,2.13625e-05
2026-08-12 21:13:18,0.045166,0.0005,2.2583e-05
2026-08-12 21:13:24,0.045166,0.0005,2.2583e-05
2026-08-12 21:13:29,0.043945,0.0005,2.19725e-05
2026-08-12 21:13:34,0.045166,0.0005,2.2583e-05
2026-08-12 21:13:39,0.042725,0.0005,2.13625e-05
2026-08-12 21:13:44,0.043945,0.0005,2.19725e-05
2026-08-12 21:13:49,0.045166,0.0005,2.2583e-05
2026-08-12 21:13:55,0.043945,0.0005,2.19725e-05
2026-08-12 21:14:00,0.042725,0.0005,2.13625e-05
2026-08-12 21:14:05,0.040283,0.0005,2.01415e-05
2026-08-12 21:14:10,0.037842,0.0005,1.8921e-05
2026-08-12 21:14:16,0.047607,0.0005,2.38035e-05
2026-08-12 21:14:21,0.045166,0.0005,2.2583e-05
2026-08-12 21:14:26,0.047607,0.0005,2.38035e-05
2026-08-12 21:14:32,0.043945,0.0005,2.19725e-05
2026-08-12 21:14:37,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:14:42,0.043945,0.0005,2.19725e-05
2026-08-12 21:14:47,0.042725,0.0005,2.13625e-05
2026-08-12 21:14:52,0.046387,0.0005,2.31935e-05
2026-08-12 21:14:57,0.046387,0.0005,2.31935e-05
2026-08-12 21:15:03,0.046387,0.0005,2.31935e-05
2026-08-12 21:15:08,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:15:13,0.043945,0.0005,2.19725e-05
2026-08-12 21:15:18,0.047607,0.0005,2.38035e-05
2026-08-12 21:15:23,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:15:28,0.043945,0.0005,2.19725e-05
2026-08-12 21:15:34,0.042725,0.0005,2.13625e-05
2026-08-12 21:15:39,0.046387,0.0005,2.31935e-05
2026-08-12 21:15:44,0.045166,0.0005,2.2583e-05
2026-08-12 21:15:49,0.042725,0.0005,2.13625e-05
2026-08-12 21:15:54,0.037842,0.0005,1.8921e-05
2026-08-12 21:15:59,0.045166,0.0005,2.2583e-05
2026-08-12 21:16:05,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:16:10,0.045166,0.0005,2.2583e-05
2026-08-12 21:16:15,0.045166,0.0005,2.2583e-05
2026-08-12 21:16:20,0.042725,0.0005,2.13625e-05
2026-08-12 21:16:25,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:16:31,0.041504,0.0005,2.0752e-05
2026-08-12 21:16:36,0.040283,0.0005,2.01415e-05
2026-08-12 21:16:41,0.045166,0.0005,2.2583e-05
2026-08-12 21:16:46,0.040283,0.0005,2.01415e-05
2026-08-12 21:16:51,0.042725,0.0005,2.13625e-05
2026-08-12 21:16:56,0.045166,0.0005,2.2583e-05
2026-08-12 21:17:02,0.045166,0.0005,2.2583e-05
2026-08-12 21:17:07,0.045166,0.0005,2.2583e-05
2026-08-12 21:17:12,0.045166,0.0005,2.2583e-05
2026-08-12 21:17:17,0.042725,0.0005,2.13625e-05
2026-08-12 21:17:22,0.043945,0.0005,2.19725e-05
2026-08-12 21:17:27,0.045166,0.0005,2.2583e-05
2026-08-12 21:17:33,0.037842,0.0005,1.8921e-05
2026-08-12 21:17:38,0.047607,0.0005,2.38035e-05
2026-08-12 21:17:43,0.037842,0.0005,1.8921e-05
2026-08-12 21:17:48,0.037842,0.0005,1.8921e-05
2026-08-12 21:17:53,0.047607,0.0005,2.38035e-05
2026-08-12 21:17:59,0.040283,0.0005,2.01415e-05
2026-08-12 21:18:04,0.045166,0.0005,2.2583e-05
2026-08-12 21:18:09,0.045166,0.0005,2.2583e-05
2026-08-12 21:18:14,0.050049,0.0005,2.50245e-05
2026-08-12 21:18:19,0.036621,0.0005,1.83105e-05
2026-08-12 21:18:24,0.043945,0.0005,2.19725e-05
2026-08-12 21:18:30,0.047607,0.0005,2.38035e-05
2026-08-12 21:18:35,0.045166,0.0005,2.2583e-05
2026-08-12 21:18:40,0.046387,0.0005,2.31935e-05
2026-08-12 21:18:45,0.045166,0.0005,2.2583e-05
2026-08-12 21:18:50,0.037842,0.0005,1.8921e-05
2026-08-12 21:18:55,0.042725,0.0005,2.13625e-05
2026-08-12 21:19:01,0.046387,0.0005,2.31935e-05
2026-08-12 21:19:06,0.043945,0.0005,2.19725e-05
2026-08-12 21:19:11,0.042725,0.0005,2.13625e-05
2026-08-12 21:19:16,0.043945,0.0005,2.19725e-05
2026-08-12 21:19:21,0.045166,0.0005,2.2583e-05
2026-08-12 21:19:27,0.037842,0.0005,1.8921e-05
2026-08-12 21:19:32,0.041504,0.0005,2.0752e-05
2026-08-12 21:19:37,0.036621,0.0005,1.83105e-05
2026-08-12 21:19:42,0.042725,0.0005,2.13625e-05
2026-08-12 21:19:47,0.042725,0.0005,2.13625e-05
2026-08-12 21:19:52,0.041504,0.0005,2.0752e-05
2026-08-12 21:19:58,0.037842,0.0005,1.8921e-05
2026-08-12 21:20:03,0.045166,0.0005,2.2583e-05
2026-08-12 21:20:08,0.042725,0.0005,2.13625e-05
2026-08-12 21:20:13,0.043945,0.0005,2.19725e-05
2026-08-12 21:20:18,0.045166,0.0005,2.2583e-05
2026-08-12 21:20:24,0.036621,0.0005,1.83105e-05
2026-08-12 21:20:29,0.050049,0.0005,2.50245e-05
2026-08-12 21:20:34,0.042725,0.0005,2.13625e-05
2026-08-12 21:20:39,0.043945,0.0005,2.19725e-05
2026-08-12 21:20:44,0.042725,0.0005,2.13625e-05
2026-08-12 21:20:49,0.043945,0.0005,2.19725e-05
2026-08-12 21:20:54,0.040283,0.0005,2.01415e-05
2026-08-12 21:21:00,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:21:05,0.045166,0.0005,2.2583e-05
2026-08-12 21:21:10,0.042725,0.0005,2.13625e-05
2026-08-12 21:21:15,0.041504,0.0005,2.0752e-05
2026-08-12 21:21:20,0.043945,0.0005,2.19725e-05
2026-08-12 21:21:25,0.047607,0.0005,2.38035e-05
2026-08-12 21:21:31,0.043945,0.0005,2.19725e-05
2026-08-12 21:21:36,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:21:41,0.047607,0.0005,2.38035e-05
2026-08-12 21:21:46,0.042725,0.0005,2.13625e-05
2026-08-12 21:21:51,0.043945,0.0005,2.19725e-05
2026-08-12 21:21:57,0.0354,0.0005,1.77e-05
2026-08-12 21:22:02,0.047607,0.0005,2.38035e-05
2026-08-12 21:22:07,0.042725,0.0005,2.13625e-05
2026-08-12 21:22:12,0.042725,0.0005,2.13625e-05
2026-08-12 21:22:17,0.037842,0.0005,1.8921e-05
2026-08-12 21:22:22,0.040283,0.0005,2.01415e-05
2026-08-12 21:22:28,0.040283,0.0005,2.01415e-05
2026-08-12 21:22:33,0.045166,0.0005,2.2583e-05
2026-08-12 21:22:38,0.042725,0.0005,2.13625e-05
2026-08-12 21:22:43,0.042725,0.0005,2.13625e-05
2026-08-12 21:22:48,0.042725,0.0005,2.13625e-05
2026-08-12 21:22:53,0.042725,0.0005,2.13625e-05
2026-08-12 21:22:59,0.042725,0.0005,2.13625e-05
2026-08-12 21:23:04,0.043945,0.0005,2.19725e-05
2026-08-12 21:23:09,0.045166,0.0005,2.2583e-05
2026-08-12 21:23:14,0.040283,0.0005,2.01415e-05
2026-08-12 21:23:19,0.045166,0.0005,2.2583e-05
2026-08-12 21:23:25,0.045166,0.0005,2.2583e-05
2026-08-12 21:23:30,0.037842,0.0005,1.8921e-05
2026-08-12 21:23:35,0.046387,0.0005,2.31935e-05
2026-08-12 21:23:40,0.042725,0.0005,2.13625e-05
2026-08-12 21:23:45,0.047607,0.0005,2.38035e-05
2026-08-12 21:23:50,0.037842,0.0005,1.8921e-05
2026-08-12 21:23:55,0.042725,0.0005,2.13625e-05
2026-08-12 21:24:01,0.043945,0.0005,2.19725e-05
2026-08-12 21:24:06,0.037842,0.0005,1.8921e-05
2026-08-12 21:24:11,0.042725,0.0005,2.13625e-05
2026-08-12 21:24:16,0.045166,0.0005,2.2583e-05
2026-08-12 21:24:21,0.042725,0.0005,2.13625e-05
2026-08-12 21:24:27,0.045166,0.0005,2.2583e-05
2026-08-12 21:24:32,0.037842,0.0005,1.8921e-05
2026-08-12 21:24:37,0.037842,0.0005,1.8921e-05
2026-08-12 21:24:42,0.042725,0.0005,2.13625e-05
2026-08-12 21:24:47,0.047607,0.0005,2.38035e-05
2026-08-12 21:24:53,0.037842,0.0005,1.8921e-05
2026-08-12 21:24:58,0.042725,0.0005,2.13625e-05
2026-08-12 21:25:03,0.042725,0.0005,2.13625e-05
2026-08-12 21:25:08,0.040283,0.0005,2.01415e-05
2026-08-12 21:25:13,0.045166,0.0005,2.2583e-05
2026-08-12 21:25:18,0.037842,0.0005,1.8921e-05
2026-08-12 21:25:23,0.040283,0.0005,2.01415e-05
2026-08-12 21:25:29,0.042725,0.0005,2.13625e-05
2026-08-12 21:25:34,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:25:39,0.042725,0.0005,2.13625e-05
2026-08-12 21:25:44,0.042725,0.0005,2.13625e-05
2026-08-12 21:25:49,0.042725,0.0005,2.13625e-05
2026-08-12 21:25:55,0.042725,0.0005,2.13625e-05
2026-08-12 21:26:00,0.043945,0.0005,2.19725e-05
2026-08-12 21:26:05,0.042725,0.0005,2.13625e-05
2026-08-12 21:26:10,0.045166,0.0005,2.2583e-05
2026-08-12 21:26:15,0.045166,0.0005,2.2583e-05
2026-08-12 21:26:26,0.024414,0.0005,1.2207000000000002e-05
2026-08-12 21:26:31,0.043945,0.0005,2.19725e-05
2026-08-12 21:26:36,0.037842,0.0005,1.8921e-05
2026-08-12 21:26:41,0.037842,0.0005,1.8921e-05
2026-08-12 21:26:46,0.045166,0.0005,2.2583e-05
2026-08-12 21:26:51,0.042725,0.0005,2.13625e-05
2026-08-12 21:26:57,0.042725,0.0005,2.13625e-05
2026-08-12 21:27:02,0.040283,0.0005,2.01415e-05
2026-08-12 21:27:07,0.040283,0.0005,2.01415e-05
2026-08-12 21:27:12,0.043945,0.0005,2.19725e-05
2026-08-12 21:27:17,0.040283,0.0005,2.01415e-05
2026-08-12 21:27:23,0.045166,0.0005,2.2583e-05
2026-08-12 21:27:28,0.042725,0.0005,2.13625e-05
2026-08-12 21:27:33,0.050049,0.0005,2.50245e-05
2026-08-12 21:27:38,0.043945,0.0005,2.19725e-05
2026-08-12 21:27:43,0.037842,0.0005,1.8921e-05
2026-08-12 21:27:48,0.045166,0.0005,2.2583e-05
2026-08-12 21:27:54,0.037842,0.0005,1.8921e-05
2026-08-12 21:27:59,0.037842,0.0005,1.8921e-05
2026-08-12 21:28:04,0.043945,0.0005,2.19725e-05
2026-08-12 21:28:09,0.037842,0.0005,1.8921e-05
2026-08-12 21:28:14,0.045166,0.0005,2.2583e-05
2026-08-12 21:28:19,0.045166,0.0005,2.2583e-05
2026-08-12 21:28:25,0.042725,0.0005,2.13625e-05
2026-08-12 21:28:30,0.036621,0.0005,1.83105e-05
2026-08-12 21:28:35,0.041504,0.0005,2.0752e-05
2026-08-12 21:28:40,0.045166,0.0005,2.2583e-05
2026-08-12 21:28:45,0.037842,0.0005,1.8921e-05
2026-08-12 21:28:51,0.047607,0.0005,2.38035e-05
2026-08-12 21:28:56,0.043945,0.0005,2.19725e-05
2026-08-12 21:29:01,0.047607,0.0005,2.38035e-05
2026-08-12 21:29:06,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:29:11,0.046387,0.0005,2.31935e-05
2026-08-12 21:29:16,0.043945,0.0005,2.19725e-05
2026-08-12 21:29:21,0.037842,0.0005,1.8921e-05
2026-08-12 21:29:27,0.042725,0.0005,2.13625e-05
2026-08-12 21:29:32,0.043945,0.0005,2.19725e-05
2026-08-12 21:29:37,0.021973,0.0005,1.09865e-05
2026-08-12 21:29:42,0.047607,0.0005,2.38035e-05
2026-08-12 21:29:47,0.043945,0.0005,2.19725e-05
2026-08-12 21:29:53,0.040283,0.0005,2.01415e-05
2026-08-12 21:29:58,0.045166,0.0005,2.2583e-05
2026-08-12 21:30:03,0.042725,0.0005,2.13625e-05
2026-08-12 21:30:08,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:30:13,0.042725,0.0005,2.13625e-05
2026-08-12 21:30:18,0.037842,0.0005,1.8921e-05
2026-08-12 21:30:24,0.043945,0.0005,2.19725e-05
2026-08-12 21:30:29,0.045166,0.0005,2.2583e-05
2026-08-12 21:30:34,0.040283,0.0005,2.01415e-05
2026-08-12 21:30:39,0.040283,0.0005,2.01415e-05
2026-08-12 21:30:44,0.040283,0.0005,2.01415e-05
2026-08-12 21:30:49,0.037842,0.0005,1.8921e-05
2026-08-12 21:30:55,0.047607,0.0005,2.38035e-05
2026-08-12 21:31:00,0.043945,0.0005,2.19725e-05
2026-08-12 21:31:05,0.0354,0.0005,1.77e-05
2026-08-12 21:31:10,0.043945,0.0005,2.19725e-05
2026-08-12 21:31:15,0.042725,0.0005,2.13625e-05
2026-08-12 21:31:20,0.040283,0.0005,2.01415e-05
2026-08-12 21:31:26,0.042725,0.0005,2.13625e-05
2026-08-12 21:31:31,0.045166,0.0005,2.2583e-05
2026-08-12 21:31:36,0.040283,0.0005,2.01415e-05
2026-08-12 21:31:41,0.042725,0.0005,2.13625e-05
2026-08-12 21:31:46,0.042725,0.0005,2.13625e-05
2026-08-12 21:31:52,0.037842,0.0005,1.8921e-05
2026-08-12 21:31:57,0.045166,0.0005,2.2583e-05
2026-08-12 21:32:02,0.043945,0.0005,2.19725e-05
2026-08-12 21:32:07,0.045166,0.0005,2.2583e-05
2026-08-12 21:32:12,0.037842,0.0005,1.8921e-05
2026-08-12 21:32:17,0.047607,0.0005,2.38035e-05
2026-08-12 21:32:23,0.037842,0.0005,1.8921e-05
2026-08-12 21:32:28,0.0354,0.0005,1.77e-05
2026-08-12 21:32:33,0.037842,0.0005,1.8921e-05
2026-08-12 21:32:38,0.040283,0.0005,2.01415e-05
2026-08-12 21:32:43,0.042725,0.0005,2.13625e-05
2026-08-12 21:32:49,0.037842,0.0005,1.8921e-05
2026-08-12 21:32:54,0.043945,0.0005,2.19725e-05
2026-08-12 21:32:59,0.043945,0.0005,2.19725e-05
2026-08-12 21:33:04,0.040283,0.0005,2.01415e-05
2026-08-12 21:33:09,0.040283,0.0005,2.01415e-05
2026-08-12 21:33:14,0.041504,0.0005,2.0752e-05
2026-08-12 21:33:20,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:33:25,0.045166,0.0005,2.2583e-05
2026-08-12 21:33:30,0.042725,0.0005,2.13625e-05
2026-08-12 21:33:35,0.0354,0.0005,1.77e-05
2026-08-12 21:33:40,0.041504,0.0005,2.0752e-05
2026-08-12 21:33:45,0.042725,0.0005,2.13625e-05
2026-08-12 21:33:51,0.043945,0.0005,2.19725e-05
2026-08-12 21:33:56,0.040283,0.0005,2.01415e-05
2026-08-12 21:34:01,0.045166,0.0005,2.2583e-05
2026-08-12 21:34:06,0.040283,0.0005,2.01415e-05
2026-08-12 21:34:11,0.036621,0.0005,1.83105e-05
2026-08-12 21:34:17,0.043945,0.0005,2.19725e-05
2026-08-12 21:34:22,0.042725,0.0005,2.13625e-05
2026-08-12 21:34:27,0.042725,0.0005,2.13625e-05
2026-08-12 21:34:32,0.043945,0.0005,2.19725e-05
2026-08-12 21:34:37,0.045166,0.0005,2.2583e-05
2026-08-12 21:34:42,0.037842,0.0005,1.8921e-05
2026-08-12 21:34:47,0.042725,0.0005,2.13625e-05
2026-08-12 21:34:53,0.037842,0.0005,1.8921e-05
2026-08-12 21:34:58,0.042725,0.0005,2.13625e-05
2026-08-12 21:35:03,0.037842,0.0005,1.8921e-05
2026-08-12 21:35:08,0.043945,0.0005,2.19725e-05
2026-08-12 21:35:13,0.042725,0.0005,2.13625e-05
2026-08-12 21:35:19,0.037842,0.0005,1.8921e-05
2026-08-12 21:35:24,0.043945,0.0005,2.19725e-05
2026-08-12 21:35:29,0.045166,0.0005,2.2583e-05
2026-08-12 21:35:34,0.045166,0.0005,2.2583e-05
2026-08-12 21:35:39,0.046387,0.0005,2.31935e-05
2026-08-12 21:35:45,0.037842,0.0005,1.8921e-05
2026-08-12 21:35:50,0.045166,0.0005,2.2583e-05
2026-08-12 21:35:55,0.045166,0.0005,2.2583e-05
2026-08-12 21:36:00,0.040283,0.0005,2.01415e-05
2026-08-12 21:36:05,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:10,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:15,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:21,0.037842,0.0005,1.8921e-05
2026-08-12 21:36:26,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:31,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:36,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:41,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:46,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:52,0.042725,0.0005,2.13625e-05
2026-08-12 21:36:57,0.042725,0.0005,2.13625e-05
2026-08-12 21:37:02,0.043945,0.0005,2.19725e-05
2026-08-12 21:37:07,0.042725,0.0005,2.13625e-05
2026-08-12 21:37:12,0.037842,0.0005,1.8921e-05
2026-08-12 21:37:18,0.042725,0.0005,2.13625e-05
2026-08-12 21:37:23,0.047607,0.0005,2.38035e-05
2026-08-12 21:37:28,0.042725,0.0005,2.13625e-05
2026-08-12 21:37:33,0.043945,0.0005,2.19725e-05
2026-08-12 21:37:38,0.040283,0.0005,2.01415e-05
2026-08-12 21:37:43,0.045166,0.0005,2.2583e-05
2026-08-12 21:37:49,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:37:54,0.042725,0.0005,2.13625e-05
2026-08-12 21:37:59,0.041504,0.0005,2.0752e-05
2026-08-12 21:38:04,0.047607,0.0005,2.38035e-05
2026-08-12 21:38:09,0.037842,0.0005,1.8921e-05
2026-08-12 21:38:14,0.046387,0.0005,2.31935e-05
2026-08-12 21:38:20,0.045166,0.0005,2.2583e-05
2026-08-12 21:38:25,0.045166,0.0005,2.2583e-05
2026-08-12 21:38:30,0.042725,0.0005,2.13625e-05
2026-08-12 21:38:35,0.042725,0.0005,2.13625e-05
2026-08-12 21:38:40,0.037842,0.0005,1.8921e-05
2026-08-12 21:38:46,0.040283,0.0005,2.01415e-05
2026-08-12 21:38:51,0.040283,0.0005,2.01415e-05
2026-08-12 21:38:56,0.042725,0.0005,2.13625e-05
2026-08-12 21:39:01,0.042725,0.0005,2.13625e-05
2026-08-12 21:39:06,0.037842,0.0005,1.8921e-05
2026-08-12 21:39:11,0.042725,0.0005,2.13625e-05
2026-08-12 21:39:17,0.042725,0.0005,2.13625e-05
2026-08-12 21:39:22,0.036621,0.0005,1.83105e-05
2026-08-12 21:39:27,0.042725,0.0005,2.13625e-05
2026-08-12 21:39:32,0.043945,0.0005,2.19725e-05
2026-08-12 21:39:37,0.045166,0.0005,2.2583e-05
2026-08-12 21:39:43,0.036621,0.0005,1.83105e-05
2026-08-12 21:39:48,0.043945,0.0005,2.19725e-05
2026-08-12 21:39:53,0.037842,0.0005,1.8921e-05
2026-08-12 21:39:58,0.037842,0.0005,1.8921e-05
2026-08-12 21:40:03,0.042725,0.0005,2.13625e-05
2026-08-12 21:40:08,0.045166,0.0005,2.2583e-05
2026-08-12 21:40:14,0.036621,0.0005,1.83105e-05
2026-08-12 21:40:19,0.037842,0.0005,1.8921e-05
2026-08-12 21:40:24,0.037842,0.0005,1.8921e-05
2026-08-12 21:40:29,0.037842,0.0005,1.8921e-05
2026-08-12 21:40:34,0.043945,0.0005,2.19725e-05
2026-08-12 21:40:39,0.047607,0.0005,2.38035e-05
2026-08-12 21:40:45,0.037842,0.0005,1.8921e-05
2026-08-12 21:40:50,0.043945,0.0005,2.19725e-05
2026-08-12 21:40:55,0.043945,0.0005,2.19725e-05
2026-08-12 21:41:00,0.042725,0.0005,2.13625e-05
2026-08-12 21:41:05,0.047607,0.0005,2.38035e-05
2026-08-12 21:42:30,0.042725,0.0005,2.13625e-05
2026-08-12 21:43:57,0.045166,0.0005,2.2583e-05
2026-08-12 21:44:04,0.047607,0.0005,2.38035e-05
2026-08-12 21:44:09,0.043945,0.0005,2.19725e-05
2026-08-12 21:44:14,0.047607,0.0005,2.38035e-05
2026-08-12 21:44:20,0.047607,0.0005,2.38035e-05
2026-08-12 21:44:25,0.046387,0.0005,2.31935e-05
2026-08-12 21:44:30,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:44:35,0.047607,0.0005,2.38035e-05
2026-08-12 21:44:40,0.047607,0.0005,2.38035e-05
2026-08-12 21:44:45,0.045166,0.0005,2.2583e-05
2026-08-12 21:44:50,0.047607,0.0005,2.38035e-05
2026-08-12 21:44:56,0.045166,0.0005,2.2583e-05
2026-08-12 21:45:01,0.047607,0.0005,2.38035e-05
2026-08-12 21:45:06,0.05249,0.0005,2.6245e-05
2026-08-12 21:45:11,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:45:16,0.046387,0.0005,2.31935e-05
2026-08-12 21:45:21,0.045166,0.0005,2.2583e-05
2026-08-12 21:45:27,0.045166,0.0005,2.2583e-05
2026-08-12 21:45:32,0.046387,0.0005,2.31935e-05
2026-08-12 21:45:37,0.05249,0.0005,2.6245e-05
2026-08-12 21:45:42,0.045166,0.0005,2.2583e-05
2026-08-12 21:45:47,0.05249,0.0005,2.6245e-05
2026-08-12 21:45:52,0.05127,0.0005,2.5635e-05
2026-08-12 21:45:57,0.045166,0.0005,2.2583e-05
2026-08-12 21:46:03,0.045166,0.0005,2.2583e-05
2026-08-12 21:46:08,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:46:13,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:46:18,0.045166,0.0005,2.2583e-05
2026-08-12 21:46:23,0.046387,0.0005,2.31935e-05
2026-08-12 21:46:28,0.047607,0.0005,2.38035e-05
2026-08-12 21:46:34,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:46:39,0.045166,0.0005,2.2583e-05
2026-08-12 21:46:44,0.047607,0.0005,2.38035e-05
2026-08-12 21:46:49,0.046387,0.0005,2.31935e-05
2026-08-12 21:47:00,0.053711,0.0005,2.68555e-05
2026-08-12 21:47:05,0.05249,0.0005,2.6245e-05
2026-08-12 21:47:10,0.046387,0.0005,2.31935e-05
2026-08-12 21:47:15,0.047607,0.0005,2.38035e-05
2026-08-12 21:47:20,0.047607,0.0005,2.38035e-05
2026-08-12 21:47:26,0.046387,0.0005,2.31935e-05
2026-08-12 21:47:31,0.053711,0.0005,2.68555e-05
2026-08-12 21:47:36,0.047607,0.0005,2.38035e-05
2026-08-12 21:47:41,0.042725,0.0005,2.13625e-05
2026-08-12 21:47:46,0.047607,0.0005,2.38035e-05
2026-08-12 21:47:51,0.050049,0.0005,2.50245e-05
2026-08-12 21:47:56,0.046387,0.0005,2.31935e-05
2026-08-12 21:48:02,0.045166,0.0005,2.2583e-05
2026-08-12 21:48:07,0.045166,0.0005,2.2583e-05
2026-08-12 21:48:12,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:17,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:22,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:27,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:32,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:48:38,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:43,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:48,0.046387,0.0005,2.31935e-05
2026-08-12 21:48:53,0.047607,0.0005,2.38035e-05
2026-08-12 21:48:58,0.047607,0.0005,2.38035e-05
2026-08-12 21:49:03,0.046387,0.0005,2.31935e-05
2026-08-12 21:49:08,0.046387,0.0005,2.31935e-05
2026-08-12 21:49:14,0.028076,0.0005,1.4038e-05
2026-08-12 21:49:19,0.047607,0.0005,2.38035e-05
2026-08-12 21:49:24,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:49:29,0.047607,0.0005,2.38035e-05
2026-08-12 21:49:34,0.042725,0.0005,2.13625e-05
2026-08-12 21:49:39,0.047607,0.0005,2.38035e-05
2026-08-12 21:49:44,0.046387,0.0005,2.31935e-05
2026-08-12 21:50:00,0.031738,0.0005,1.5869e-05
2026-08-12 21:50:05,0.047607,0.0005,2.38035e-05
2026-08-12 21:50:10,0.028076,0.0005,1.4038e-05
2026-08-12 21:50:15,0.050049,0.0005,2.50245e-05
2026-08-12 21:50:20,0.043945,0.0005,2.19725e-05
2026-08-12 21:50:26,0.045166,0.0005,2.2583e-05
2026-08-12 21:50:31,0.054932,0.0005,2.7466e-05
2026-08-12 21:50:36,0.050049,0.0005,2.50245e-05
2026-08-12 21:50:41,0.045166,0.0005,2.2583e-05
2026-08-12 21:50:46,0.045166,0.0005,2.2583e-05
2026-08-12 21:50:51,0.047607,0.0005,2.38035e-05
2026-08-12 21:50:57,0.045166,0.0005,2.2583e-05
2026-08-12 21:51:02,0.046387,0.0005,2.31935e-05
2026-08-12 21:51:07,0.047607,0.0005,2.38035e-05
2026-08-12 21:51:12,0.046387,0.0005,2.31935e-05
2026-08-12 21:51:17,0.05249,0.0005,2.6245e-05
2026-08-12 21:51:22,0.045166,0.0005,2.2583e-05
2026-08-12 21:51:27,0.05127,0.0005,2.5635e-05
2026-08-12 21:51:32,0.050049,0.0005,2.50245e-05
2026-08-12 21:51:38,0.045166,0.0005,2.2583e-05
2026-08-12 21:51:43,0.047607,0.0005,2.38035e-05
2026-08-12 21:51:48,0.047607,0.0005,2.38035e-05
2026-08-12 21:51:53,0.047607,0.0005,2.38035e-05
2026-08-12 21:51:58,0.05127,0.0005,2.5635e-05
2026-08-12 21:52:03,0.047607,0.0005,2.38035e-05
2026-08-12 21:52:08,0.053711,0.0005,2.68555e-05
2026-08-12 21:52:18,0.047607,0.0005,2.38035e-05
2026-08-12 21:52:24,0.046387,0.0005,2.31935e-05
2026-08-12 21:52:29,0.047607,0.0005,2.38035e-05
2026-08-12 21:52:34,0.046387,0.0005,2.31935e-05
2026-08-12 21:52:39,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:52:44,0.046387,0.0005,2.31935e-05
2026-08-12 21:52:49,0.047607,0.0005,2.38035e-05
2026-08-12 21:52:54,0.047607,0.0005,2.38035e-05
2026-08-12 21:52:59,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:10,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:15,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:20,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:26,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:31,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:36,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:41,0.028076,0.0005,1.4038e-05
2026-08-12 21:53:47,0.046387,0.0005,2.31935e-05
2026-08-12 21:53:52,0.047607,0.0005,2.38035e-05
2026-08-12 21:53:57,0.050049,0.0005,2.50245e-05
2026-08-12 21:54:02,0.047607,0.0005,2.38035e-05
2026-08-12 21:54:07,0.050049,0.0005,2.50245e-05
2026-08-12 21:54:12,0.047607,0.0005,2.38035e-05
2026-08-12 21:54:18,0.047607,0.0005,2.38035e-05
2026-08-12 21:54:23,0.045166,0.0005,2.2583e-05
2026-08-12 21:54:28,0.050049,0.0005,2.50245e-05
2026-08-12 21:54:33,0.050049,0.0005,2.50245e-05
2026-08-12 21:54:38,0.046387,0.0005,2.31935e-05
2026-08-12 21:54:43,0.045166,0.0005,2.2583e-05
2026-08-12 21:54:48,0.047607,0.0005,2.38035e-05
2026-08-12 21:54:54,0.045166,0.0005,2.2583e-05
2026-08-12 21:54:59,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:55:09,0.050049,0.0005,2.50245e-05
2026-08-12 21:55:14,0.045166,0.0005,2.2583e-05
2026-08-12 21:55:19,0.047607,0.0005,2.38035e-05
2026-08-12 21:55:24,0.050049,0.0005,2.50245e-05
2026-08-12 21:55:30,0.047607,0.0005,2.38035e-05
2026-08-12 21:55:35,0.046387,0.0005,2.31935e-05
2026-08-12 21:55:40,0.050049,0.0005,2.50245e-05
2026-08-12 21:55:45,0.045166,0.0005,2.2583e-05
2026-08-12 21:55:50,0.045166,0.0005,2.2583e-05
2026-08-12 21:55:55,0.047607,0.0005,2.38035e-05
2026-08-12 21:56:00,0.047607,0.0005,2.38035e-05
2026-08-12 21:56:06,0.047607,0.0005,2.38035e-05
2026-08-12 21:56:16,0.047607,0.0005,2.38035e-05
2026-08-12 21:56:21,0.047607,0.0005,2.38035e-05
2026-08-12 21:57:01,0.046387,0.0005,2.31935e-05
2026-08-12 21:57:06,0.045166,0.0005,2.2583e-05
2026-08-12 21:57:11,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:57:16,0.045166,0.0005,2.2583e-05
2026-08-12 21:57:21,0.047607,0.0005,2.38035e-05
2026-08-12 21:57:26,0.046387,0.0005,2.31935e-05
2026-08-12 21:57:32,0.047607,0.0005,2.38035e-05
2026-08-12 21:57:37,0.045166,0.0005,2.2583e-05
2026-08-12 21:57:42,0.046387,0.0005,2.31935e-05
2026-08-12 21:57:47,0.045166,0.0005,2.2583e-05
2026-08-12 21:57:52,0.047607,0.0005,2.38035e-05
2026-08-12 21:57:57,0.046387,0.0005,2.31935e-05
2026-08-12 21:58:02,0.047607,0.0005,2.38035e-05
2026-08-12 21:58:07,0.047607,0.0005,2.38035e-05
2026-08-12 21:58:13,0.046387,0.0005,2.31935e-05
2026-08-12 21:58:18,0.047607,0.0005,2.38035e-05
2026-08-12 21:58:23,0.047607,0.0005,2.38035e-05
2026-08-12 21:58:28,0.045166,0.0005,2.2583e-05
2026-08-12 21:58:33,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:58:38,0.047607,0.0005,2.38035e-05
2026-08-12 21:58:44,0.045166,0.0005,2.2583e-05
2026-08-12 21:58:49,0.042725,0.0005,2.13625e-05
2026-08-12 21:58:54,0.046387,0.0005,2.31935e-05
2026-08-12 21:58:59,0.047607,0.0005,2.38035e-05
2026-08-12 21:59:04,0.048828,0.0005,2.4414000000000004e-05
2026-08-12 21:59:09,0.047607,0.0005,2.38035e-05
2026-08-12 21:59:14,0.047607,0.0005,2.38035e-05
2026-08-12 21:59:19,0.046387,0.0005,2.31935e-05
2026-08-12 21:59:25,0.046387,0.0005,2.31935e-05
2026-08-12 21:59:30,0.047607,0.0005,2.38035e-05
2026-08-12 21:59:04,0.047607,0.0005,2.38035e-05
2026-08-12 21:59:09,0.047607,0.0005,2.38035e-05
2026-08-12 21:59:14,0.046387,0.0005,2.31935e-05
2026-08-12 21:59:19,0.058594,0.0005,2.9297e-05
2026-08-12 21:59:26,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 21:59:31,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 21:59:37,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 21:59:42,0.084229,0.0005,4.21145e-05
2026-08-12 21:59:47,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 21:59:52,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 21:59:57,0.062256,0.0005,3.1128e-05
2026-08-12 22:00:02,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:00:07,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:00:12,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:00:18,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:00:23,0.063477,0.0005,3.17385e-05
2026-08-12 22:00:28,0.065918,0.0005,3.2959e-05
2026-08-12 22:00:33,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:00:38,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:00:43,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:00:49,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:00:54,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:00:59,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:01:04,0.040283,0.0005,2.01415e-05
2026-08-12 22:01:09,0.068359,0.0005,3.41795e-05
2026-08-12 22:01:14,0.068359,0.0005,3.41795e-05
2026-08-12 22:01:19,0.065918,0.0005,3.2959e-05
2026-08-12 22:01:25,0.068359,0.0005,3.41795e-05
2026-08-12 22:01:31,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:01:36,0.065918,0.0005,3.2959e-05
2026-08-12 22:01:41,0.083008,0.0005,4.1504e-05
2026-08-12 22:01:46,0.057373,0.0005,2.86865e-05
2026-08-12 22:01:51,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:01:57,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:02:02,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:02:07,0.062256,0.0005,3.1128e-05
2026-08-12 22:02:12,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:02:04,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:02:09,0.073242,0.0005,3.6621e-05
2026-08-12 22:02:14,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:02:19,0.057373,0.0005,2.86865e-05
2026-08-12 22:02:25,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:02:30,0.075684,0.0005,3.7842e-05
2026-08-12 22:02:35,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:02:40,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:02:45,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:02:50,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:02:56,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:03:01,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:03:06,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:03:11,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:03:16,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:03:21,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:03:27,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:03:32,0.068359,0.0005,3.41795e-05
2026-08-12 22:03:37,0.057373,0.0005,2.86865e-05
2026-08-12 22:03:42,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:03:47,0.068359,0.0005,3.41795e-05
2026-08-12 22:03:52,0.068359,0.0005,3.41795e-05
2026-08-12 22:03:58,0.043945,0.0005,2.19725e-05
2026-08-12 22:04:08,0.062256,0.0005,3.1128e-05
2026-08-12 22:04:13,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:04:18,0.065918,0.0005,3.2959e-05
2026-08-12 22:04:23,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:04:29,0.062256,0.0005,3.1128e-05
2026-08-12 22:04:34,0.065918,0.0005,3.2959e-05
2026-08-12 22:04:39,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:04:44,0.062256,0.0005,3.1128e-05
2026-08-12 22:04:49,0.056152,0.0005,2.8076e-05
2026-08-12 22:04:55,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:05:00,0.068359,0.0005,3.41795e-05
2026-08-12 22:05:05,0.068359,0.0005,3.41795e-05
2026-08-12 22:05:10,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:05:15,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:05:20,0.084229,0.0005,4.21145e-05
2026-08-12 22:05:25,0.073242,0.0005,3.6621e-05
2026-08-12 22:05:31,0.068359,0.0005,3.41795e-05
2026-08-12 22:05:36,0.068359,0.0005,3.41795e-05
2026-08-12 22:05:41,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:05:46,0.068359,0.0005,3.41795e-05
2026-08-12 22:05:51,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:05:56,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:06:02,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:06:07,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:06:12,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:06:17,0.058594,0.0005,2.9297e-05
2026-08-12 22:06:22,0.083008,0.0005,4.1504e-05
2026-08-12 22:06:28,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:06:33,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:06:38,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:06:43,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:06:48,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:06:53,0.068359,0.0005,3.41795e-05
2026-08-12 22:06:59,0.068359,0.0005,3.41795e-05
2026-08-12 22:07:04,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:07:09,0.073242,0.0005,3.6621e-05
2026-08-12 22:07:14,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:07:19,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:07:25,0.068359,0.0005,3.41795e-05
2026-08-12 22:07:30,0.068359,0.0005,3.41795e-05
2026-08-12 22:07:35,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:07:40,0.068359,0.0005,3.41795e-05
2026-08-12 22:07:45,0.084229,0.0005,4.21145e-05
2026-08-12 22:07:50,0.068359,0.0005,3.41795e-05
2026-08-12 22:08:01,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:08:06,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:08:11,0.068359,0.0005,3.41795e-05
2026-08-12 22:08:16,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:08:21,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:08:32,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:08:37,0.068359,0.0005,3.41795e-05
2026-08-12 22:08:42,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:08:47,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:08:52,0.084229,0.0005,4.21145e-05
2026-08-12 22:08:57,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:09:03,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:09:08,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:09:13,0.065918,0.0005,3.2959e-05
2026-08-12 22:09:18,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:09:23,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:09:28,0.068359,0.0005,3.41795e-05
2026-08-12 22:09:34,0.068359,0.0005,3.41795e-05
2026-08-12 22:09:39,0.068359,0.0005,3.41795e-05
2026-08-12 22:09:44,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:09:49,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:09:54,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:09:59,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:10:29,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:10:40,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:10:45,0.083008,0.0005,4.1504e-05
2026-08-12 22:10:50,0.068359,0.0005,3.41795e-05
2026-08-12 22:10:55,0.075684,0.0005,3.7842e-05
2026-08-12 22:11:00,0.068359,0.0005,3.41795e-05
2026-08-12 22:11:05,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:11:10,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:11:16,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:11:21,0.068359,0.0005,3.41795e-05
2026-08-12 22:11:26,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:11:31,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:11:36,0.085449,0.0005,4.27245e-05
2026-08-12 22:11:46,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:11:52,0.068359,0.0005,3.41795e-05
2026-08-12 22:11:57,0.068359,0.0005,3.41795e-05
2026-08-12 22:12:02,0.068359,0.0005,3.41795e-05
2026-08-12 22:12:07,0.068359,0.0005,3.41795e-05
2026-08-12 22:12:12,0.063477,0.0005,3.17385e-05
2026-08-12 22:12:17,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:12:22,0.075684,0.0005,3.7842e-05
2026-08-12 22:12:27,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:12:33,0.08667,0.0005,4.3335e-05
2026-08-12 22:12:38,0.068359,0.0005,3.41795e-05
2026-08-12 22:12:43,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:12:48,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:12:53,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:12:58,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:13:03,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:13:09,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:13:14,0.062256,0.0005,3.1128e-05
2026-08-12 22:13:19,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:13:24,0.063477,0.0005,3.17385e-05
2026-08-12 22:13:29,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:13:34,0.065918,0.0005,3.2959e-05
2026-08-12 22:13:39,0.068359,0.0005,3.41795e-05
2026-08-12 22:13:45,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:13:50,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:13:55,0.073242,0.0005,3.6621e-05
2026-08-12 22:14:00,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:14:05,0.073242,0.0005,3.6621e-05
2026-08-12 22:14:10,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:14:15,0.068359,0.0005,3.41795e-05
2026-08-12 22:14:21,0.070801,0.0005,3.54005e-05
2026-08-12 22:14:26,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:14:31,0.062256,0.0005,3.1128e-05
2026-08-12 22:14:36,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:14:41,0.047607,0.0005,2.38035e-05
2026-08-12 22:14:46,0.070801,0.0005,3.54005e-05
2026-08-12 22:14:51,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:14:57,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:15:02,0.068359,0.0005,3.41795e-05
2026-08-12 22:15:12,0.068359,0.0005,3.41795e-05
2026-08-12 22:15:17,0.068359,0.0005,3.41795e-05
2026-08-12 22:15:22,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:15:27,0.068359,0.0005,3.41795e-05
2026-08-12 22:15:33,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:15:38,0.073242,0.0005,3.6621e-05
2026-08-12 22:15:43,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:15:48,0.061035,0.0005,3.05175e-05
2026-08-12 22:15:53,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:15:58,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:16:04,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:16:09,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:16:14,0.068359,0.0005,3.41795e-05
2026-08-12 22:16:19,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:16:24,0.084229,0.0005,4.21145e-05
2026-08-12 22:16:29,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:16:56,0.068359,0.0005,3.41795e-05
2026-08-12 22:17:01,0.070801,0.0005,3.54005e-05
2026-08-12 22:17:06,0.083008,0.0005,4.1504e-05
2026-08-12 22:17:11,0.08667,0.0005,4.3335e-05
2026-08-12 22:17:17,0.070801,0.0005,3.54005e-05
2026-08-12 22:17:22,0.070801,0.0005,3.54005e-05
2026-08-12 22:17:27,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:17:36,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:17:41,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:17:47,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:17:52,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:17:57,0.08667,0.0005,4.3335e-05
2026-08-12 22:18:02,0.068359,0.0005,3.41795e-05
2026-08-12 22:18:07,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:18:12,0.045166,0.0005,2.2583e-05
2026-08-12 22:18:17,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:18:23,0.058594,0.0005,2.9297e-05
2026-08-12 22:18:28,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:18:33,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:18:38,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:18:43,0.065918,0.0005,3.2959e-05
2026-08-12 22:18:48,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:18:53,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:19:22,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:19:32,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:19:37,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:19:42,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:19:48,0.070801,0.0005,3.54005e-05
2026-08-12 22:19:53,0.068359,0.0005,3.41795e-05
2026-08-12 22:19:58,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:20:03,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:20:08,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:20:13,0.075684,0.0005,3.7842e-05
2026-08-12 22:20:18,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:20:24,0.065918,0.0005,3.2959e-05
2026-08-12 22:20:29,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:20:34,0.068359,0.0005,3.41795e-05
2026-08-12 22:20:39,0.065918,0.0005,3.2959e-05
2026-08-12 22:20:44,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:20:49,0.068359,0.0005,3.41795e-05
2026-08-12 22:20:54,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:21:00,0.083008,0.0005,4.1504e-05
2026-08-12 22:21:05,0.068359,0.0005,3.41795e-05
2026-08-12 22:21:10,0.070801,0.0005,3.54005e-05
2026-08-12 22:21:15,0.073242,0.0005,3.6621e-05
2026-08-12 22:21:20,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:21:25,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:21:30,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:21:36,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:21:41,0.068359,0.0005,3.41795e-05
2026-08-12 22:21:46,0.068359,0.0005,3.41795e-05
2026-08-12 22:21:51,0.068359,0.0005,3.41795e-05
2026-08-12 22:21:56,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:22:01,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:22:06,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:22:11,0.065918,0.0005,3.2959e-05
2026-08-12 22:22:17,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:22:22,0.083008,0.0005,4.1504e-05
2026-08-12 22:22:27,0.085449,0.0005,4.27245e-05
2026-08-12 22:22:32,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:22:37,0.073242,0.0005,3.6621e-05
2026-08-12 22:22:42,0.068359,0.0005,3.41795e-05
2026-08-12 22:22:47,0.068359,0.0005,3.41795e-05
2026-08-12 22:22:53,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:22:58,0.062256,0.0005,3.1128e-05
2026-08-12 22:23:03,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:23:08,0.065918,0.0005,3.2959e-05
2026-08-12 22:23:13,0.08667,0.0005,4.3335e-05
2026-08-12 22:23:18,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:23:23,0.068359,0.0005,3.41795e-05
2026-08-12 22:23:28,0.065918,0.0005,3.2959e-05
2026-08-12 22:23:34,0.08667,0.0005,4.3335e-05
2026-08-12 22:23:39,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:23:44,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:23:49,0.063477,0.0005,3.17385e-05
2026-08-12 22:23:54,0.070801,0.0005,3.54005e-05
2026-08-12 22:23:59,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:24:05,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:24:10,0.068359,0.0005,3.41795e-05
2026-08-12 22:24:15,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:24:20,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:24:25,0.08667,0.0005,4.3335e-05
2026-08-12 22:24:30,0.065918,0.0005,3.2959e-05
2026-08-12 22:24:35,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:24:40,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:24:46,0.073242,0.0005,3.6621e-05
2026-08-12 22:24:51,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:24:56,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:25:01,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:25:06,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:25:11,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:25:16,0.070801,0.0005,3.54005e-05
2026-08-12 22:25:22,0.075684,0.0005,3.7842e-05
2026-08-12 22:25:27,0.070801,0.0005,3.54005e-05
2026-08-12 22:25:32,0.083008,0.0005,4.1504e-05
2026-08-12 22:25:37,0.070801,0.0005,3.54005e-05
2026-08-12 22:25:42,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:25:47,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:25:58,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:26:03,0.070801,0.0005,3.54005e-05
2026-08-12 22:26:08,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:26:13,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:26:18,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:26:23,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:26:29,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:26:34,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:26:39,0.084229,0.0005,4.21145e-05
2026-08-12 22:26:44,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:26:49,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:26:54,0.070801,0.0005,3.54005e-05
2026-08-12 22:27:04,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:27:10,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:27:15,0.073242,0.0005,3.6621e-05
2026-08-12 22:27:20,0.08667,0.0005,4.3335e-05
2026-08-12 22:27:25,0.073242,0.0005,3.6621e-05
2026-08-12 22:27:30,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:27:35,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:27:40,0.075684,0.0005,3.7842e-05
2026-08-12 22:27:46,0.070801,0.0005,3.54005e-05
2026-08-12 22:27:51,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:27:56,0.08667,0.0005,4.3335e-05
2026-08-12 22:28:01,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:28:06,0.083008,0.0005,4.1504e-05
2026-08-12 22:28:11,0.073242,0.0005,3.6621e-05
2026-08-12 22:28:16,0.087891,0.0005,4.39455e-05
2026-08-12 22:28:22,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:28:27,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:28:32,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:28:37,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:28:42,0.070801,0.0005,3.54005e-05
2026-08-12 22:28:47,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:28:52,0.070801,0.0005,3.54005e-05
2026-08-12 22:28:58,0.075684,0.0005,3.7842e-05
2026-08-12 22:29:03,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:29:08,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:29:13,0.08667,0.0005,4.3335e-05
2026-08-12 22:29:18,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:29:23,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:29:29,0.070801,0.0005,3.54005e-05
2026-08-12 22:29:34,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:29:39,0.085449,0.0005,4.27245e-05
2026-08-12 22:29:44,0.068359,0.0005,3.41795e-05
2026-08-12 22:29:49,0.070801,0.0005,3.54005e-05
2026-08-12 22:29:54,0.070801,0.0005,3.54005e-05
2026-08-12 22:29:59,0.089111,0.0005,4.45555e-05
2026-08-12 22:30:04,0.073242,0.0005,3.6621e-05
2026-08-12 22:30:09,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:30:15,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:30:20,0.070801,0.0005,3.54005e-05
2026-08-12 22:30:25,0.08667,0.0005,4.3335e-05
2026-08-12 22:30:30,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:30:35,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:30:40,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:30:46,0.068359,0.0005,3.41795e-05
2026-08-12 22:30:51,0.068359,0.0005,3.41795e-05
2026-08-12 22:30:56,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:31:01,0.070801,0.0005,3.54005e-05
2026-08-12 22:31:06,0.087891,0.0005,4.39455e-05
2026-08-12 22:31:11,0.068359,0.0005,3.41795e-05
2026-08-12 22:31:16,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:31:21,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:31:27,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:31:32,0.073242,0.0005,3.6621e-05
2026-08-12 22:31:37,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:31:42,0.070801,0.0005,3.54005e-05
2026-08-12 22:31:47,0.068359,0.0005,3.41795e-05
2026-08-12 22:31:53,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:31:58,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:32:03,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:32:08,0.070801,0.0005,3.54005e-05
2026-08-12 22:32:13,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:32:18,0.083008,0.0005,4.1504e-05
2026-08-12 22:32:23,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:32:28,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:32:33,0.073242,0.0005,3.6621e-05
2026-08-12 22:32:39,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:32:44,0.063477,0.0005,3.17385e-05
2026-08-12 22:32:49,0.065918,0.0005,3.2959e-05
2026-08-12 22:32:54,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:32:59,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:33:04,0.08667,0.0005,4.3335e-05
2026-08-12 22:33:09,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:33:15,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:33:20,0.068359,0.0005,3.41795e-05
2026-08-12 22:33:25,0.070801,0.0005,3.54005e-05
2026-08-12 22:33:30,0.085449,0.0005,4.27245e-05
2026-08-12 22:33:35,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:33:40,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:33:45,0.063477,0.0005,3.17385e-05
2026-08-12 22:33:51,0.068359,0.0005,3.41795e-05
2026-08-12 22:33:56,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:34:01,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:34:06,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:34:11,0.068359,0.0005,3.41795e-05
2026-08-12 22:34:16,0.070801,0.0005,3.54005e-05
2026-08-12 22:34:21,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:34:27,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:34:32,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:34:37,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:34:42,0.068359,0.0005,3.41795e-05
2026-08-12 22:34:47,0.075684,0.0005,3.7842e-05
2026-08-12 22:34:52,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:34:57,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:35:03,0.062256,0.0005,3.1128e-05
2026-08-12 22:35:08,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:35:13,0.042725,0.0005,2.13625e-05
2026-08-12 22:35:18,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:35:23,0.081787,0.0005,4.08935e-05
2026-08-12 22:35:28,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:35:33,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:35:38,0.081787,0.0005,4.08935e-05
2026-08-12 22:35:44,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:35:49,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:35:54,0.087891,0.0005,4.39455e-05
2026-08-12 22:35:59,0.064697,0.0005,3.2348500000000004e-05
2026-08-12 22:36:04,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:36:09,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:36:14,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:36:20,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:36:25,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:36:30,0.076904,0.0005,3.8452000000000004e-05
2026-08-12 22:36:35,0.067139,0.0005,3.3569500000000004e-05
2026-08-12 22:36:40,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:36:45,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:36:50,0.073242,0.0005,3.6621e-05
2026-08-12 22:36:56,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:37:01,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:37:06,0.070801,0.0005,3.54005e-05
2026-08-12 22:37:11,0.089111,0.0005,4.45555e-05
2026-08-12 22:37:16,0.081787,0.0005,4.08935e-05
2026-08-12 22:37:21,0.074463,0.0005,3.7231500000000004e-05
2026-08-12 22:37:26,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:37:32,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:37:37,0.06958,0.0005,3.4790000000000004e-05
2026-08-12 22:38:08,0.070801,0.0005,3.54005e-05
2026-08-12 22:40:54,0.084229,0.0005,4.21145e-05
2026-08-12 22:41:00,0.072021,0.0005,3.6010500000000004e-05
2026-08-12 22:41:05,0.081787,0.0005,4.08935e-05
````
