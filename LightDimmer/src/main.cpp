/**
 * Statement of authorship: I Haiden Murphy (Student #: 000839028) certify that this material
 * is my original work. No other person's work has been used without due acknowledgement. 
**/

#include <Arduino.h>

/**
 * Variables for the potentiometer, led, and button that corrispont to their location 
 * (wire supplying power).
**/
const int meterPin = A0;  //potentiometer pin code
const int buttonPin = D5; //button pin code
const int ledPin = D4;    //led code (on board)
int delaytime = 100;      //delay variable
int state = 0;            //state 
//int buttonOld;
//int buttonNew = 1;
//int iVal;



/**
 * Setup method that prepares the mode values and begins the loop fuction with the Serial.begin
 *  command.
**/
void setup()
{//setup
  Serial.begin(115200); 
  //analogWriteRange(1023); //set default PWM range

  //pinMode sets the functionallity or 'mode' for a pin.
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN_16);

  //pinMode(potentiometerPin, INPUT);
}//setup



/**
 * A function that loops through the code inside. The code inside gives the potentiometer 
 * a range of PWM values and if statments are used to set the power on an or off depending 
 * on the input.
**/
void loop ()  
{//loop
  //val is declared as an int which is set to read the pin of the potentiometer.
  int val = analogRead(meterPin);
  //val becomes mapped by the range PWM values.
  val = map(val, 1, 1024, 1, 255);
  //analog write function reads the led pin and is set to the val value.
  analogWrite(ledPin, val);

  //state is set to become the digital read of the button pin.
  state = digitalRead(buttonPin);
    //checks if the led pin is on or off
    if (state == 0)
    {//if0
      //writes the digital power value HIGH for the led pin
      digitalWrite(ledPin, HIGH);
      //state becomes 1
      state = 1;
    }//if0
    else if (state == 1)
    {//elseif1
      //writes the digital power value HIGH for the led pin
      digitalWrite(ledPin, LOW); //LOW);
      //state becomes 0
      state = 0;
    }//elseif1
    else
    {//else
      digitalWrite(ledPin, LOW);
    }//else
  //added in order to provide more effiecentcy (time) to the loop function.
  delay(1);
}//loop