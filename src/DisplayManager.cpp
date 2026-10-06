#include "DisplayManager.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int LCD_SDA_PIN = 8;
const int LCD_SCL_PIN = 9;
const int BTN_PIN = 4;

DISPLAY_STATES lcd_state = CONNECTING_TO_WIFI;

String text_top;
String text_bottom; 

bool is_btn_held = false;

void setup_lcd(){
  pinMode(BTN_PIN, OUTPUT);
  Wire.begin(LCD_SDA_PIN, LCD_SCL_PIN);

  lcd.init();
  lcd.backlight();
}

void update_lcd(SystemState systemState){
  if (digitalRead(BTN_PIN) == HIGH){
    if (!is_btn_held) {
      lcd_state = static_cast<DISPLAY_STATES>((lcd_state + 1) % COUNT);
      is_btn_held = true;
    }
  } else {
    is_btn_held = false;
  }

    switch (lcd_state) {
    case CONNECTING_TO_WIFI:
        if (!systemState.isWifiConnected) {
          // No WiFi = definitely no server
          lcd_print_text("WiFi: Connecting", "Server: Offline "); 
        } else {
          // WiFi is connected! Show the IP on top.
          String topText = systemState.IP;
          
          // Check server status for the bottom row
          String bottomText = systemState.isServerOnline ? "Server: Online " : "Server: Offline ";
          
          lcd_print_text(topText, bottomText);
        }
        break;
    case POWER_USAGE:
        if (systemState.isRelayOn) {
            // Row 1: Live Power
            String pwr_str = "PWR: " + systemState.totalPowerUsed;
            
            // Row 2: Available Units 
            String bal_str = "BAL: " + String(systemState.availableUnits, 4) + " kWh";
            
            lcd_print_text(pwr_str, bal_str);
        } else {
            lcd_print_text("FUNDS EXHAUSTED!", "RELAY DISABLED");
        }
        break;
    case OFFLINE_DOWN_TIME:
        lcd_print_text("BEEN OFFLINE FOR", get_time_info_from_ms(systemState.offlineDownTime));
        break;
    }
}

String get_time_info_from_ms(unsigned long ms_passed){
  char timeString[20]; // Increased buffer size for safety

  // Calculate total units
  unsigned long total_secs = ms_passed / 1000;
  
  // Use modulo (%) to get the remaining parts
  short secs  = total_secs % 60;
  short mins  = (total_secs / 60) % 60;
  short hours = (total_secs / 3600) % 24;
  short days  = total_secs / 86400;

  // Combine into a single format string
  sprintf(timeString, "%02dd %02dh %02dm %02ds", days, hours, mins, secs);

  return String(timeString);
}


void lcd_print_text(const String &text_top, const String &text_bottom){
  const int LCD_COLS = 16; // Change to 20 if using a 20x4 display

  // Process top line
  String padded_top = text_top;
  while(padded_top.length() < LCD_COLS) {
    padded_top += " ";
  }
  lcd.setCursor(0, 0);
  lcd.print(padded_top);

  // Process bottom line
  String padded_bottom = text_bottom;
  while(padded_bottom.length() < LCD_COLS) {
    padded_bottom += " ";
  }
  lcd.setCursor(0, 1);
  lcd.print(padded_bottom);
}
