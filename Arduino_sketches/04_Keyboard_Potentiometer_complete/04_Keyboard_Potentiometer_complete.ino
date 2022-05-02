// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

// Pin for button
const int pot_pin = A5; 

// Maximum number to print
const int max_value = 7;

// Tolerance to detect a change in the dial
const int tolerance = 4;

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
int last_char = 0;

void loop(){

   int current_val = analogRead(pot_pin);

   // Scale value from 0->1023 to 0->max_value (e.g. 8)
   int current_char = map(current_val,0,1023,0,max_value);
   
   // Has dial moved more than the tolerance?
   if((current_val > last_val+tolerance) || (current_val < last_val-tolerance)){
      // If the character is different to the last printed one
      if(last_char != current_char){
         Keyboard.println(current_char);
         last_val = current_val;
         last_char = current_char;
      }
   }

}
