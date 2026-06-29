# Energy Efficiency Monitoring for Solar Panel 🌞

A simple Arduino based project that monitors voltage output and light intensity of a solar panel using an LDR sensor. It gives real time alerts using LEDs and a buzzer based on the readings.

---

## 📌 What This Project Does

- Reads **voltage output** from the solar panel using analog pin A0
- Reads **light intensity** using an **LDR sensor** on analog pin A1
- **Red LED blinks** when it's dark and voltage is too low (fault condition)
- **Buzzer alerts** for 5 seconds when fault is detected
- **Green LED blinks** when it's dark but voltage is normal (night mode)
- All outputs turn off when there is bright light
- Sensor values are printed to **Serial Monitor** every 500ms

---

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| LDR (Light Dependent Resistor) | 1 |
| Voltage Sensor Module | 1 |
| Red LED | 1 |
| Green LED | 1 |
| Buzzer | 1 |
| Resistors (10kΩ) | 2 |
| Breadboard | 1 |
| Jumper Wires | as needed |

---

## 🔌 Pin Connections

| Component | Arduino Pin |
|---|---|
| Voltage Sensor | A0 |
| LDR Sensor | A1 |
| Red LED | D12 |
| Green LED | D13 |
| Buzzer | D11 |

---

## ⚙️ How It Works

The system checks two things at all times — **light level** and **voltage output**.

**3 possible conditions:**

1. **Bright light** → Everything is off (solar panel working normally in daylight)
2. **Dark + Good voltage** → Green LED blinks slowly (night mode, battery is charged)
3. **Dark + Low voltage** → Red LED blinks + Buzzer sounds for 5 seconds (fault detected)

The buzzer runs for only 5 seconds to avoid continuous noise, then resets and can trigger again if the fault continues.

---

## 📊 Threshold Values

| Parameter | Value |
|---|---|
| LDR Threshold | 500 (out of 1023) |
| Voltage Threshold | 1.0V |
| Buzzer Alert Duration | 5 seconds |

---

## 💻 How to Upload the Code

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software)
2. Open `voltage_ldr_monitor.ino`
3. Select **Tools → Board → Arduino UNO**
4. Select the correct **COM Port** under Tools → Port
5. Click the **Upload** button (→ arrow)

---

## 📁 Project Structure

```
energy-efficiency-solar-panel-monitor/
│
├── voltage_ldr_monitor.ino   # main arduino code
├── circuit.png               # circuit diagram (coming soon)
└── README.md                 # project description
```

---

## 🚀 Future Improvements

- Add an LCD display to show live voltage and LDR readings
- Log data to an SD card for analysis
- Add WiFi module (ESP8266) to monitor readings on phone
- Set adjustable thresholds using a potentiometer

---

## 👨‍💻 Made By

**Siyam Singh**
B.Tech Mechatronics, Robotics & Automation Engineering
CAS, AKTU Lucknow (Batch 2025–2029)

🔗 [LinkedIn](https://linkedin.com/in/siyamsingh-23398638a)
