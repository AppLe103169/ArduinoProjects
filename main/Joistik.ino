int xPin = A1;
int yPin =A2;
int buttonPin=A0;
int xPozisyonu=0;
int yPozisyonu=0;
int butonDurum=0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin ,INPUT);
  pinMode(yPin ,INPUT);
  pinMode(buttonPin ,INPUT);
}

void loop() {
  xPozisyonu=analogRead(A1);
  yPozisyonu=analogRead(A2);
  butonDurum=analogRead(A0);
  Serial.print("X:");
  Serial.print(xPozisyonu);
  Serial.print("y:");
  Serial.print(yPozisyonu);
  Serial.print("button:");
  Serial.println(butonDurum);
  delay(100);
  

}
