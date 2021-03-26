#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
// sensorRain -->  1024 maxim, 0 minim

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

void loop()
{
  int f = analogRead(A0);
  lcd.setCursor(0,0); 
  //lcd.print("Drops: ");
  //lcd.print(1024 - f);
  //lcd.setCursor(0,1);
  lcd.print("Rain: ");
  if (f < 1024 - 400 ) {
    lcd.print("Yes");
  } else {
    lcd.print("No");
  }
  delay(100);
}
