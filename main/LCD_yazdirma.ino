#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
 lcd.clear();
lcd.begin(16, 2);
lcd.print("ANNEMI SEVIYORUM");
delay(2000);
lcd.clear();
lcd.begin(16, 2);
lcd.print("BABAMI SEVIYORUM");
delay(2000);
lcd.clear();
lcd.begin(16, 2);
lcd.print("ABIMI SEVIYORUM");
delay(2000);
lcd.clear();
lcd.print("AILEMI SEVIYORUM");
lcd.setCursor(0, 1);
lcd.print("HEM DE COK");
}

void loop() {
 
 
}
