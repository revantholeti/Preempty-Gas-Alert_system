const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;
const int sensorPin4 = A3;
const int photoPin = 4;
const int ledPin = 13;
const int threshold = 110;
char stringToPrint[100];


int startTime,endTime;

int val1,val2,val3,val4;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(sensorPin1,INPUT);
  pinMode(sensorPin2,INPUT);
  pinMode(sensorPin3,INPUT);
  pinMode(sensorPin4,INPUT);
  pinMode(photoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int start = digitalRead(photoPin);
  startTime = millis();
  if(start == HIGH)
    digitalWrite(ledPin,HIGH);
  while(start == LOW)
  {
      digitalWrite(ledPin,LOW);
      val1 = analogRead(sensorPin1);
      val2 = analogRead(sensorPin2);
      val3 = analogRead(sensorPin3);
      val4 = analogRead(sensorPin4);
      //sprintf(stringToPrint,"%d,%d,%d,%d",val1,val2,val3,val4);
      //Serial.println(stringToPrint);
      if((val1 >= threshold) || (val2 >= threshold) || (val3 >= threshold) || (val4 >= threshold))
      {
        endTime = millis();
        sprintf(stringToPrint,"%d ms",endTime - startTime);
        Serial.println(stringToPrint);
        digitalWrite(ledPin,HIGH);
        delay(1000);
        digitalWrite(ledPin,LOW);
        start = HIGH;
      } 
  }
}
