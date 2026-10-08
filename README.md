# AirMouse – Wireless Surface-Independent Mouse

A wireless, surface-independent AirMouse developed using **Raspberry Pi Pico, MPU6050, HC-05 Bluetooth, and ESP-01 Wi-Fi**. The system enables cursor movement through hand motion without requiring a conventional mouse surface.

## 📌 Overview

The AirMouse detects hand movements using an **MPU6050 inertial measurement unit (IMU)** and converts the detected orientation into cursor movement.

The system also provides physical buttons for:

* Left click
* Right click
* Scroll up
* Scroll down

Wireless communication is implemented using both **HC-05 Bluetooth** and **ESP-01 Wi-Fi**, providing dual-channel connectivity.

## 🎯 Objectives

* Develop a surface-independent wireless mouse.
* Detect hand movement using an MPU6050 sensor.
* Convert hand orientation into cursor movement.
* Provide hardware-based mouse buttons.
* Implement Bluetooth and Wi-Fi wireless communication.
* Achieve reliable real-time cursor control at a 50 Hz update rate.

## ⚙️ How It Works

The system consists of a handheld transmitter and a receiver.

1. The **MPU6050** detects the orientation and movement of the handheld device.
2. The **Raspberry Pi Pico** reads the sensor data through I2C.
3. The measured angles are mapped to mouse X and Y movement.
4. Four physical buttons provide mouse click and scrolling functions.
5. The Pico packages the data into a comma-separated format.
6. The data is transmitted through **HC-05 Bluetooth** and **ESP-01 Wi-Fi**.
7. The receiver interprets the received data and converts it into mouse commands.

### Data Format

```text
mouseX,mouseY,leftClick,rightClick,scrollUp,scrollDown
```

## 🧩 System Architecture

```text
             ┌─────────────┐
             │   MPU6050   │
             │  IMU Sensor │
             └──────┬──────┘
                    │ I2C
                    ▼
            ┌───────────────┐
            │ Raspberry Pi  │
            │     Pico      │
            └───────┬───────┘
                    │
        ┌───────────┴───────────┐
        │                       │
        ▼                       ▼
 ┌─────────────┐         ┌─────────────┐
 │    HC-05    │         │    ESP-01   │
 │  Bluetooth  │         │    Wi-Fi    │
 └──────┬──────┘         └──────┬──────┘
        │                       │
        └───────────┬───────────┘
                    ▼
              ┌───────────┐
              │  Receiver │
              └─────┬─────┘
                    ▼
              Cursor / Mouse
```

## 🔧 Hardware Components

| Component            | Purpose                        |
| -------------------- | ------------------------------ |
| Raspberry Pi Pico    | Main microcontroller           |
| MPU6050              | Motion and orientation sensing |
| HC-05                | Bluetooth communication        |
| ESP-01               | Wi-Fi communication            |
| Tactile Push Buttons | Mouse control inputs           |
| Buck-Boost Regulator | Power regulation               |

## 💻 Software

* Arduino IDE
* Embedded C/C++
* Wire Library
* MPU6050_tockn Library
* Serial/UART communication
* ESP-01 AT commands
* TCP communication

## 📡 Wireless Communication

### HC-05 Bluetooth

The HC-05 provides Bluetooth-based wireless communication between the AirMouse and receiver.

### ESP-01 Wi-Fi

The ESP-01 provides Wi-Fi communication using AT commands and TCP communication.

The system is designed to support both communication channels.

## 🖱️ Mouse Controls

| Input              | Function        |
| ------------------ | --------------- |
| Hand movement      | Cursor movement |
| Left button        | Left click      |
| Right button       | Right click     |
| Scroll-up button   | Scroll up       |
| Scroll-down button | Scroll down     |

A **100 ms debounce** is implemented for button inputs to reduce unintended multiple detections.

## 📊 Performance

The implemented system operates at a **50 Hz update rate**, corresponding to a 20 ms processing cycle.

Based on the structured trials:

* Trial-based final accuracy: **85%**
* Bluetooth communication range: up to **10 m**
* Wi-Fi communication range: up to **50 m**
* Button debounce: **100 ms**
* Cursor update rate: **50 Hz**

## 🚀 Future Scope

Future improvements include:

* BLE HID implementation
* Improved wireless communication
* Battery-powered operation
* OLED display integration
* Adjustable cursor sensitivity
* Improved motion filtering
* Further accuracy improvement
* Compact enclosure design

## 📁 Project Structure

```text
AirMouse/
│
├── README.md
├── src/
│   └── AirMouse.ino
├── receiver/
│   └── README.md
├── circuit/
│   └── circuit_diagram.png
└── images/
    ├── block_diagram.png
    ├── flowchart.png
    ├── hardware_model.jpg
    └── accuracy_graph.png
```

## 👩‍💻 Project Team

* Aparajithaa T. S.
* Dhaaarshini Sri S.
* Divyalakshmi J.

---

**AirMouse – A wireless, surface-independent mouse using embedded systems and dual wireless connectivity.**
