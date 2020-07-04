
/*
3D Printable, Bluetooth controlled and low cost Robotic bartender - DIY Machines
https://diymachines.co.uk/projects/how-to-build-an-arduino-diy-robotic-bartender.html

==========
The code and wiring diagram can be downloaded from here: https://diymachines.co.uk/projects/how-to-build-an-arduino-diy-robotic-bartender.html
3D printed parts can be downloaded from here:  https://www.thingiverse.com/thing:2478890
==========
SAY THANKS:
Buy me a coffee to say thanks: https://ko-fi.com/diymachines
Support us on Patreon: https://www.patreon.com/diymachines

SUBSCRIBE:
■ https://www.youtube.com/channel/UC3jc4X-kEq-dEDYhQ8QoYnQ?sub_confirmation=1
■ INSTAGRAM: https://www.instagram.com/diy_machines/?hl=en
■ FACEBOOK: https://www.facebook.com/diymachines/
*/

//----------------------

//The below is for the stepper motors

#include <AFMotor.h>
AF_Stepper motor1(48, 1);
AF_Stepper motor2(48, 2);
int distanceToMove = 200;

//---------------------

// Below is for the RGB LED

int greenPin = 10;
int bluePin = A1;
int redPin = 9;

//---------------------

void setup() {

// for the contact switch 

  // initialize the LED as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  
//--------------------------------

//  For the stepper motors

  motor1.setSpeed(600);

//--------------------------------

// For LED

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

//-------------------------------

}


void loop(){ 
  
  Serial.println("Red light and platform moving in one direction");
  setColor(255, 0, 0);  // red
  motor1.step(distanceToMove, FORWARD, SINGLE); 
  motor1.release();

  Serial.println("Green light and platform paused for one second");
  setColor(0, 0, 255);  // green
  delay(1000);

  Serial.println("Blue light and platform moving in the other direction");
  setColor(0, 255, 0);  // blue
  motor1.step(distanceToMove, BACKWARD, SINGLE);
  motor1.release();

  Serial.println("White light and platform paused for one second");
  setColor(180, 180, 180);  // white
  delay(1000);


} 


void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
