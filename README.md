# Smart_Home_Systems

A simple smart home automation system built using **ESP32** and **Blynk IoT**. The project allows remote control of LED brightness and DC fan speed using sliders, along with RFID-based door access using a servo motor.

## Features
* LED brightness control using PWM
* DC fan speed control using PWM
* RFID-based door unlocking
* Door control through Blynk app
* Wi-Fi connectivity using ESP32

## Components Used
* ESP32 Development Board
* MFRC522 RFID Reader
* SG90 Servo Motor
* LED
* DC Fan
* Logic-Level MOSFET (for fan control)
* Blynk IoT

## Pin Connections
| Component        | ESP32 GPIO |
| ---------------- | ---------- |
| LED              | GPIO 2     |
| DC Fan (PWM)     | GPIO 27    |
| Servo Motor      | GPIO 14    |
| MFRC522 SDA (SS) | GPIO 5     |
| MFRC522 SCK      | GPIO 18    |
| MFRC522 MOSI     | GPIO 23    |
| MFRC522 MISO     | GPIO 19    |
| MFRC522 RST      | GPIO 22    |
| MFRC522 3.3V     | 3.3V       |
| MFRC522 GND      | GND        |

## Blynk Virtual Pins
| Widget                | Virtual Pin |
| --------------------- | ----------- |
| LED Brightness Slider | V0          |
| Fan Speed Slider      | V1          |
| Door Button           | V2          |

## Libraries Used
* Blynk
* MFRC522
* SPI
* ESP32Servo
