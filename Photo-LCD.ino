#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0; // select the input pin 
int ledPin = 13; // select the pin for the LED
int sensorValue = 100; // variable to store the value coming from the sensor

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  Serial.begin(9600); 
  pinMode (ledPin, OUTPUT);
}

void loop(){
  sensorValue = analogRead (sensorPin);
  sensorValue = 120 * log10(sensorValue/5);
  Serial.println(sensorValue);

  digitalWrite (ledPin, HIGH);
  
  delay (100);
  digitalWrite (ledPin, LOW);
  delay (sensorValue);
  
  lcd.print("Sensor val: ");
  lcd.print(sensorValue);

  delay(1000);
}
