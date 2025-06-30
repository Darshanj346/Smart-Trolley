# Smart Trolley – Intelligent Shopping Cart System

The Smart Trolley is an IoT-based project designed to simplify the shopping experience by automatically scanning items using RFID tags and displaying the bill in real-time on an LCD. This reduces waiting time at billing counters.

## 💡 Features

- RFID-based item detection
- LCD display for billing
- Buzzer alerts for cart actions
- Real-time stock monitoring
- Servo motor to lock/unlock cart if budget exceeded

## 🧰 Components Used

- Arduino Uno / Nano
- RFID Module (RC522)
- RFID Tags (UIDs for items)
- LCD Display with I2C Module
- Buzzer
- Servo Motor
- Push Button
- LEDs
- Breadboard & Jumpers
- Power Supply

## 🔌 Circuit Diagram
assets/IoT-based-Smart-Shopping-Cart-Circuit-Diagram.png

## 🧠 Working

1. Each item has an RFID tag.
2. When the item is placed in the trolley, the RC522 reads its UID.
3. If UID matches the stored item, it is added to the bill.
4. The LCD shows the item name and running total.
5. Pressing the button removes the last scanned item (optional).

## 📦 Code

See `code/smart_trolley.ino`.

## 📸 Preview

![Demo](assets/demo.gif)


