// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Include Bounce2 library by Thomas O Fredericks
#include <Bounce2.h>

// Debouncers for buttons
Bounce button1 = Bounce();

void setup(){

	// ⚠ Safety stop!
	// Program will not begin unless pin 12 connected to GND
	pinMode(12, INPUT_PULLUP);
	while(digitalRead(12)==HIGH){
		// do nothing!
		delay(500);
	}

	// Attach pin A3 to debouncer
	button1.attach(A3,INPUT_PULLUP);

	// Start keyboard
	Keyboard.begin();

}

void loop(){

	// Update debouncers
	button1.update(); 

	// If button was released
	if(button1.rose()) { 
		Keyboard.write(KEY_LEFT_ARROW);
	}
}