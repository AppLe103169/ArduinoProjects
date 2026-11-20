#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
pinMode(A0 ,INPUT);  
Serial.begin(9600);
}

void loop() {
  float topNem=analogRead(A0);
Serial.print("nem değeri");
lcd.begin(16, 2); 
Serial.print(topNem);
 
  delay(200);
}
