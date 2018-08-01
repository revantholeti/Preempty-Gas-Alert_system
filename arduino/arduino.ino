#include<HX711.h>
#include<SoftwareSerial.h>
#define DOUT  3
#define CLK  2
HX711 scale(DOUT,CLK);
SoftwareSerial mySerial(9,10);
float calibration_factor = -96650;  //-106600
void setup() 
{
  mySerial.begin(9600);
  Serial.begin(9600);  
  scale.set_scale(-96650);  
  scale.tare();               
}
void loop() 
{
  Serial.print("Weight: ");
  Serial.print(scale.get_units(),3);  
  Serial.println(" kg"); 
  float weight=scale.get_units();
  if(weight==3)
  {
    if (Serial.available()>0)
      {
        SendMessage();
        break;
      }
  }
}
void SendMessage()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000); 
  mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
  delay(1000);
  mySerial.println("warining!!!!!!!!!!");
  delay(100);
   mySerial.println((char)26);
  delay(1000);
}
