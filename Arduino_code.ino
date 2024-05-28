/*
Created By    : Code and Robot ID
Project       : Turn ON/Off Lamp Using Hand Tracking
Version       : 02
Date (update) : 28 Mei 2024
*/

#include <Wire.h> // Library kabel sedikit
#include <LiquidCrystal_I2C.h> // Untuk library LCD secara I2C

LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

String data_serial_receive;
const int time_delay = 2;
const int ledPins[] = {2, 3, 4, 5, 6}; 

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 5; i++) {
     pinMode(ledPins[i], OUTPUT);
  }

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Hand Tracking Python");
  delay(1000);
  lcd.clear();
}

void displayMessage(const char* line1, const char* line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void controlLeds(const int ledStatus[], int size) {
  for(int i = 0; i < size; i++) {
    digitalWrite(ledPins[i], ledStatus[i]);
  }
}

void loop() {
  if (Serial.available() > 0) {
    data_serial_receive = Serial.readStringUntil('\n');
    lcd.backlight();
    lcd.setCursor(0, 2);
    lcd.print("Nilai Serial1:");
    lcd.setCursor(15, 2);
    lcd.print(data_serial_receive);

    int ledStatus[5] = {LOW, LOW, LOW, LOW, LOW};

    if (data_serial_receive == "11") {
      displayMessage("Kanan 1", "Lampu Nyala");
      ledStatus[0] = HIGH;
    }
    else if (data_serial_receive == "12") {
      displayMessage("Kanan 2", "Lampu Nyala");
      ledStatus[1] = HIGH;
    }
    else if (data_serial_receive == "13") {
      displayMessage("Kanan 3", "Lampu Nyala");
      ledStatus[2] = HIGH;
    }
    else if (data_serial_receive == "14") {
      displayMessage("Kanan 4", "Lampu Nyala");
      ledStatus[3] = HIGH;
    }
    else if (data_serial_receive == "15") {
      displayMessage("Kanan 5", "Lampu Nyala");
      ledStatus[4] = HIGH;
    }
    else if (data_serial_receive == "21") {
      displayMessage("Kiri 1", "Lampu Nyala");
      ledStatus[0] = HIGH;
    }
    else if (data_serial_receive == "22") {
      displayMessage("Kiri 2", "Lampu Nyala");
      ledStatus[0] = HIGH;
      ledStatus[1] = HIGH;
    }
    else if (data_serial_receive == "23") {
      displayMessage("Kiri 3", "Lampu Nyala");
      ledStatus[0] = HIGH;
      ledStatus[1] = HIGH;
      ledStatus[2] = HIGH;
    }
    else if (data_serial_receive == "24") {
      displayMessage("Kiri 4", "Lampu Nyala");
      ledStatus[0] = HIGH;
      ledStatus[1] = HIGH;
      ledStatus[2] = HIGH;
      ledStatus[3] = HIGH;
    }
    else if (data_serial_receive == "25") {
      displayMessage("Kiri 5", "Lampu Nyala");
      for (int i = 0; i < 5; i++) {
        ledStatus[i] = HIGH;
      }
    }
    else if (data_serial_receive == "10" || data_serial_receive == "20") {
      displayMessage("Kanan/Kiri 0", "Lampu Mati");
    }
    
    controlLeds(ledStatus, 5);
  }
}
