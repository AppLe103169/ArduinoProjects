#define led 8
#define led2 9
#define led3 10
void setup() {
 pinMode (led, OUTPUT);
 pinMode (led2, OUTPUT);
 pinMode (led3, OUTPUT);



}

void loop() {
 digitalWrite (led ,HIGH);
 delay (5000);
 digitalWrite (led ,LOW);

 digitalWrite (led2 ,HIGH);
 delay (3000);
 digitalWrite (led2 ,LOW);
 
 digitalWrite (led3 ,HIGH);
 delay (1000);
 digitalWrite (led3 ,LOW);
 delay (1000);
}
