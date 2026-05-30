#include <SD.h>
#include <SPI.h>

const int chipSelect = 10;
const int currentPin = A0;
const float zeroVoltage = 2.5;      // calliberation needed 
const float sensitivity = 0.066;    // 30A sensor
unsigned long lastSave = 0;
int dataCount = 0;

void setup() {
  Serial.begin(9600);
  if (!SD.begin(chipSelect)) {
    Serial.println("SD FAIL!");
    while(1);
  }
  Serial.println("SD OK!");
  File dataFile = SD.open("current.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Time(ms),Voltage(V),Current(A)");
    dataFile.close();
  }
}

void loop() {
  int raw = analogRead(currentPin);
  float voltage = (raw / 1024.0) * 5.0;
  float current = (voltage - zeroVoltage) / sensitivity;
  unsigned long timestamp = millis();

  if (timestamp - lastSave >= 100) {
    File dataFile = SD.open("current.csv", FILE_WRITE);
    if (dataFile) {
      dataFile.print(timestamp);
      dataFile.print(",");
      dataFile.print(voltage, 3);
      dataFile.print(",");
      dataFile.println(current, 3);
      dataFile.close();
      dataCount++;
      Serial.print(timestamp);
      Serial.print(",");
      Serial.print(voltage, 3);
      Serial.print(",");
      Serial.println(current, 3);
    }
    lastSave = timestamp;
  }
}
