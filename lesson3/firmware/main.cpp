#include "Particle.h"

SYSTEM_MODE(MANUAL); // Disable internet

// Part 1: Servo
Servo myservo;

// Part 2: PIR Sensor
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;

void setup() // Put setup code here to run once
{

  // Part 1: Servo
  myservo.attach(A4);
  pinMode(A0, INPUT);

  // Part 2: PIR Sensor
  pinMode(A2, INPUT);
  pinMode(D7, OUTPUT);
  Serial.begin(115200);

}

void loop() // Put code here to loop forever
{

  // Part 1: Servo
  int reading = analogRead(A0);
  int position = map(reading, 0, 4095, 0, 180);
  myservo.write(position);

  // Part 2: PIR Sensor
  val = digitalRead(A2);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(D7, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(D7, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

}
