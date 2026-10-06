#include "MeterLogic.h"

const int POTENTIOMETER_PIN = 17;
const int RELAY_PIN = 18; 
const int BUZZER_PIN = 16;

// Standard 5V relays are usually Active-Low, meaning LOW turns them ON.
const int RELAY_ON = LOW; 
const int RELAY_OFF = HIGH;

int load_consumed;

void setup_meter(){
    setup_load();
    
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, RELAY_OFF); // Default to off until server authorizes

    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);      // Default buzzer silent
}

void setup_load() {
    pinMode(POTENTIOMETER_PIN, INPUT);
}

float get_load_value(){
    int sensorValue = analogRead(POTENTIOMETER_PIN);
    float factor = (sensorValue / 4096.0);
    return factor;
}

void update_relay(bool enable) {
    if (enable) {
        digitalWrite(RELAY_PIN, RELAY_ON);
    } else {
        digitalWrite(RELAY_PIN, RELAY_OFF);
    }
}

void update_buzzer(float units, float balance, bool relay_is_on) {
    unsigned long currentMillis = millis();
    static int lastToneFreq = -1; // Tracks current state to prevent PWM resetting
    int targetFreq = 0;
    
    if (balance <= 0.0 || !relay_is_on) {
        // STATE 2: Fully Exhausted / Cutoff (Long pulsing alarm)
        if ((currentMillis / 1200) % 2 == 0) {
            targetFreq = 4000; // 4kHz piercing tone
        } else {
            targetFreq = 0;
        }
    } 
    else if (units <= 2.0) {
        // STATE 1: Low Balance Warning (<= 2 Units)
        int intervalCycle = currentMillis % 5000;
        if (intervalCycle < 200 || (intervalCycle > 400 && intervalCycle < 600)) {
            targetFreq = 2500; // Warning pitch
        } else {
            targetFreq = 0;
        }
    } 
    else {
        // Normal Operation: Completely silent
        targetFreq = 0;
    }

    // Only update the tone hardware when the target frequency changes
    if (targetFreq != lastToneFreq) {
        if (targetFreq > 0) {
            tone(BUZZER_PIN, targetFreq);
        } else {
            noTone(BUZZER_PIN);
        }
        lastToneFreq = targetFreq;
    }
}