int trigpin = 9;
int echopin = 10;
int yled = 11;
int sled = 12;
int kled = 13;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin ,OUTPUT);
pinMode(echopin ,INPUT);
pinMode(yled ,OUTPUT);
pinMode(sled ,OUTPUT);
pinMode(kled ,OUTPUT);
}

void loop() {
  digitalWrite(kled ,HIGH);
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
  if (mesafe < 3){
   delay(5000);
   digitalWrite(kled ,LOW);
   digitalWrite(sled ,HIGH);
   delay(1000);
   digitalWrite(sled ,LOW);
   digitalWrite(yled ,HIGH);
   delay(10000);
   digitalWrite(yled ,LOW);
  }else{
    digitalWrite(kled ,HIGH);
  }
}
