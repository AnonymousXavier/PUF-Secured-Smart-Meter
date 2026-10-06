#include "CaptivePortal.h"
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <LittleFS.h>

#include "NetworkingModule.h"
#include "RTCManager.h"


const byte DNS_PORT = 53;
DNSServer dnsServer;
WebServer server(80);

void setup_portal() {
  // 1. Enable dual mode: Station (Client to Python) + Access Point (For Phones)
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("Smart Meter");

  // 2. Start DNS Server to hijack all requests and route to the ESP32's AP IP
  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

  // 3. Serve the HTML dashboard when a user connects (The Captive Portal Trigger)
  server.onNotFound([]() {
    if (LittleFS.exists("/portal.html")) {
      File file = LittleFS.open("/portal.html", "r");
      server.streamFile(file, "text/html");
      file.close();
    } else {
      server.send(200, "text/plain", "Dashboard missing from flash memory! Upload LittleFS image.");
    }
  });

  // 4. Handle the Configuration form submission
  server.on("/config", HTTP_GET, []() {
    // Extract ALL the variables from the URL
    String new_ssid = server.arg("wifi_ssid");
    String new_pass = server.arg("wifi_password");
    String new_ip = server.arg("server_ip");
    String new_port = server.arg("server_port"); // <--- MISSING THIS LINE
    String new_time = server.arg("rtc_time"); 
    
    Serial.println("--- NEW CONFIGURATION RECEIVED ---");
    Serial.println("WiFi SSID: " + new_ssid);
    Serial.println("Target Server IP: " + new_ip);
    Serial.println("Target Server Port: " + new_port); // <--- Add this print to check it
    Serial.println("----------------------------------");

    // Pass the NEW PORT to the hardware!
    update_network_config(new_ssid, new_pass, new_ip, new_port); // <--- ADD new_port HERE
    update_rtc_time(new_time);

    String htmlResponse = "<h2>Configuration Saved!</h2>";
    htmlResponse += "<p>Network: " + new_ssid + "</p>";
    htmlResponse += "<p>IP updated to: " + new_ip + ":" + new_port + "</p>";
    htmlResponse += "<br><a href='/'>Return to Dashboard</a>";
    
    server.send(200, "text/html", htmlResponse);
  });

  server.begin();
  Serial.println("Captive Portal Started. Connect to 'Smart Meter'");
}

void handle_portal() {
  dnsServer.processNextRequest();
  server.handleClient();
}
