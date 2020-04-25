#include "DHT.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define DHTTYPE DHT11   // DHT 11

#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  dht.begin();
}

void loop()
{
  float f = dht.readTemperature(true);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(dht.readTemperature());
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(dht.readHumidity());
  lcd.print("%");
  delay(1000);
}
