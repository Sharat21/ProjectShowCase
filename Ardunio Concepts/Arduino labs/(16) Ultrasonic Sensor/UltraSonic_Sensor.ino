/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
More info at: http://goo.gl/kJ8Gl
*/

#define trigPin 9 //define the pin
#define echoPin 10 //define the pin

void setup() {
  Serial.begin (9600); //Begin serial monitor
  pinMode(trigPin, OUTPUT); //intialize as an output
  pinMode(echoPin, INPUT); //initialize as input
}

void loop() {
  int duration, distance; //state the int
  digitalWrite(trigPin, HIGH); //high value
  delayMicroseconds(1000); //delay of 1000 microseconds
  digitalWrite(trigPin, LOW); //low value
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration/2) / 29.1; //equation (math behind calculation)
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range"); //This happens when distance is 200cm or more
  }
  else {
    Serial.print(distance);  //IF the distance is in range it prints the distance in cm.
    Serial.println(" cm");
  }
  int thisPitch = map(distance, 0, 200, 2093, 22); //this is for the peizo for when the peizo does come close it has a high pitch and far it has a low pitch
  tone(4, thisPitch);
  delay(500); //delay of 500 miliseconds. 
  noTone(4);
}
