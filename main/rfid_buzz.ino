#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 8
#define GREEN_LED_PIN 7
#define RED_LED_PIN 6

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  Serial.println("Kartınızı okutup bekleyin...");
}

void loop() {
  // RFID kartının taranmasını bekleyin
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Kart ID'sini alın
  String cardID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    cardID += String(mfrc522.uid.uidByte[i], DEC);
    if (i < mfrc522.uid.size - 1) cardID += ",";
  }

  Serial.print("Kart ID'si: ");
  Serial.println(cardID);

  // LED'leri kapat
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  // Belirtilen kart ID'si ile karşılaştırın
  if (cardID == "57,226,214,75") {
    // Doğru kart -> Yeşil LED yanacak ve buzzer çalacak
    digitalWrite(GREEN_LED_PIN, HIGH);
    tone(BUZZER_PIN, 262);
    delay(1000);  // 3 saniye bekle
    noTone(BUZZER_PIN);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    // Yanlış kart -> Kırmızı LED yanacak
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, 330);
    delay(1000);  // 3 saniye bekle
    digitalWrite(RED_LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  // Kartı uyku moduna al ve loop'u tekrar başlat
  mfrc522.PICC_HaltA();
  delay(1000); // Biraz bekle, sonra tekrar başla
}




 
