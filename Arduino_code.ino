
/*
 * Breated By : Code and Robot ID
 * Project    : Hand Tracking Arduino
 * Date       : 6 Agustus 2021
 */

#include <Wire.h> // Library kabel sedikit
#include <LiquidCrystal_I2C.h> // Untuk library LCD secara I2C
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

String data_serial_receive;
int time_delay = 2;
int ledPins[] = {2,3,4,5,6}; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(LED_BUILTIN, OUTPUT);
  for(int i = 0; i < 5; i++){
     pinMode(ledPins[i],OUTPUT);  //this is a loop and will repeat eight times
  }
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("Hand Tracking Python");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

   if (Serial.available() > 0) {
    data_serial_receive = Serial.readStringUntil('\n');
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("Nilai Serial1:");
    lcd.setCursor(15,2);
    lcd.print(data_serial_receive);
    //delay(time_delay);

    if (data_serial_receive == "11"){ // Kode yang diterima dari serial python, tangan kanan dan 1 jari yang terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kanan 1");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala"); 

      digitalWrite(ledPins[0], HIGH); // Nyalakan LED 1 saja
      digitalWrite(ledPins[1], LOW); // LED 2 mati
      digitalWrite(ledPins[2], LOW); // LED 3 mati
      digitalWrite(ledPins[3], LOW); // LED 4 mati
      digitalWrite(ledPins[4], LOW); // LED 5 mati
      
      //delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "12"){ // Ini 2 jari kanan yang terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kanan 2");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala");  

      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1], HIGH); // LED 2 nyala
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "13"){ // 3 jari kanan yang terdeteksi makan LED no 3 nyala
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kanan 3");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala");   

      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], HIGH);  // LED 3 nyala
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "14"){ // 4 jari kanan terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kanan 4");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala");    

      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], HIGH); // LED no 4 nyala
      digitalWrite(ledPins[4], LOW);
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "15"){ // semua jari kanan terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kanan 5");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala"); 
      //digitalWrite(LED_BUILTIN, HIGH);

      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], HIGH); // LED no 5 nyala
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "21"){ // disamakan dengan '11' jadi 1 LED saja yang menyala
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kiri 1");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala"); 

      digitalWrite(ledPins[0], HIGH); // LED no 1 saja yang menyala
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      
      //delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "22"){ // 2 jari kiri terdeteksi 
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kiri 2");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala"); 

      digitalWrite(ledPins[0], HIGH); // LED no 1 mnyela
      digitalWrite(ledPins[1], HIGH); // LED no 2 juga mneyala
      digitalWrite(ledPins[2], LOW);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "23"){ // Kiri dengan 3 jari terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kiri 3");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala");

      digitalWrite(ledPins[0], HIGH); //nyala 3 LED
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], LOW);
      digitalWrite(ledPins[4], LOW);
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "24"){ // $ jari kiri yang terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kiri 4");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala");

      digitalWrite(ledPins[0], HIGH); // Nyala 4 LED
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[4], LOW);
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "25"){ // 5 jari kiri terdeteksi
      lcd.backlight();
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kiri 5");
      lcd.setCursor(0,1);
      lcd.print("Lampu Nyala");

      for (int i=0; i<5; i++){
        digitalWrite(ledPins[i], HIGH); // Semua LED menyala
      }
      
      // delay(time_delay);// wait for a second
    }
    else if (data_serial_receive == "10" or data_serial_receive == "20"){
      lcd.backlight();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kanan/Kiri 0");  
      lcd.setCursor(0,1);
      lcd.print("Lampu Mati");
      //digitalWrite(LED_BUILTIN, LOW); 

      for (int i=0; i<5; i++){
        digitalWrite(ledPins[i], LOW); // Jika tangan mengepal maka semua LED mati
      }
      
      // delay(time_delay);// wait for a second
    }
  }

}
