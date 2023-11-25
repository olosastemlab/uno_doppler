/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

// digital pin 2 has a doppler radar attached to it
const unsigned char dopplerIn = A0;
int baudRate = 9600;
int loopDelay = 1;
int motionDelay = 500;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(baudRate);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(dopplerIn);

  if( sensorValue > 360 || sensorValue < 345 )
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(motionDelay);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }


  
  // print out the value you read:
  Serial.println(sensorValue);
  delay(loopDelay);        // delay in between reads for stability
}
