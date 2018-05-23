/* Lesson 1:
 * Part 1: Intro
 * Part 2: Blink
 * Part 3: Button -> LED
 */

#include "Particle.h"

SYSTEM_MODE(MANUAL); // This tells the Photon to not use the Internet

void setup() // Put setup code here to run once
{
  // Part 1: Intro
  pinMode(D7, OUTPUT); // instructs the Photon to initialize pin D7, setting it as an OUTPUT.
  digitalWrite(D7, HIGH); // instructs the Photon to write the HIGH value to D7, a Digital output operation.

  // Part 2: Blink
  pinMode(D7, OUTPUT); // makes D7 an OUTPUT just like the last part

  // Part 3: Button -> LED
  pinMode(D7, OUTPUT);
  pinMode(D0, INPUT_PULLUP);

}

void loop() // Put code here to loop forever
{
  // Part 2: Blink
  digitalWrite(D7, HIGH); // turn D7 LED on
  delay(1000);            // wait 1000 milliseconds (1 second)
  digitalWrite(D7, LOW);  // turn D7 LED off
  delay(1000);            // wait 1 second

  // Part 3 Button -> LED
  if ( digitalRead(D0) == LOW ) { // The button is LOW when pressed
    digitalWrite(D7, HIGH); // The LED will be on while button is pressed
  }
  else {
    digitalWrite(D7, LOW); // The LED will be off when button is not pressed
  }
}
