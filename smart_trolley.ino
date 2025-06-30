
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo lockServo;

int buzzer = 3;
int maxTotal = 100;
int currentTotal = 0;

struct Item {
  String name;
  int price;
  byte uid[4];
};

Item items[] = {
  {"Milk", 20, {0x7A, 0xDB, 0x55, 0xE9}},
  {"Bread", 15, {0xCA, 0x76, 0x4D, 0xE9}},
  {"Eggs", 30, {0x1A, 0x24, 0x4F, 0xE9}},
  {"Juice", 25, {0x93, 0x27, 0xAD, 0xFA}}
};

int itemCount = sizeof(items) / sizeof(Item);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  lockServo.attach(5);
  lockServo.write(0);
  lcd.setCursor(0, 0);
  lcd.print("Smart Trolley");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  byte *uid = rfid.uid.uidByte;
  bool found = false;

  for (int i = 0; i < itemCount; i++) {
    if (memcmp(uid, items[i].uid, 4) == 0) {
      found = true;
      currentTotal += items[i].price;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(items[i].name);
      lcd.setCursor(0, 1);
      lcd.print("Total: Rs.");
      lcd.print(currentTotal);
      tone(buzzer, 1000, 100);
      delay(1000);
      break;
    }
  }

  if (!found) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Item Not Found");
    tone(buzzer, 200, 100);
    delay(1000);
  }

  if (currentTotal > maxTotal) {
    lcd.clear();
    lcd.print("Limit Exceeded!");
    lockServo.write(90);  // lock cart
    tone(buzzer, 2000, 500);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
