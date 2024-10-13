#include <Servo.h>
Servo myservo;
const int pingPin = 12; 
const int echoPin = 13; 
int ldr=A0;
int value=0;

void setup() {
   Serial.begin(9600); 
   myservo.attach(9);
   Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  value=analogRead(ldr);

   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);

   if (cm <15)
   {
    myservo.write(90);
    digitalWrite(7,HIGH);
   }
   else{
    myservo.write(0);
    digitalWrite(7,LOW);
   }

   
if(value>300&& cm <15)
  {
    digitalWrite(7,HIGH);
    myservo.write(0);
    digitalWrite(5,HIGH);
   }
   else if (value>300){
    digitalWrite(7,HIGH);
   }
  
  else
  {
    digitalWrite(7,LOW);
    digitalWrite(5,LOW);
  }
 
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}