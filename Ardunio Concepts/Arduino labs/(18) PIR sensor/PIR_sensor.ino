int led = 13;                // the LED pin is attached to pin 13
int sensor = 3;              // the pin that the sensor is attached to is pin 3
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value) = 0

void setup() { //Initlization
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial for Serial Monitor
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) { //condition is if the state is low it runs this code or it does something else (else)
      Serial.println("Motion detected!");  //Writes Motion Detected in Serial Monitor
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {   //else statement
      digitalWrite(led, LOW); // turn The LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!"); //Writes No Motion Detected in Serial Monitor
        state = LOW;       // update variable state to LOW
    }
  }
}
