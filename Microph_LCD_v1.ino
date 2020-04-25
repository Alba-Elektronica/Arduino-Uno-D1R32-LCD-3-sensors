#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 100; // variable to store the value coming from the sensor

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  pinMode (ledPin, OUTPUT);
}

void loop(){
  sensorValue = analogRead (sensorPin);
  digitalWrite (ledPin, HIGH);
  delay (sensorValue);
  digitalWrite (ledPin, LOW);
  delay (sensorValue);
  lcd.print("Sensor val: ");
  lcd.print(sensorValue);
  delay(1000);
}
