int ledPins[] = {2,3,4,5,6,7,8,9};   // Use of an array to define  multiple led pins consisting of pins 2,3,4,5,6,7,8,9,

void setup() //Initalize
{
  // setup all 8 pins as OUTPUT - notice that the list is "indexed" with a base of 0.
  pinMode(ledPins[0],OUTPUT);  // ledPins[0] = 2 Initialize as an output
  pinMode(ledPins[1],OUTPUT);  // ledPins[1] = 3  Initialize as an output
  pinMode(ledPins[2],OUTPUT);  // ledPins[2] = 4 Initialize as an output
  pinMode(ledPins[3],OUTPUT);  // ledPins[3] = 5 Initialize as an output
  pinMode(ledPins[4],OUTPUT);  // ledPins[4] = 6 Initialize as an output
  pinMode(ledPins[5],OUTPUT);  // ledPins[5] = 7 Initialize as an output
  pinMode(ledPins[6],OUTPUT);  // ledPins[6] = 8 Initialize as an output
  pinMode(ledPins[7],OUTPUT);  // ledPins[7] = 9 Initialize as an output
}

void loop()
{

  // This loop() calls functions that we've written further below.
  // We've disabled some of these by commenting them out (putting
  // "//" in front of them). To try different LED displays, remove
  // the "//" in front of the ones you'd like to run, and add "//"
  // in front of those you don't to comment out (and disable) those
  // lines.

  oneAfterAnother();  // Light up all the LEDs in turn
  
  //oneOnAtATime();         // Turn on one LED at a time
  
  //pingPong();             // Same as oneOnAtATime() but change direction once LED reaches edge

  //marquee();              // Chase lights like you see on theater signs

  //randomLED();            // Blink LEDs randomly
}



/******************************************************************
 * oneAfterAnother()
 * 
 * This function turns all the LEDs on, pauses, and then turns all 
 * the LEDS off. The function takes advantage of for() loops and 
 * the array to do this with minimal typing. 
/*****************************************************************/
void oneAfterAnother()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                       // make this smaller for faster switching

  // Turn all the LEDs on:  
  for(index = 0; index <= 7; index = ++index)  // step through index from 0 to 7
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);                
  }                                  

  // Turn all the LEDs off: 
  for(index = 7; index >= 0; index = --index)  // step through index from 7 to 0
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }               
}
 
/*****************************************************************
 * oneOnAtATime()
 * 
 * This function will step through the LEDs, lighting only one at
 * a time. It turns each LED ON and then OFF before going to the 
 * next LED.
/****************************************************************/

void oneOnAtATime()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                       // make this smaller for faster switching
  
  for(index = 0; index <= 7; index = ++index)   // step through the LEDs, from 0 to 7
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}

/*****************************************************************
 * pingPong()
 * 
 * This function will step through the LEDs, lighting one at at 
 * time in both directions. There is no delay between the LED off
 * and turning on the next LED. This creates a smooth pattern for
 * the LED pattern.
/****************************************************************/
void pingPong()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
   
  for(index = 0; index <= 7; index = ++index)   // step through the LEDs, from 0 to 7
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
 
  for(index = 7; index >= 0; index = --index)   // step through the LEDs, from 7 to 0
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}

/*****************************************************************
 
void marquee()
{
  int index;
  int delayTime = 200; // milliseconds to pause between LEDs
 
  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)
  
  for(index = 0; index <= 3; index++) // Step from 0 to 3
  {
    digitalWrite(ledPins[index], HIGH);    // Turn a LED on
    digitalWrite(ledPins[index+4], HIGH);  // Skip four, and turn that LED on
    delay(delayTime);                      // Pause to slow down the sequence
    digitalWrite(ledPins[index], LOW);     // Turn the LED off
    digitalWrite(ledPins[index+4], LOW);   // Skip four, and turn that LED off
  }
}

/*****************************************************************
 * randomLED()
 * 
 * This function will turn on random LEDs. Can you modify it so it
 * also lights them for random times?
/****************************************************************/
void randomLED()
{
  int index;
  int delayTime;
  
  index = random(8);  // pick a random number between 0 and 7
  delayTime = 100;
  
  digitalWrite(ledPins[index], HIGH);  // turn LED on
  delay(delayTime);                    // pause to slow down
  digitalWrite(ledPins[index], LOW);   // turn LED off
}
