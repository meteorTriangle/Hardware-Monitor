#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;       // whether the string is complete

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);               
  inputString.reserve(200);
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  
}


void loop()  {
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n');
    String ss;
    String CPU_usage = inputString.substring(0,inputString.indexOf("%")+1);
    int CPU_usage_len = inputString.indexOf("R");
    String RAM_usage = inputString.substring(inputString.indexOf("R"),inputString.indexOf("%",CPU_usage_len)+1);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(CPU_usage);
    lcd.setCursor(0,1);
    lcd.print(RAM_usage);
  }
}
