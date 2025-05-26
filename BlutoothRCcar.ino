#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

int trigPin = A1;
int echoPin = A2;
int pingTravelTime;
int distance;
int finalD;

int buzzPin = A3;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;

void setup()
{
  Serial.begin(9600);
  bluetoothSerial.begin(9600);  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzPin,INPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTravelTime = pulseIn(echoPin,HIGH);


  distance = (pingTravelTime*765.*5280*12)/(3600.*1000000);
  finalD = distance/2;
  Serial.print("Distance(in inches): ");
  Serial.println(finalD);
  

  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    Stop(); 
    
    switch (command) {
      case 'F':
        if(finalD<10 && finalD>0){
          Stop();
        }
        else{
          forward();
        }
        
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
    
  }
  
  if(finalD<10 and finalD >0){
    analogWrite(buzzPin,255);
  } 
  else{
    analogWrite(buzzPin,0);
  }
  }
  

void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void right()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void Stop()
{
  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); 
}
