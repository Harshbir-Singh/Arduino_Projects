#include<Servo.h>
int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int Xval;
int Yval;
int Sval;
int servoPin = 8;
int servoPos;
int buzzPin = 9;

Servo myServo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Xpin,INPUT);
pinMode(Ypin,INPUT);
pinMode(Spin,INPUT);
pinMode(buzzPin,OUTPUT);
digitalWrite(Spin,HIGH);
myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
Xval = analogRead(Xpin);
Yval = analogRead(Ypin);
Sval = digitalRead(Spin);

Serial.print("X = ");
Serial.print(Xval);
Serial.print(" Y =");
Serial.print(Yval);
Serial.print(" S = ");
Serial.println(Sval);
servoPos = (180./1023.)*Xval;
if(Sval!=1){
  digitalWrite(buzzPin,HIGH);
}
else{
  digitalWrite(buzzPin,LOW);
}
myServo.write(servoPos);
}
