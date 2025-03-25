#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int start;
float FirstNum;
float SecondNum;
float Ans;

String op;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
Serial.println("Enter 1 to use the calculator, else enter any number to stop");
while (Serial.available()==0){

}
start = Serial.parseInt();


if (start == 1){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("First Number:");
  Serial.println("First Number");
  while (Serial.available()==0){

  }
  FirstNum = Serial.parseFloat();

  
  lcd.setCursor(0,1);
  lcd.print(FirstNum);
  ;
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Second Number:");
  Serial.println("Second Number");
  while (Serial.available()==0){
  }
  
  SecondNum = Serial.parseFloat();
  lcd.setCursor(0,1);
  lcd.print(SecondNum);
  
  
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Select'+,-,/,*'");
  Serial.println("Select operator'+,-,/,*'");
  while (Serial.available()==0){
  }
  
  op = Serial.readString();
  lcd.setCursor(0,1);
  lcd.print(op);

  
  if(op == "+"){
    Ans = FirstNum + SecondNum;
    
    
  }
  else if(op == "-"){
    Ans = FirstNum-SecondNum;
    
  }
  else if(op == "/"){
    
    
      Ans = FirstNum/SecondNum;
      
    
  }
  else if(op == "*"){
    Ans = FirstNum*SecondNum;
    
  }
  
if(SecondNum==0 && op=="/"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ZeroDivisionError");
    }
else if(op!="+" && op!="-" && op !="/" && op !="*"){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error");
}
else{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(FirstNum);
  lcd.print(op);
  lcd.print(SecondNum);
  lcd.print("=");
  lcd.print(Ans);
}
}
else{
  lcd.clear();
  
}

}