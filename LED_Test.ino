
/*
3D Printable, Bluetooth controlled and low cost Robotic bartender - DIY Machines
https://diymachines.co.uk/projects/how-to-build-an-arduino-diy-robotic-bartender.html

Build yourself a low-cost easy to assemble bluetooth controllable robotic bartender using an Arduino Uno.
This easy Arduino based project can be 3D printed and is a cool Arduino project for beginners.

==========
The code and wiring diagram can be downloaded from here: https://diymachines.co.uk/projects/how-to-build-an-arduino-diy-robotic-bartender.html
3D printed parts can be downloaded from here:  https://www.thingiverse.com/thing:2478890
==========
SAY THANKS:
Buy me a coffee to say thanks: https://ko-fi.com/diymachines
Support us on Patreon: https://www.patreon.com/diymachines

*/


//---------------------

// Below is for the RGB LED

int greenPin = 10;
int bluePin = A1;
int redPin = 9;


void setup() {

  // initialize the LED as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);

// For LED

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

//-------------------------------

}


void loop(){ 
  
  Serial.println("The LED should be red.");
  setColor(255, 0, 0);  // red
  delay(1000);
  
  Serial.println("The LED should be blue.");
  setColor(0, 255, 0);  // blue
  delay(1000);
  
  Serial.println("The LED should be green.");
  setColor(0, 0, 255);  // green
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
