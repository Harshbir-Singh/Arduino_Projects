#include<Servo.h>
int servoPin = 9;
int servoPos;
int pin = 8;
int Vout = A0;
int Vread;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin,HIGH);
Vread = analogRead(Vout);
Serial.println(Vread);
if(Vread>130 && Vread<160){
  servoPos = 180;
} 

else if(Vread>200){
  servoPos = 0;
} 

else if(Vread<80){
  servoPos = 90;
} 
myServo.write(servoPos);
}
