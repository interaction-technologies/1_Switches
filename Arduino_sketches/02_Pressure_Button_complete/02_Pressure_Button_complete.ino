// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Pin for button
const int pressure_pin = A3; 

// Thresholds for triggering switch
// We use two values to avoid de-bounce the switch
const int press_threshold = 300;
const int release_threshold = 400;

// Keeping track of whether we sent the message or not yet
bool message_sent = false;

void setup() {
  
   // ⚠ Safety stop!
   // Program will not begin unless pin 12 connected to GND
   pinMode(12, INPUT_PULLUP);
   while(digitalRead(12)==HIGH){
      // do nothing!
      delay(500);
   }

	// Set pressure pin
	pinMode(pressure_pin,INPUT_PULLUP);
}

void loop() {
	// Read and loop sensor value
	int sensor_value = analogRead(pressure_pin);

	if(sensor_value < press_threshold){
		// Pressure switch is being pressed
		if(!message_sent){
		Keyboard.write('a');
		message_sent = true;
		}
	}else if(sensor_value > release_threshold){
		// Pressure switch is not pressed
		message_sent = false;
	}
}