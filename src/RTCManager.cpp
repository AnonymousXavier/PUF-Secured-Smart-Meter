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
