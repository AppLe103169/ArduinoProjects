#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>





#include <SPI.h>

int buzz = 8;

int RST_PIN = 9; //RC522 modülü reset pinini tanımlıyoruz.
int SS_PIN = 10; //RC522 modülü chip select pinini tanımlıyoruz.
; //Servo motor pinini tanımlıyoruz.
 //Servo motor için değişken oluşturuyoruz.
MFRC522 rfid(SS_PIN, RST_PIN); //RC522 modülü ayarlarını yapıyoruz.
byte ID[4] = {
  57,
  226,
  214,
  75
}; //Yetkili kart ID'sini tanımlıyoruz. 
void setup() {
  pinMode(buzz, OUTPUT); //Servo motor pinini motor değişkeni ile ilişkilendiriyoruz.
  Serial.begin(9600); //Seri haberleşmeyi başlatıyoruz.
  SPI.begin(); //SPI iletişimini başlatıyoruz.
  rfid.PCD_Init(); //RC522 modülünü başlatıyoruz.
}
void loop() {
  if (!rfid.PICC_IsNewCardPresent()) //Yeni kartın okunmasını bekliyoruz.
   noTone(buzz);
    return;
  if (!rfid.PICC_ReadCardSerial()) //Kart okunmadığı zaman bekliyoruz.
 
    return;
    
  if (rfid.uid.uidByte[0] == ID[0] && //Okunan kart ID'si ile ID değişkenini karşılaştırıyoruz.
    rfid.uid.uidByte[1] == ID[1] &&
    rfid.uid.uidByte[2] == ID[2] &&
    rfid.uid.uidByte[3] == ID[3]) {
    Serial.println("Kapi acildi");
    ekranaYazdir();
    tone(buzz, 262); //Servo motoru 180 dereceye getiriyoruz.
    delay(3000);
    noTone(buzz); //Servo motoru 0 dereceye getiriyoruz.
    delay(20);
  } else { //Yetkisiz girişte içerideki komutlar çalıştırılır.
    Serial.println("Yetkisiz Kart");
    ekranaYazdir();
    noTone(buzz);
  }
  rfid.PICC_HaltA();
}
void ekranaYazdir() {
  Serial.print("ID Numarasi: ");
  for (int sayac = 0; sayac < 4; sayac++) {
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}
