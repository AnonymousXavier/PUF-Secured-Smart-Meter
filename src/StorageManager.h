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
