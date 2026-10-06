import streamlit as st
import psycopg2
import pandas as pd
import time
import warnings

# ==========================================
# 1. PAGE CONFIGURATION
# ==========================================
st.set_page_config(page_title="Utility Consumer Portal", page_icon="💳", layout="centered")

st.title("💳 Utility Vending Portal")
st.write("Welcome! Enter your Meter ID to securely check your balance and purchase units.")

# ==========================================
# 2. AUTHENTICATION & OVERVIEW
# ==========================================
meter_id = st.text_input("Enter Meter ID", value="1")

if meter_id:
    try:
        # Connect to the PostgreSQL database
        pg_conn = psycopg2.connect("dbname=smart_meter_db user=postgres password=Xav@2007ier host=localhost port=5432")
        
        # Query the specific meter
        query = f"SELECT balance_ngn, total_kwh, tariff_rate FROM virtual_wallets WHERE device_id = {meter_id}"
        
        with warnings.catch_warnings():
            warnings.simplefilter("ignore", UserWarning)
            wallet_df = pd.read_sql_query(query, pg_conn)

        if not wallet_df.empty:
            current_balance = float(wallet_df.iloc[0]['balance_ngn'])
            total_units = float(wallet_df.iloc[0]['total_kwh'])
            tariff = float(wallet_df.iloc[0]['tariff_rate'])
            
            available_units = current_balance / tariff if tariff > 0 else 0.0

            st.success(f"Meter ID {meter_id} Authenticated securely.")
            
            # --- ACCOUNT OVERVIEW ---
            st.divider()
            st.subheader("Account Overview")
            
            col1, col2 = st.columns(2)
            col1.metric("Available Power", f"{available_units:.4f} kWh")
            col2.metric("Wallet Balance", f"₦ {current_balance:,.2f}")
            
            st.caption(f"Lifetime Consumed: {total_units:.4f} kWh | Current Tariff: ₦{tariff}/kWh")
            
            # --- VENDING STATION ---
            st.divider()
            st.subheader("Top-Up Units")
            
            topup_amount = st.number_input("Amount (₦)", min_value=100.0, step=100.0, value=1000.0)
            preview_units = topup_amount / tariff
            
            st.info(f"You are purchasing: **{preview_units:.2f} kWh**")
            
            if st.button("⚡ Proceed to Payment", type="primary", use_container_width=True):
                # Process the transaction
                vend_cursor = pg_conn.cursor()
                vend_cursor.execute("UPDATE virtual_wallets SET balance_ngn = balance_ngn + %s WHERE device_id = %s", (topup_amount, meter_id))
                pg_conn.commit()
                vend_cursor.close()
                
                # Visual feedback
                st.balloons()
                st.success(f"Payment Successful! ₦{topup_amount:,.2f} has been added to Meter {meter_id}.")
                time.sleep(2) # Give the user time to read the success message
                st.rerun()
                
        else:
            st.error("Meter ID not found in the utility database.")
            
        pg_conn.close()
        
    except Exception as e:
        st.error(f"Database Connection Error: {e}")