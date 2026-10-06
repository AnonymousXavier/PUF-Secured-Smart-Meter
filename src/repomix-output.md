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
