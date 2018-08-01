#include "HX711.h"
#include <SoftwareSerial.h>
SoftwareSerialmySerial(9,10);
HX711 scale(A1,A0);
void setup()
{
mySerial.begin(9600);
Serial.begin(9600);
delay(100);
Serial.println("HX711 Demo");
scale.set_scale(415.f);
scale.tare();
Serial.print("read:");
Serial.println(scale.read());
Serial.print("read average:");
Serial.println(scale.read_average(20));
Serial.println("Readings:");
}
void loop()
{
Serial.print("average(weight):");
Serial.print(scale.get_units(10),1);
if(scale.get_units(10)==3000)
{
SendMessage();
}
Serial.println("  gram");
delay(500);
}
void SendMessage()
{
mySerial.println("AT+CMGF=1");
delay(1000);
mySerial.println("AT+CMGS=\"+91805624042005\"\r");
delay(1000);
mySerial.println("it is a warining");
delay(100);
mySerial.println((char)26);
delay(1000);
}