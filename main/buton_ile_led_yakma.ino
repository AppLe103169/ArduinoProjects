#define Buton 8
#define Led 10
#define Buton2 9

void setup() {
   pinMode(Buton, INPUT);
  pinMode(Led, OUTPUT);
pinMode(Buton2, INPUT);
}

void loop() {
  if (digitalRead(Buton) == 1)
  digitalWrite(Led,HIGH);
if (digitalRead(Buton2) == 1)
 digitalWrite(Led,LOW);



}
