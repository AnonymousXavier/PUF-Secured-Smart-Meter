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
