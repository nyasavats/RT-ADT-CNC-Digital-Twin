#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_PASSWORD";
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  server.begin();
  Serial.println("WiFi Ready!");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    WiFiClient client = server.available();
    if (client) {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/plain");
      client.println();
      client.println(data);
      client.stop();
    }
  }
}
