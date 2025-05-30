int pin = 8;
int buzzPin = 9;
int Vout;
int photoPin = A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin,OUTPUT);
pinMode(buzzPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Vout = analogRead(photoPin);
Serial.println(Vout);
digitalWrite(pin,LOW);
if(Vout>500){
  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(200);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(300);

}
else if(Vout>400 && Vout<500){
  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(3000);

}
if(Vout>300 && Vout<400){
  digitalWrite(buzzPin,HIGH);
  delay(1);
  digitalWrite(buzzPin,LOW);
  delay(2);

}
else if(Vout>40 && Vout<300){
  digitalWrite(buzzPin,HIGH);
  delay(3);
  digitalWrite(buzzPin,LOW);
  delay(40);

}
if(Vout<40){
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(200);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(300);

}
}
