#include <Servo.h>
Servo ag90;
#define led1 7
#define led2 8

void setup() {
  ag90.attach(3);
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
}

void loop() {
  ag90.write (0);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
    delay(1000);
     digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
  ag90.write (180);
  delay(1000);
ag90.write (0);
 digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
}
