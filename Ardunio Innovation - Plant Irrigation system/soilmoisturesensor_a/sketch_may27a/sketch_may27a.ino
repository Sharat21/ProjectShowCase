#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
lcd.begin(16, 2); 
lcd.print("  Mert Arduino &"); 
lcd.setCursor(0, 1);
lcd.print("   How To Make");
delay(5000);
lcd.clear();
lcd.print("Arduino Projects");
lcd.setCursor(0, 1);
lcd.print("Tutorials & Make");
delay(5000);
lcd.clear();
lcd.print("   SUBSCRIBE");
lcd.setCursor(0, 1);
lcd.print("FOR MORE VIDEOS");
delay(5000);
lcd.clear();

}

void loop() {

}
