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