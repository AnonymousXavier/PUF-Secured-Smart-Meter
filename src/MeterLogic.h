#pragma once

#include <Arduino.h>

void setup_meter();
void setup_load();

float get_load_value();
void update_buzzer(float units, float balance, bool relay_is_on);