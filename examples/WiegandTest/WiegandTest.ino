#include <WiegandMulti.h>

WIEGANDMULTI wg;

void Reader1D0Interrupt(void) {
  wg.ReadD0();
}

void Reader1D1Interrupt(void) {
  wg.ReadD1();
}

void setup() {
  Serial.begin(9600);
  wg.begin(22, 23, Reader1D0Interrupt, Reader1D1Interrupt);
  Serial.print("hello");
}

void loop() {
  if (wg.available()) {
    Serial.print("Wiegand1 HEX = ");
    Serial.print(wg.getCode(), HEX);
    Serial.print(", DECIMAL = ");
    Serial.print(wg.getCode());
    Serial.print(", Type W");
    Serial.println(wg.getWiegandType());
  }
}