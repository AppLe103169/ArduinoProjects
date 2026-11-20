#define echo 9
#define trig 10
#define buzz 8
int maxiRange = 50;
int minimumRange = 0; 




void setup() {
 pinMode(trig ,OUTPUT);
 pinMode(buzz ,OUTPUT);
 pinMode(echo ,INPUT); 

}

void loop() {

  
  int olcum = mesafe(maxiRange,minimumRange);
melodi(olcum*10);
}
int mesafe(int maxrange, int minrange)
{
  long duration, distance;

  digitalWrite(trig ,LOW);
  delayMicroseconds(2);
  digitalWrite(trig ,HIGH);
  delayMicroseconds(10);
   digitalWrite(trig ,LOW);

   duration = pulseIn(echo ,HIGH);
   distance = duration / 58.2;
   delay(50);

   if(distance >= maxrange || distance <= minrange)
   return 0;
   return distance;
   
}
int melodi(int dly)
{
  tone(buzz ,330);
  delay(dly);
  noTone (buzz);
  delay(dly);
 
}
