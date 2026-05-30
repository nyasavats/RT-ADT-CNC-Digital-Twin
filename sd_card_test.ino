#include <SD.h>
#include <SPI.h>

const int chipSelect = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting SD card test...");
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card failed!");
    return;
  }
  Serial.println("SD card ready!");
  File myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("Hello from Arduino!");
    myFile.close();
    Serial.println("Data written successfully!");
  }
}

void loop() {

}
