const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("ACS712 Current Sensor Test");
  Serial.println("Voltage readings:");
}

void loop() {
  int rawValue = analogRead(sensorPin);
  float voltage = (rawValue / 1024.0) * 5.0;
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  delay(500);
}
