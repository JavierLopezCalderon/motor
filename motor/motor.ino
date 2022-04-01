// Define stepper motor connections:
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

#define dirPin 2
#define stepPin 3
#define Botonreset 4 
int contador;
int pasos = 120, timedelay = 20;
int limiteContador = 1000;
int fin;

LiquidCrystal_I2C lcd(0x27, 16, 2);  //

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(Botonreset, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("INICIANDO...");
  delay(1000);
  lcd.clear();
  EEPROM.get(0, contador);
}

void loop() {
  while(contador < limiteContador+1){ 
    lcd.clear();
    lcd_contador();
    digitalWrite(dirPin, HIGH);
    ciclopaso();
    lcd.clear();
    lcd_contador();
    digitalWrite(dirPin, LOW);
    ciclopaso();
    contador++;
    EEPROM.put(0, contador);
  }
  if(contador <= limiteContador && fin == 0){
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("FIN");
  lcd.setCursor(5, 0);
  lcd.print("C:");
  lcd.setCursor(8,0);
  lcd.print(contador);
    fin = 1;
  }
  if(digitalRead(Botonreset) == HIGH){
    contador =0;
    fin =0;
    EEPROM.put(0, contador);
    delay(500);
  } 
}

void lcd_contador(){
  lcd.setCursor(0, 0);
  lcd.print("C:");
  lcd.setCursor(3, 0);
  lcd.print(contador);
}

void ciclopaso(){
  for(int i=0; i<pasos+1; i++){
    digitalWrite(stepPin, HIGH);
    delay(timedelay);
    digitalWrite(stepPin, LOW);
    delay(timedelay);
    lcd.setCursor(6, 0);
    lcd.print("P:");
    lcd.setCursor(8, 0);
    lcd.print(i);
  }
}
