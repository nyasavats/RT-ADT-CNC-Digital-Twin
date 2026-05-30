const int sensorPin = A0;
const float zeroCurrentVoltage = 2.5;  //needs adjustment as per your actual reading
const float sensitivity = 0.066;        

void setup() {
  Serial.begin(9600);
  Serial.println("Current Sensor - Ready!");
}

void loop() {
  int rawValue = analogRead(sensorPin);
  float voltage = (rawValue / 1024.0) * 5.0;
  float current = (voltage - zeroCurrentVoltage) / sensitivity;
  Serial.print("Voltage: ");
  Serial.print(voltage, 3);
  Serial.print("V | Current: ");
  Serial.print(current, 2);
  Serial.println("A");
  delay(500);
}
