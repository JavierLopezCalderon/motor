// Define stepper motor connections:
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define dirPin 2
#define stepPin 3

LiquidCrystal_I2C lcd(0x27, 16, 2);  //

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.print("INICIANDO...");
  delay(1000);
  lcd.clear();
  /*// Set the spinning direction CW/CCW:
  digitalWrite(dirPin, HIGH);*/
}

void loop() {
  digitalWrite(dirPin, HIGH);
  // These four lines result in 1 step:
  for(int i=0; i<300; i++){
    digitalWrite(stepPin, HIGH);
    delay(20);
    digitalWrite(stepPin, LOW);
    delay(20);
    lcd.setCursor(0, 0);
    lcd.print("P:");
    lcd.setCursor(3, 0);
    lcd.print(i);
   // lcd.clear();
  }
  digitalWrite(dirPin, LOW);
  // These four lines result in 1 step:
  for(int i=0; i<1500; i++){
    digitalWrite(stepPin, HIGH);
    delay(20);
    digitalWrite(stepPin, LOW);
    delay(20);
  }

  
}
