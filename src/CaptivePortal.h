#pragma once

#include <Arduino.h>

void setup_portal();
void handle_portal();
void update_network_config(String new_ssid, String new_pass, String new_ip);
