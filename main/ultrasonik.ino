int trigpin = 8;
int echopin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin ,OUTPUT);
pinMode(echopin ,INPUT);
}

void loop() {
long sure ,mesafe;
digitalWrite(trigpin ,LOW);
delayMicroseconds(2);
digitalWrite(trigpin ,HIGH);
delayMicroseconds(10);
 digitalWrite(trigpin ,LOW);
 sure = pulseIn(echopin ,HIGH);
 mesafe = (sure/2) / 29.2;
 Serial.print("ölçülen  mesafe:"); 
  Serial.print(mesafe); 
  Serial.println("cm"); 
  delay(500); 
}
