//RGB LED Slow Swell Display
//Mike Landry 2015


// Pin Definitions

//Knob input
const int swellPin = A4;


//RGB LED Pin Number Assignment
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;


int swellTime = 0;
int colorValue = 0;
int newColorValue = 0;
int delayDiv = 0;

//RGB LED Color PWM Values

/* Color reference  

Proposed color order:
Red, Orange, Yellow, Green, Blue, Indigo, Purple, OFF

  setColor(0, 0, 0); // "black"
  setColor(255, 0, 0);  // red
  setColor(172, 251, 0);  // orange
  setColor(255, 255, 0);  // yellow
  setColor(0, 255, 0);  // green
  setColor(0, 255, 255);  // aqua
  setColor(0, 0, 255);  // blue
  setColor(80, 0, 80);  // purple
  setColor(0, 0, 0); // "black"

*/


//color arrays = (Previous R, Previous G, Previous B, New R, New G, New B, Delay time divisor)
//Delay time divisor splits delay time for each color between number of PWM changes

const int blkI[7] = {0, 0, 0, 0, 0, 0, 1};
const int red[7] = {0, 0, 0, 255, 0, 0, 1};
const int org[7] = {255, 0, 0, 172, 251, 0, 2};
const int ylw[7] = {172, 251, 0, 255, 255, 0, 2};
const int grn[7] = {255, 255, 0, 0, 255, 0, 1};
const int aqu[7] = {0, 255, 0, 0, 255, 255, 1};
const int blu[7] = {0, 255, 255, 0, 0, 255, 1};
const int ind[7] = {0, 0, 255, 75, 0, 130, 2};
const int prp[7] = {75, 0, 130, 80, 0, 80, 2};
const int blkF[7] = {0, 0, 0, 0, 0, 0, 1};



void setup()
{

pinMode(swellPin, INPUT);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);

}



void loop()
{

colorSwell();

// The above function turns the individual LEDs full-on and
// full-off. If you want to generate more than eight colors,
// you can do so by varying the brightness of the individual
// LEDs between full-on and full-off.

// The analogWrite() function lets us do this. This function
// lets you dim a LED from full-off to full-on over 255 steps.

}




void colorSwell()
{

//Total time to loop through each color = ADC voltage * (Arduino Uno 10-bit resolution)
float swellVolt = analogRead(swellPin) * 1/310;
swellTime = swellVolt / 9; 

//Black Initial
setPWMRed(blkI [0], blkI [3], blkI [6]);
setPWMGreen(blkI [1], blkI [4], blkI [6]);
setPWMBlue(blkI [2], blkI [5], blkI [6]);

//Red
setPWMRed(red [0], red [3], red [6]);
setPWMGreen(red [1], red [4], red [6]);
setPWMBlue(red [2], red [5], red [6]);

//orange
setPWMRed(org [0], org [3], org [6]);
setPWMGreen(org [1], org [4], org [6]);
setPWMBlue(org [2], org [5], org [6]);

//yellow
setPWMRed(ylw [0], ylw [3], ylw [6]);
setPWMGreen(ylw [1], ylw [4], ylw [6]);
setPWMBlue(ylw [2], ylw [5], ylw [6]);

//green
setPWMRed(grn [0], grn [3], grn [6]);
setPWMGreen(grn [1], grn [4], grn [6]);
setPWMBlue(grn [2], grn [5], grn [6]);

//aqua
setPWMRed(aqu [0], aqu [3], aqu [6]);
setPWMGreen(aqu [1], aqu [4], aqu [6]);
setPWMBlue(aqu [2], aqu [5], aqu [6]);

//blue
setPWMRed(blu [0], blu [3], blu [6]);
setPWMGreen(blu [1], blu [4], blu [6]);
setPWMBlue(blu [2], blu [5], blu [6]);

//indigo
setPWMRed(ind [0], ind [3], ind [6]);
setPWMGreen(ind [1], ind [4], ind [6]);
setPWMBlue(ind [2], ind [5], ind [6]);

//purple
setPWMRed(prp [0], prp [3], prp [6]);
setPWMGreen(prp [1], prp [4], prp [6]);
setPWMBlue(prp [2], prp [5], prp [6]);

//blackFinal
setPWMRed(blkF [0], blkF [3], blkF [6]);
setPWMGreen(blkF [1], blkF [4], blkF [6]);
setPWMBlue(blkF [2], blkF [5], blkF [6]);

}


void colorChange(int pin) {
	int delayPWM = 0;

	if (colorValue != newColorValue)
	{
		if (colorValue < newColorValue)
		{
			++colorValue;
			analogWrite(pin, colorValue);
			
			delayPWM = ((swellTime/delayDiv)/(newColorValue - colorValue));
			delay(delayPWM);
		}
	
		else // colorValue > newColorValue
		{		
			--colorValue;
			analogWrite(pin, colorValue);
			
			delayPWM = ((swellTime/delayDiv)/(newColorValue - colorValue));
			delay(delayPWM);
		}
	}
}



void setPWMRed(int colorValue, int newColorValue, int delayDiv) 
{
	//Red LED
	//pin = redPin
	colorChange(redPin);
}

void setPWMGreen(int colorValue, int newColorValue, int delayDiv) 
{
	//Green LED
	//pin = greenPin
	colorChange(greenPin);
}

void setPWMBlue(int colorValue, int newColorValue, int delayDiv) 
{
	//Blue LED
	//pin = bluePin
	colorChange(bluePin);

}








/*

OLD CODE
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
*/


