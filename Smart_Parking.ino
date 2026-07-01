#include <LiquidCrystal.h> //1-include the necesseary librairies
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//2-initialise the LCD and servo motor
Servo myServo;

const int Gate = 7;  //3- define the pins used
const int slot_1 = 8;
const int slot_2 = 9;

void setup() {
  myServo.attach(6); //4-attach the servo motor
  lcd.begin(16, 2); //5-initialize the LCD and serial and clear the LCD
  Serial.begin(9600);
  lcd.clear();
  closeGate(); //we close Gate first

  // Method updated: simple and clean
  for (int pin = 7; pin < 10; pin++) { 
    pinMode(pin, INPUT);
  }
}

void loop() {
  // Changed type to bool (true/false)
  bool G_value = digitalRead(Gate) == false;
  bool S1_value = digitalRead(slot_1) == false;
  bool S2_value = digitalRead(slot_2) == false;

  if (!G_value) { // Car is present at the gate
    if (S1_value && S2_value) {
      lcd.setCursor(0, 0);
      lcd.print("Available:      ");
      lcd.setCursor(0, 1);
      lcd.print("Slot 1 & Slot 2");
      openGate();
    } 
    else if (!S1_value && S2_value) {
      lcd.setCursor(0, 0);
      lcd.print("Available:      ");
      lcd.setCursor(0, 1);
      lcd.print("Slot 2          ");
      openGate();
    } 
    else if (S1_value && !S2_value) {
      lcd.setCursor(0, 0);
      lcd.print("Available:      ");
      lcd.setCursor(0, 1);
      lcd.print("Slot 1          ");
      openGate();
    } 
    else { // Both slots are full
      lcd.setCursor(0, 0);
      lcd.print("Full Parking    ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      closeGate(); // Only closes when parking is full
    }
  } 
  else { // No car at the gate (System Idle)
    lcd.setCursor(0, 0);
    lcd.print("PARK CAR HERE   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    closeGate(); // Only closes when no car is waiting
  }

  delay(500);
}



void openGate() { // Using functions 
  myServo.write(0);
}

void closeGate() {
  myServo.write(90);
}
