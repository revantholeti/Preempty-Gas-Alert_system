#include <hx711.h>



#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

HX711 scale(A1, A0);    

void setup() {
 
  mySerial.begin(9600);  
  Serial.begin(9600);    
  delay(100);
  Serial.println("HX711 Demo");

  scale.set_scale(415.f); 
  scale.tare(); 

  Serial.print("read: \t\t");
  Serial.println(scale.read()); 
  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20)); 
  
  Serial.println("Readings:");
}

void loop() {
  Serial.print("\t average(weight):\t");
  Serial.print(scale.get_units(10), 1);
  Serial.println("gram");
  
if (scale.get_units(10) == 1000){
    //SendMessage();
    Serial.println("Buy a new ONe");
}
  delay(500);
}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919703831127\"\r"); 
  delay(1000);
  mySerial.println("Cylinder is empty");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);
  delay(1000);
}


