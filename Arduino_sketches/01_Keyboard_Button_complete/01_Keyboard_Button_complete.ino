// Include the Keyboard library
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
#include <Keyboard.h>

const int num_buttons = 2;

// Pin for button
const int button_pins[num_buttons] = {A3, A4};

// Save last button states
// We are using INPUT_PULLUP, so button released = LOW
bool button_last_states[num_buttons] = {LOW, LOW};

// Characters to print
int chars[num_buttons] = {KEY_LEFT_ARROW, KEY_RIGHT_ARROW};

void setup(){

   // ⚠ Safety stop!
   // Program will not begin unless pin 12 connected to GND
   pinMode(12, INPUT_PULLUP);
   while(digitalRead(12)==HIGH){
      // do nothing!
      delay(500);
   }
   
   // Set push button pin
   for(int i=0; i<num_buttons; i++){
      pinMode(button_pins[i], INPUT_PULLUP);
   }

   // Start keyboard
   Keyboard.begin();

}

void loop(){

   // Loop for each button
   for(int i=0; i<num_buttons; i++){
      if( (button_last_states[i]==HIGH) && (digitalRead(button_pins[i])==LOW) ){
         // If last state was pressed and now it is released, write character
         Keyboard.write(chars[i]);
      }
      // Save last state of button
      button_last_states[i] = digitalRead(button_pins[i]);
   }
}