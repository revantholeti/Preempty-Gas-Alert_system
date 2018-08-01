
#include "HX711.h"
HX711 scale(A1, A0);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("HX711 Demo");
  scale.set_scale(415.f); 
  scale.tare();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\t| one_unit:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:");
  Serial.print(scale.get_units(10), 1);
  Serial.print("\n");
  scale.power_down();              // put the ADC in sleep mode
  delay(3000);
  scale.power_up();
}
