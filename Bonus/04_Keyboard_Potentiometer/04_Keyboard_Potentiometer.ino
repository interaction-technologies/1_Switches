// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Pin for button
const int pot_pin = A5; 

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

int last_val = 0;

void loop(){

	int current_val = analogRead(pot_pin);

	// If the value is different to the last printed value
	if(last_val != current_val){
		Keyboard.println(current_val);
		last_val = current_val;
	}
}
