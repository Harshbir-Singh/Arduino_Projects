#include <LiquidCrystal.h>
#include <DHT.h>
#define Type DHT11
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;


int sensePin = 2;  
DHT HT(sensePin,Type);  
float humidity;
float tempC;
float tempF;
int setTime = 2000;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
HT.begin();
delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
humidity = HT.readHumidity();
tempC = HT.readTemperature();
tempF = HT.readTemperature(true);

lcd.setCursor(0,0);
lcd.print("Humidity:");
lcd.setCursor(0,1);
lcd.print(humidity);
delay(setTime);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temperature in C:");
lcd.setCursor(0,1);
lcd.print(tempC);
delay(setTime);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temperature in F:");
lcd.setCursor(0,1);
lcd.print(tempF);
delay(setTime);
lcd.clear();

}

