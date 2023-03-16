// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Install the library "Encoder" by Paul Stoffregen
// https://www.pjrc.com/teensy/td_libs_Encoder.html
#include <Encoder.h>

// Create Encoder
Encoder myEnc(2,3);

// Clockwise and counter-clockwise characters
const char cw_char = '>';
const char ccw_char = '<';

void setup(){

	// ⚠ Safety stop!
	// Program will not begin unless pin 12 connected to GND
	pinMode(12, INPUT_PULLUP);
	while(digitalRead(12)==HIGH){
		// do nothing!
		delay(500);
	}

	// Start keyboard
	Keyboard.begin();
}

long last_position = 0;

void loop() {
	// Divide by 4 because of 4 encoder pulses per detent
	long current_position = (myEnc.read()/4);

	if (current_position > last_position){
		// If new position greater than last position, moving CW
		Keyboard.write(cw_char);
		last_position = current_position;
	}else if(current_position < last_position){
		// If new position greater than last position, moving CCW
		Keyboard.write(ccw_char);
		last_position = current_position;
	}
}
