#include "Particle.h"

SYSTEM_MODE(MANUAL); // Disable internet

void setup() // Put setup code here to run once
{

  // Part 1: Analog Output with DAC
  pinMode(A6, OUTPUT);
  analogWrite(A6, 2500);

  // Part 2: Analog Output with PWM
  pinMode(D0, OUTPUT);
  analogWrite(D0, 5);

  // Part 3: Analog Output with a Buzzer
  pinMode(D4, INPUT_PULLUP);
  pinMode(D2, OUTPUT);

  // Part 4: Analog Input from a Potentiometer
  pinMode(A0, INPUT);
  pinMode(A6, OUTPUT);

  // Part 5: Analog Input from a Photo-resistor
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  pinMode(A2, INPUT);
  Serial.begin(115200);

}

void loop() // Put code here to loop forever
{

  // Part 3: Analog Output with a Buzzer
  if ( digitalRead(D4) == LOW ) {
    analogWrite(D2, 150);
  }
  else {
    analogWrite(D2, 0);
  }

  // Part 4: Analog Input from a Potentiometer
  int potReading = analogRead(A0);
  analogWrite(A6, potReading);

  // Part 5: Analog Input from a Photo-resistor
  int lightReading = analogRead(A2);
  Serial.printlnf("lightReading: %d", lightReading);

}
