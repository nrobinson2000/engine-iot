#include "Particle.h"

SYSTEM_MODE(SEMI_AUTOMATIC); // Disable the Particle Cloud until we do Particle.connect()
SYSTEM_THREAD(ENABLED); // Enable multithreading

inline void softDelay(uint32_t msDelay)
{
  for (uint32_t ms = millis(); millis() - ms < msDelay; Particle.process());
}

int reading;

int toggleLight(String input)
{
  if (input == "ON")
  {
    digitalWrite(D7, HIGH);
  }
  else
  {
    digitalWrite(D7, LOW);
  }
}


void setup() // Put setup code here to run once
{

  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
  pinMode(A1, INPUT);

  pinMode(D7, OUTPUT);

  Particle.variable("light", reading);

  Particle.function("setLight", toggleLight);

  // Connect to the Particle Cloud
  Particle.connect();
  // the connection is maintained automatically

}

void loop() // Put code here to loop forever
{

//Particle.publish("light", String(analogRead(A1)));

reading = analogRead(A1);

//delay(4000);


}
