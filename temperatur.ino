#include <Arduino.h>
#define USE_SERIAL Serial
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int getSensor(){
  int Celcius=0;
  sensors.requestTemperatures();
  Celcius=sensors.getTempCByIndex(0);
  return Celcius;
}

void setup() {
  delay(500); // Let the module self-initialize
  USE_SERIAL.begin(115200);
  for(uint8_t t = 4; t > 0; t--) {
      USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
      USE_SERIAL.flush();
      delay(1000);
  }
}

void loop() {
  delay(1000);
  USE_SERIAL.println(getSensor());
}
