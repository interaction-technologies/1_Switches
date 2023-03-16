// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Include Bounce2 library by Thomas O Fredericks
#include <Bounce2.h>

// Debouncers for buttons
Bounce button1 = Bounce();
Bounce button2 = Bounce();

void setup(){

	// ⚠ Safety stop!
	// Program will not begin unless pin 12 connected to GND
	pinMode(12, INPUT_PULLUP);
	while(digitalRead(12)==HIGH){
		// do nothing!
		delay(500);
	}

	// Attach pins A3 and A4 to debouncers
	button1.attach(A3,INPUT_PULLUP);
	button2.attach(A4,INPUT_PULLUP);

	// Start keyboard
	Keyboard.begin();

}

void loop(){

	// Update debouncers
	button1.update(); 
	button2.update(); 

	// If buttons were released
	if(button1.rose()) { 
		Keyboard.write(KEY_LEFT_ARROW);
	}
	if(button2.rose()) { 
		Keyboard.write(KEY_RIGHT_ARROW);
	}
}