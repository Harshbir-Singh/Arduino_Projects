#include <Stepper.h>
int steps = 2048;
int motorSpeed = 10;
int Vpin = 3;

int VoutOld = 1;
int VoutNew;
int motorState = 0;
Stepper myStepper(steps, 8,10,9,11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motorSpeed);

pinMode(Vpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
VoutNew = digitalRead(Vpin);
Serial.println(VoutNew);
if(VoutNew==0 && VoutOld == 1){
  motorState = motorState*(-1)
}
myStepper.step(motorState*1);
VoutOld = VoutNew;

}
