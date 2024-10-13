#include <Servo.h>
Servo myservo;    

void setup() {
  myservo.attach(A3);  
}  

void loop() {
myservo.write(90);             
    delay(1500);                    
  myservo.write(0);              
    delay(1500);                     
  
}
