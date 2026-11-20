#include <Servo.h>
Servo ag90;
const byte pot_pini =A0;
int pot_deger;
void setup()
{
  
  Serial.begin(9600);
  ag90.attach(3);
}

void loop() {
pot_deger = analogRead(pot_pini);
Serial.println(pot_deger);
int yeni_deger=map(pot_deger , 0,1023,0,180);
ag90.write(yeni_deger);
Serial.print("Aci degeri = ");
Serial.println(yeni_deger);

}
