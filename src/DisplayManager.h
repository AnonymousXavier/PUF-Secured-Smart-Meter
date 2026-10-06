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