int esikDegeri = 400;
int buzzerPin = 9;
int deger;
int C =523;
void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  deger = analogRead(A0); 
 if (deger > esikDegeri) {
   tone(buzzerPin, C );
    delay(100);
    noTone(buzzerPin);
    delay(100);
 } else {
  noTone(buzzerPin);
 }
}
