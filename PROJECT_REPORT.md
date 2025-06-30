# Smart Trolley – Project Report

## 📌 Objective

To develop a smart shopping trolley system that automates the billing process using RFID technology and reduces checkout time in supermarkets.

## ⚙️ System Overview

Each product is equipped with an RFID tag. When placed in the trolley, the tag is scanned, and item details are displayed on an LCD screen. The system maintains a running total and notifies the user if the budget limit is exceeded using a buzzer and servo lock.

## 🧰 Hardware Components

| Component       | Description                       |
|----------------|-----------------------------------|
| Arduino Nano    | Microcontroller unit              |
| RC522 RFID Module | Used for scanning RFID tags      |
| RFID Tags       | Represent items in the store      |
| LCD I2C Display | For showing item name and total   |
| Buzzer          | Alerts for scan and errors        |
| Servo Motor     | Locks trolley when budget is exceeded |
| Push Button     | Optional item removal             |
| Power Supply    | 5V Battery / USB                  |

## 🔌 Circuit Diagram

See `assets/circuit_diagram.png` for the wiring layout.

## 🔄 Working

1. RFID tag is scanned when item is added.
2. The UID is matched to a predefined item list.
3. Item name and updated bill are shown on LCD.
4. Buzzer beeps for successful or failed scan.
5. Servo motor locks trolley if total exceeds ₹100.

## 🧠 Code Description

- `smart_trolley.ino` contains all logic:
  - RFID reading using MFRC522
  - LCD control via I2C
  - UID matching and billing
  - Buzzer/servo control

## 🎯 Future Improvements

- Add Wi-Fi support for cloud syncing
- Add mobile app integration
- Add barcode scanner for non-RFID items
- Support for item removal confirmation

## 🎥 Demo

Placeholder demo in `assets/demo.gif`. Replace with your own GIF or link to a YouTube video.

## 👨‍💻 Author

Darshan Jadhav  
GitHub: [yourusername](https://github.com/yourusername)  
Email: your.email@example.com  
