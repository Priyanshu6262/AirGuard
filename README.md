# AirGuard
AirGard is an IoT-based gas leakage detection and alert system using NodeMCU, MQ2 gas sensor, relay module, and Blynk IoT for real-time monitoring, automatic safety control, and mobile notifications.


# AirGard - IoT Gas Leakage Detection System

## Overview
AirGard is an IoT-based gas leakage detection and monitoring system built using NodeMCU (ESP8266), MQ2 gas sensor, relay module, and Blynk IoT.

The system detects gases such as LPG, smoke, and alcohol gas, monitors gas levels in real time, controls a relay automatically based on gas concentration, and sends mobile notifications when dangerous gas levels are detected.

## Features
- Real-time gas monitoring using MQ2 sensor
- Blynk IoT dashboard integration
- Gas status zones:
  - Safe Zone
  - Medium Zone
  - Dangerous Zone
- Automatic relay control
- Manual relay ON/OFF control from Blynk app
- Mobile notification alerts for gas leakage
- Anti-spam alert logic (prevents repeated notifications)

## Components Used
- NodeMCU ESP8266
- MQ2 Gas Sensor
- Relay Module
- Jumper Wires
- Breadboard
- Blynk IoT Platform

## Working Principle
1. MQ2 sensor detects gas concentration.
2. NodeMCU reads analog gas values from the sensor.
3. Gas values are sent to Blynk dashboard.
4. System classifies gas level:
   - Gas < 100 → SAFE
   - Gas 100–300 → MEDIUM
   - Gas > 300 → DANGEROUS
5. In danger zone:
   - Relay turns OFF automatically
   - Mobile notification is sent
6. Users can manually control relay through Blynk.

## Pin Connections
- MQ2 A0 → NodeMCU A0
- Relay IN → NodeMCU D5
- Relay VCC → 3.3V / VIN (based on module)
- Relay GND → GND

## Software Used
- Arduino IDE
- Blynk IoT
- ESP8266 Board Package

## Libraries
- ESP8266WiFi
- BlynkSimpleEsp8266

## Future Improvements
- Add buzzer alarm
- Add OLED/LCD display
- Add automatic exhaust fan control
- Add email/SMS alerts
- Add cloud data logging

## Applications
- Home gas leakage monitoring
- Kitchen safety
- Industrial gas monitoring
- Fire and smoke detection

## Author
Priyanshu
