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