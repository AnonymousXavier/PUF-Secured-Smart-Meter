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


