#pragma once

#include <Arduino.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>

void setup_rtc();
String get_current_timestamp();
void update_rtc_time(String datetime);
