#pragma once
#include <Arduino.h>

struct SystemState {
    String IP;
    bool isWifiConnected;
    bool isServerOnline;
    String totalPowerUsed;
    unsigned long offlineDownTime;
    // --- NEW FIELDS ---
    float availableUnits;
    bool isRelayOn;
};