const int ledPin = 13; //pin 13 is the LED
const int pushbutton1 = 2; //pin 2 is pushbutton 1
const int pushbutton2 = 3; //pin 3 is pushbutton2
int buttonState1 = 0; //giving it a value of 0
int buttonState2 = 0; //giving it a value of 0
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT); //Initialize as Ouput
  pinMode(pushbutton1,INPUT); //Initialize as an INPUT
  pinMode(pushbutton2,INPUT); //Initialize as an INPUT
}
void loop()
{
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(pushbutton1); //button state1 is digitallyreading pushbutton 1
  buttonState2 = digitalRead(pushbutton2);//button state2 is digitallyreading pushbutton 2
  digitalWrite(ledPin,LOW);
  
  if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);   //if Button state 1 is high, lED is on
  }
  else{
    // turn LED off:
    digitalWrite(ledPin, LOW); // turns off lED
  }

 if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH); //if button state 2 is high, LED turns on
  }
  else{
    // turn LED off:
    digitalWrite(ledPin, LOW); //else turns off
  }

}
