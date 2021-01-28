//Writeen by Sharat

int  analogPin = A0;     // The interger value is being assigned with the analog 0 value
int ledPin = 13;   // the interger ledPin is being assigned pin 13 which is 13.
int sensorValue = 0;       // Interger/variable to store the analog value from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
}

void loop() {   //A loop condition to keep the ledPin from turning off or consistently staying on creating the blinking function (High to low loop)
  sensorValue = analogRead(analogPin);    // readinjg the value from the sensor (A0)
  digitalWrite(ledPin, HIGH);  // turn the ledPin on 
  delay(sensorValue);                  // stop the program for some time (miliseconds)
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(sensorValue);                  // stop the program for some time
}
 
