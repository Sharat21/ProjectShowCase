
//Relay Sensor Integer value
int relay = 13;
int sensor = 8;
int sensor1 = 0;
int sensorPin = A0;
int val1;



void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //Sending signal to relay through pin 13
  pinMode(8, OUTPUT); //Setting ping 8 as the input pin in order to reieve data
  Serial.begin(9600);
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

 if(val1 >=60) 
 {
  if(val1 >= 61 && val1 <= 75)
  {
    digitalWrite(13,HIGH); //sendinglow value to the relay
    delay(90000); //Puts fertilizer for 1.5 minutes (1 minute and 30 seconds)
    digitalWrite(13,LOW);
  }
 
  else
  {
    digitalWrite(13,LOW); //sends high value to the relay
  }
  delay(1000); //Every 2 hours is the delay (7200000)
  }
delay(1000);  //(7200000)


}
