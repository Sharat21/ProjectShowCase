int lightPin = A0;  //Pin is set as Analog pin 0 for the LDR
int ledPin=9;     //pin is set as pin 9 for the LED

void setup()//Initialize
{
    Serial.begin(9600);  //Begin serial Monitor
    pinMode( ledPin, OUTPUT ); //Initialize as an OUTPUT
}

void loop() //Loop
{
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor. (Analog Value)
    analogWrite(ledPin, analogRead(lightPin)/-1);  //send the value to the ledPin. Depending on value of resistor you have  to divide by a negative value to reverse the effect.
                                                //This makes the LED brighter when you cover the photoresistor
   delay(15); //Delay of 15 miliseconds
}
