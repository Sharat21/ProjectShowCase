
//Relay Sensor Integer value
int relay = 13;
int sensor = 8;
int sensor1 = 0;
int sensorPin = A0;
int val;
int val1;
int blue = 7;
int green = 9;
int red = 10;
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //Sending signal to relay through pin 13
  pinMode(8, OUTPUT); //Setting ping 8 as the input pin in order to reieve data
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);  
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("Garden System");
  lcd.setCursor(0,1);
  lcd.print("      ON");
   delay(2000);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 sensor1 = analogRead(sensorPin);
Serial.print("\n\nAnalogValue:");
Serial.print(sensor1);
val1 = map(sensor1, 1023, 200, 0, 100);
Serial.print("\nPercentValue: ");
Serial.print(val1);
Serial.print("%");

lcd.setCursor(0,0);
lcd.print("Soil Moisture - ");
lcd.setCursor(0,1);
lcd.print(val1);
lcd.print("%");
delay(1000);
lcd.clear();
  
  if(val1 <= 60 && val1 > 0)
  {
    digitalWrite(13,HIGH); //sendinglow value to the relay
    digitalWrite(10,HIGH);
       digitalWrite(9,LOW);
     digitalWrite(7,LOW);
  }
  else if (val1 >= 75 && val1 >= 66)
  {
    digitalWrite(7,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
  }
  else
  {
    digitalWrite(13,LOW); //sends high value to the relay
    digitalWrite(9,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
  }
delay(400);



 
}
