const int temperaturePin = A1; //Analog pin A1 will be used to get the analog vaue of the temp sensor


void setup() //Initialization
{

  Serial.begin(9600); //Initialize/ Begin serial monitor
}


void loop() //Loop with no condition (loops and essentially resets temp according to delay basically refreshes)
{


  float voltage, degreesC, degreesF; //Declare 3 floating point variables

  voltage = getVoltage(temperaturePin); //Measure the voltage at the analog pin

  degreesC = ((voltage - 0.5) * 32)-4; // Convert the voltage to degrees Celsius

  degreesF = degreesC * (9.0 / 5.0) + 32.0; //Convert degrees Celsius to Fahrenheit
  

  
  
  Serial.print("voltage: "); 
  Serial.print(voltage);   //Printing Voltage
  Serial.print("  deg C: ");
  Serial.print(degreesC);  //Printing the Temp in degrees Celcius
  Serial.print("  deg F: ");
  Serial.println(degreesF); //Printing the Temp in degrees Fahrenheit

 //For example  "voltage: 0.56 deg C: 26.76 deg F: 80.17"

  delay(1000); // delay of 1000 miliseconds
}


float getVoltage(int pin)   //Function to read and return floating-point value (true voltage) on analog pin 
{

  return (analogRead(pin) * 0.004882814); 
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value which is the voltage being read at that pin.
}
