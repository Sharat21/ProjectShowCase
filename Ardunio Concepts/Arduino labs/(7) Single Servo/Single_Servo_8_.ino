#include <Servo.h> //Include the library

Servo myservo;  // create servo object to control a servo inorder to do this lab


int pos = 0;    // variable to store the servo position = 0

void setup() {
  myservo.attach(9);  // the servo is being attached to pin 9
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // delay of 15 miliseconds in order for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // delay of 15 miliseconds in order for the servo to reach the position. 
  }
}
