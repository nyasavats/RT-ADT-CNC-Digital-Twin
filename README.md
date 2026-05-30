# RT-ADT — Real-Time Analytical Digital Twin for CNC Monitoring

Low-cost digital twin system for real-time CNC spindle health monitoring and predictive maintenance — built with a single ACS712 current sensor, Arduino Uno, ESP32, and Node-RED.

> B.Tech Minor Project

## What This Does

Reads CNC spindle motor current using a low-cost ACS712 sensor. Uses physics-based models to compute RMS current, load index, and torque in real time. Flags anomalies like tool wear, overload, and chip jamming — no expensive industrial sensors, no black-box ML.
---

## Results

| Metric | Value |
|---|---|
| Anomaly Detection Accuracy | >85% |
| False Positive Rate | <10% |
| End-to-end Latency | <5 seconds |
| RMS Repeatability | ≤5% |
| Materials Tested | Aluminum, Mild Steel |

---

## Files

| File | Purpose |
|---|---|
| `ACS712_Voltage_Reader.ino` | Raw ADC + voltage reading — calibration helper |
| `Current_Measurement.ino` | Voltage to current conversion with zero offset |
| `Production_Script.ino` | Main logger — sensor reading + SD card combined |
| `sd_card_test.ino` | SD card hardware verification |
| `esp32_wifi.ino` | ESP32 WiFi relay — sends data to cloud |

---

## Hardware

| Component | Details |
|---|---|
| CNC Machine | 1610 Pro Mini (GRBL), 775 spindle motor |
| Current Sensor | ACS712 30A — 66 mV/A sensitivity |
| Microcontroller | Arduino Uno R3 |
| Wi-Fi Module | ESP32 |
| Storage | 32 GB MicroSD |
| Cloud Broker | HiveMQ Cloud |
| Dashboard | Node-RED |

---

## Anomaly Detection Logic
Load Index = RMS_current / Baseline_current
Load Index > 1.5  →  WARNING
Load Index > 2.0  →  FAULT
Sudden spike > 0.5A  →  SPIKE alert

---

## Research Areas

Digital Twins · Predictive Maintenance · Cyber-Physical Systems · Industrial IoT · Edge Computing · Smart Manufacturing

---
