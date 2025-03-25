int pin = 8;
int pinOut1 = 2;
int pinOut2 = 3;
int pinRead1;
int pinRead2;
int led;
int buzzPin = 10;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin,OUTPUT);
pinMode(pinOut1,INPUT);
pinMode(pinOut2,INPUT);
pinMode(buzzPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
pinRead1 = digitalRead(pinOut1);
pinRead2 = digitalRead(pinOut2);
Serial.println(pinRead1);

Serial.println(pinRead2);


if(pinRead1==0){
  led = led+1;
  delay(10);
}
if(pinRead2==0){
  led = led-1;
  delay(10);
}

if(led>255){
  led=255;
  digitalWrite(buzzPin,HIGH);
}

if(led<0){
  led = 0;

}
if(led<255){
  digitalWrite(buzzPin,LOW);
}
Serial.println(led);
analogWrite(pin,led);
}

