
const int relayPin = 2;      // Set the relay pin to pin 2
const int timeDelay = 1000; // 1000 milisecond delay

void setup() //Initialize
{
  pinMode(relayPin, OUTPUT);  // set RelayPin as an output
}


void loop()                     //loop
{
  digitalWrite(relayPin, HIGH);  // turn the relay on
  
  delay(timeDelay);              // wait for the delay of one second/1000 miliseconds
  
  digitalWrite(relayPin, LOW);   // turn the relay off
  
  delay(timeDelay);              // wait for the delay of one second/1000 miliseconds
} 
