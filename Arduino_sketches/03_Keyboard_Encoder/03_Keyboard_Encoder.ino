// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Install the library "Encoder" by Paul Stoffregen
// https://www.pjrc.com/teensy/td_libs_Encoder.html
#include <Encoder.h>

// Create Encoder
Encoder myEnc(2,3);

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
   long current_position = myEnc.read();
   if (current_position != last_position){
      Keyboard.println(current_position);
      last_position = current_position;
   }
}
