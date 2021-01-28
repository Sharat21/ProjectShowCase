
int datapin = 2; //set to pin 2
int clockpin = 3;// set to pin 3
int latchpin = 4; //set to pin 4

// We'll also declare a global variable for the data we're
// sending to the shift register:

byte data = 0;


void setup()
{
  // Set the three SPI pins to be outputs:

  pinMode(datapin, OUTPUT); //Initliaze as an Ouput
  pinMode(clockpin, OUTPUT);  //Initliaze as an Ouput
  pinMode(latchpin, OUTPUT);//Initliaze as an Ouput
}


void loop()
{
  
  oneAfterAnother();      // All on, all off
  
  //oneOnAtATime();       // Scroll down the line
  
  //pingPong();           // Like above, but back and forth

  //randomLED();          // Blink random LEDs
  
  //marquee();

  //binaryCount();        // Bit patterns from 0 to 255
}


void shiftWrite(int desiredPin, boolean desiredState)
{
// This function lets you make the shift register outputs
// HIGH or LOW in exactly the same way that you use digitalWrite().

  bitWrite(data,desiredPin,desiredState); //Change desired bit to 0 or 1 in "data"
  
  // Now we'll actually send that data to the shift register.
  // The shiftOut() function does all the hard work of
  // manipulating the data and clock pins to move the data
  // into the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data); //Send "data" to the shift register

  //Toggle the latchPin to make "data" appear at the outputs
  digitalWrite(latchpin, HIGH); 
  digitalWrite(latchpin, LOW); 
}


void oneAfterAnother()
{
// This function will turn on all the LEDs, one-by-one,
// and then turn them off all off, one-by-one. 

  int index;
  int delayTime = 100; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching

  // Turn all the LEDs on
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);                
  }

  // Turn all the LEDs off
  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, LOW);
    delay(delayTime);
  }
}


void oneOnAtATime()
{
// This function will turn the LEDs on and off, one-by-one. 
  int index;
  int delayTime = 100; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++) //condition set to go <= 7
  {
    shiftWrite(index, HIGH);  // turn LED on
    delay(delayTime);   // pause to slow down the sequence
    shiftWrite(index, LOW); // turn LED off
  }
}

void pingPong()
{
// This function turns on the LEDs, one at a time, in both directions. 
  int index;
  int delayTime = 100; // time (milliseconds) to pause between LEDs
                       // make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);  // turn LED on
    delay(delayTime);   // pause to slow down the sequence
    shiftWrite(index, LOW); // turn LED off
  }

  // step through the LEDs, from 7 to 0
  
  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, HIGH);  // turn LED on
    delay(delayTime);   // pause to slow down the sequence
    shiftWrite(index, LOW); // turn LED off
  }
}

void randomLED()
{
// This function will randomly turn on and off LEDs. 
  int index;
  int delayTime = 100; // time (milliseconds) to pause between LEDs
                       // make this smaller for faster switching
  
  index = random(8);  // pick a random number between 0 and 7
  
  shiftWrite(index, HIGH);  // turn LED on
  delay(delayTime);   // pause to slow down the sequence
  shiftWrite(index, LOW); // turn LED off
}

void marquee()
{
// This function will mimic "chase lights" like those around signs.
  int index;
  int delayTime = 200; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching
  
  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)
  
  for(index = 0; index <= 3; index++)
  {
    shiftWrite(index, HIGH);    // Turn a LED on
    shiftWrite(index+4, HIGH);  // Skip four, and turn that LED on
    delay(delayTime);   // Pause to slow down the sequence
    shiftWrite(index, LOW); // Turn both LEDs off
    shiftWrite(index+4, LOW);
  }
}


void binaryCount()
{
// This function creates a visual representation of the on/off pattern
// of bits in a byte. 

  int delayTime = 1000; // time (milliseconds) to pause between LEDs
                        // make this smaller for faster switching
  
  // Send the data byte to the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
  
  // Add one to data, and repeat!
  // (Because a byte type can only store numbers from 0 to 255,
  // if we add more than that, it will "roll around" back to 0
  // and start over).

  data++;

  // Delay so you can see what's going on:

  delay(delayTime);
}
