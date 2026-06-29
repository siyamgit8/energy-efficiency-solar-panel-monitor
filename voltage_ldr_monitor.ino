// pins i am using
int voltagePin = A0;
int ldrPin = A1;
int redLed = 12;
int greenLed = 13;
int buzzer = 11;

// threshold values
int ldrThreshold = 500;
float voltageThreshold = 1.0;

// buzzer will run for 5 seconds only
unsigned long buzzerDuration = 5000;
unsigned long buzzerStartTime = 0;
bool buzzerActive = false;

// last time we printed to serial
unsigned long lastPrintTime = 0;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("System started...");
}

void allOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int rawVolt = analogRead(voltagePin);
  float voltage = rawVolt * (5.0 / 1023.0);

  unsigned long now = millis();

  // print sensor values every 500ms so serial monitor doesnt spam
  if (now - lastPrintTime >= 500) {
    Serial.print("LDR Value: ");
    Serial.print(ldrValue);
    Serial.print("   Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");
    lastPrintTime = now;
  }

  if (ldrValue < ldrThreshold) {
    // dark condition detected

    if (voltage < voltageThreshold) {
      // LOW voltage + dark = fault condition
      // start buzzer timer if not already running
      if (!buzzerActive) {
        buzzerActive = true;
        buzzerStartTime = now;
      }

      // blink red led every 1 second
      bool blinkState = (now / 1000) % 2 == 0;
      digitalWrite(redLed, blinkState ? HIGH : LOW);
      digitalWrite(greenLed, LOW);

      // buzzer runs steady for 5 seconds then stops
      if (now - buzzerStartTime <= buzzerDuration) {
        digitalWrite(buzzer, HIGH);
      } else {
        digitalWrite(buzzer, LOW);
        buzzerActive = false; // reset so it can trigger again next time
      }

    } else {
      // dark but voltage is fine = normal night mode
      buzzerActive = false;
      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, LOW);

      // blink green slowly every 2 seconds
      bool blinkState = (now / 2000) % 2 == 0;
      digitalWrite(greenLed, blinkState ? HIGH : LOW);
    }

  } else {
    // bright light detected = everything off
    buzzerActive = false;
    allOff();
  }
}