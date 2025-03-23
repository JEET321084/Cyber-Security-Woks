#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println("Scanning Wi-Fi networks...");
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.println("Networks found:");
    for (int i = 0; i < n; i++) {
      Serial.printf("%d: SSID: %s | BSSID: %02X:%02X:%02X:%02X:%02X:%02X | Signal: %d dBm\n", 
                    i + 1, WiFi.SSID(i).c_str(),
                    WiFi.BSSID(i)[0], WiFi.BSSID(i)[1], WiFi.BSSID(i)[2], 
                    WiFi.BSSID(i)[3], WiFi.BSSID(i)[4], WiFi.BSSID(i)[5],
                    WiFi.RSSI(i));
    }
  }
}

void loop() {}
