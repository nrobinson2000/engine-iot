#include "spark-dallas-temperature/spark-dallas-temperature.h"
#include "OneWire/OneWire.h"
#include "Particle.h"

SYSTEM_MODE(SEMI_AUTOMATIC);
SYSTEM_THREAD(ENABLED);

DallasTemperature dallas(new OneWire(D3));

double lastTemp;
double tempF;

String tempFString;

int brightness;

inline void softDelay(uint32_t msDelay)
{
  for (uint32_t ms = millis(); millis() - ms < msDelay; Particle.process());
}

int ledToggle(String command)
{
  if (command == "ON")
  {
    digitalWrite(A0, HIGH);
    return 1;
  }
  else
  {
    digitalWrite(A0, LOW);
    return 0;
  }
}

void setup() // Put setup code here to run once
{

pinMode(A5, OUTPUT);
digitalWrite(A5, HIGH);
pinMode(A1, INPUT);
pinMode(A0, OUTPUT);

dallas.begin();

Serial.begin(115200);

Particle.variable("brightness", brightness);
Particle.variable("temperature", tempFString);

Particle.function("ledToggle", ledToggle);

Particle.connect();
}

void loop() // Put code here to loop forever
{
  brightness = analogRead(A1);
  brightness = map(brightness, 0, 4095, 0, 100);

  dallas.requestTemperatures();
  tempF = dallas.getTempFByIndex(0);

  if (tempF >= -190) (lastTemp = tempF);
  if (tempF <= -190) (tempF = lastTemp);

  tempFString = String(tempF, 2);

  Serial.printlnf("Temperature: %.2f\t Brightness: %d%%", tempF, brightness);
  softDelay(500);
}
