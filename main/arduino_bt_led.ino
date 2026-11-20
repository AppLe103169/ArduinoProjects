char incomingChar;

void setup() {
  Serial.begin(9600); // Bluetooth modülü ile aynı baud rate
  pinMode(13, OUTPUT); // LED pini çıkış olarak ayarlandı
}

void loop() {
  if (Serial.available() > 0) { // Seri portta veri var mı?
    incomingChar = Serial.read(); // Gelen veriyi oku
    if (incomingChar == '1') {
      digitalWrite(13, HIGH); // LED'i yak
    } else if (incomingChar == '0') {
      digitalWrite(13, LOW); // LED'i söndür
    }
  }
}
