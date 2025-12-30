//optional rfid or bluetooth

#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define SDA_PIN 5
#define RST_PIN 22
#define SERVO_PIN 13
#define BUZZER 4//

MFRC522 rfid(SDA_PIN, RST_PIN);
Servo door;

// New PWM variables
int buzzerChannel = -1;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_DOOR");

  SPI.begin();
  rfid.PCD_Init();

  door.attach(SERVO_PIN);
  door.write(0);

  // New ESP32 PWM setup
  buzzerChannel = ledcAttach(BUZZER, 2000, 8);   // pin, freq, resolution

  Serial.println("RFID OR Bluetooth Door Ready");
}

void loop() {

  // Bluetooth
  if (SerialBT.available()) {
    String cmd = SerialBT.readStringUntil('\n');
    cmd.trim();
    if (cmd == "OPEN") {
      openDoor();
    }
  }

  // RFID
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    openDoor();
    rfid.PICC_HaltA();
  }
}

void beep(int ms) {
  ledcWrite(BUZZER, 128);   // ON
  delay(ms);
  ledcWrite(BUZZER, 0);     // OFF
}

void openDoor() {
  SerialBT.println("Door Opened");
  beep(400);

  door.write(90);
  delay(5000);
  door.write(0);

  SerialBT.println("Door Closed");
}
