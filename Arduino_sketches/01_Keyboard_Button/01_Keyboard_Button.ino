// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Pin for button
const int button_pin = A3; 

void setup(){

	// ⚠ Safety stop!
	// Program will not begin unless pin 12 connected to GND
	pinMode(12, INPUT_PULLUP);
	while(digitalRead(12)==HIGH){
		// do nothing!
		delay(500);
	}

	// Set push button pin
	pinMode(button_pin, INPUT_PULLUP);

	// Start keyboard
	Keyboard.begin();

}

void loop(){
	// If button pushed, print character 'a'
	if(digitalRead(button_pin) == LOW){
		Keyboard.write('a');
	}
}