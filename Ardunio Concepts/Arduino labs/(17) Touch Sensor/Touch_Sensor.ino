//Digital Capacitive Touch Sensor Arduino Interfacing
 
int sensorPin = 7; // capactitive touch sensor - Arduino Digital pin D1
 
int ledPin = 13; // Output display LED (on board LED) - Arduino Digital pin D13
 
void setup() {
  Serial.begin(9600); //Begin Serial Monitor
  pinMode(ledPin, OUTPUT);   //Initilize as an Ouput
  pinMode(sensorPin, INPUT); //Initialize as an Input
}
 
void loop() {
  int senseValue = digitalRead(sensorPin);
  if (senseValue == 1){
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED"); //Prints Touched if sense value == 1 in serial Monitor and turns LED on
  }
  else{
    digitalWrite(ledPin,LOW);
    Serial.println("not touched"); //Prints not touched if sensor value doesn't ==1 in serial monitor and turns off led
  } 
  delay(500); //delay of 500 miliseconds. 
  
}
