
int blue = 9; //blue pin of led is connected to pin 9
int green = 10; //green pin of rgb led is connected to pin 10
int red = 11; //red pin of rgb led is connected to pin 11
void setup() {  //Initliaziation 
  // put your setup code here, to run once:
  pinMode(red, OUTPUT); //output these values
  pinMode(green,OUTPUT); //output these values
  pinMode(blue,OUTPUT); //output these value
}

void loop()  //A loop to keep looping the code inside the loop (No condition)
{ 
  // put your main code here, to run repeatedly:
  setColor(255, 0, 0); // Red Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(0, 255, 0); // Green Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(0, 0, 255); // Blue Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(255, 255, 125); // Raspberry Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(0, 255, 255); // Cyan Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(255, 0, 255); // Magenta Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(255, 255, 0); // Yellow Colour
  delay(1000); //delay 1 second or 1000 miliseconds
  setColor(255, 255, 255); // White Colour
  delay(1000); //delay 1 second or 1000 miliseconds
}

void setColor(int redvalue, int greenvalue, int bluevalue) //the Set Colour inizailization (Set Color is being declared in this scope)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(red, redvalue); //Writing the Analog values of the red pin and value
  analogWrite(green, greenvalue); //Writing the Analog values of the green pin and value
  analogWrite(blue, bluevalue); //Writing the Analog values of the blue pin and value
}
