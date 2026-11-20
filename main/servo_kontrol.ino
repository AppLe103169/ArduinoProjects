#include <Servo.h>
Servo ag90;



void setup() {
  ag90.attach(10);
  ag90.write(0);
  delay(500);
}

void loop() {
ag90.write (0);
delay(1000);
ag90.write(90);
delay(1000);
}
