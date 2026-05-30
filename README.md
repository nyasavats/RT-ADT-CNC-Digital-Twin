# RT-ADT-CNC-Digital-Twin
Real-Time Analytical Digital Twin (RT-ADT) framework to monitor the health of CNC machines and predict maintenance need. 
What This Does ? 
Reads CNC spindle motor current using a low-cost ACS712 sensor. Uses physics-based models to compute RMS current, load index, and torque in real time. Flags anomalies like tool wear, overload, and chip jamming — no expensive industrial sensors, no black-box ML.
CNC Spindle → ACS712 → Arduino Uno → ESP32 → HiveMQ Cloud → Python Engine → Node-RED Dashboard

