#include <Servo.h>
Servo ag90;
#include <LiquidCrystal.h>
LiquidCrystal lcd (12 ,11 ,5 ,4 ,3 ,2);

int esikDegeri = 100;
int sensorPin = A0;
#define buzzerPin 8
int C = 262;
int D = 294;
int E = 330;
int F = 349;
int G = 392;
int A = 440;
int B = 494;
int C_ = 523;
int veri;
void setup() {
  ag90.attach(6);
  ag90.write(0);
  pinMode(buzzerPin ,OUTPUT);
lcd.begin(16, 2);
}

void loop() {
  veri = analogRead(sensorPin);
lcd.print("veri:");
lcd.setCursor(0, 0);
lcd.print(veri);
  if(veri > esikDegeri){
    ag90.write(180);
  tone(buzzerPin ,C);
 
  delay(100);
 noTone(buzzerPin);
  delay(100);
 }else{if(veri < esikDegeri);
  
  ag90.write(0); }

 
}
