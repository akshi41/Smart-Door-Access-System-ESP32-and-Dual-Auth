# Smart-Door-Access-System-ESP32-and-Dual-Auth
A dual-authentication smart door system using ESP32, allowing users to unlock the door via either RFID or Bluetooth. Designed for IoT security applications with automatic door control and audio alerts.
This project demonstrates a **secure, flexible and low-cost IoT-based access control system**.

---

## 🚀 Features

- Door can be unlocked using **Bluetooth (mobile app)**  
- Door can also be unlocked using **RFID card**  
- **Either RFID or Bluetooth** can open the door  
- **Servo motor** automatically opens and closes the door  
- **Buzzer** gives audio alert when the door opens  
- Works in real-time using **ESP32**

---

## 🧰 Components Used

| Component | Quantity |
|----------|---------|
| ESP32 Development Board | 1 |
| RFID Reader (RC522) | 1 |
| RFID Card / Tag | 1 |
| Servo Motor (SG90) | 1 |
| Buzzer | 1 |
| Jumper Wires | As required |
| Android Phone (Bluetooth App) | 1 |

---

## 🔌 Connections

### RFID RC522 → ESP32
| RFID Pin | ESP32 Pin |
|---------|---------|
| SDA | GPIO 5 |
| SCK | GPIO 18 |
| MOSI | GPIO 23 |
| MISO | GPIO 19 |
| RST | GPIO 22 |
| 3.3V | 3.3V |
| GND | GND |

### Servo Motor → ESP32
| Servo Wire | ESP32 |
|-----------|------|
| Red | 5V |
| Brown | GND |
| Yellow (Signal) | GPIO 13 |

### Buzzer → ESP32
| Buzzer | ESP32 |
|--------|------|
| + | GPIO 4 |
| – | GND |

---

## 🧠 How It Works

1. ESP32 waits for **Bluetooth command** or **RFID scan**  
2. If **Bluetooth "OPEN"** is received → door opens  
3. If **any RFID card** is scanned → door opens  
4. When door opens:
   - Buzzer beeps  
   - Servo rotates to open the door  
5. After 5 seconds, the door automatically closes  

This allows **two ways of authentication**:  
- Mobile phone  
- RFID card  

---

## 📱 Bluetooth Setup

Install **Serial Bluetooth Terminal** from the Play Store.

Steps:
1. Power the ESP32  
2. Connect Bluetooth to **ESP32_DOOR**  
3. Send:


The door will open.

---

## 🧪 How to Run

1. Upload the Arduino code to ESP32  
2. Connect all components as per wiring table  
3. Power the ESP32  
4. Use:
   - Bluetooth `OPEN` command  
   **OR**
   - Tap RFID card  
5. Door opens and closes automatically

---
## 🎬 Demo Video

Watch the working demo of the Smart Door Access System here:  

Automatic Door both rfid and bluetooth:
https://drive.google.com/file/d/1u2zA2EkUEI9YTgHzT9D-YhT66AeXmCqj/view?usp=sharing

Automatic Door both rfid or bluetooth:
https://drive.google.com/file/d/1FoQ6u42a_N5dw5mSJE1sLqOQTSOPSJGd/view?usp=sharing

## 🎯 Applications

- Smart Home Door Lock  
- Office Entry System  
- Hostel or Lab Access Control  
- IoT Security Projects  

---

## 🔮 Future Improvements

- Add LCD or OLED display  
- Add password using mobile app  
- Add cloud logging (Firebase / ThingSpeak)  
- Add mobile UI buttons  
- Add face recognition (ESP32-CAM)

---

## 👨‍💻 Author

**Akshitha**  
ESP32 | IoT | Embedded Systems  

