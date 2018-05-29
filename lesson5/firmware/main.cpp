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

char message[256];

inline void softDelay(uint32_t msDelay)
{
  for (uint32_t ms = millis(); millis() - ms < msDelay; Particle.process());
}

void subscribeHandler(const char *event, const char *data)
{

digitalWrite(D7, !(digitalRead(D7)));



}

void setup() // Put setup code here to run once
{
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
  pinMode(A1, INPUT);

  pinMode(D7, OUTPUT);

  dallas.begin();

  Serial.begin(115200);

  Particle.variable("brightness", brightness);
  Particle.variable("temperature", tempFString);

  Particle.subscribe("engine-button", subscribeHandler);

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

  snprintf(message, sizeof(message), "{\"temperature\":\"%.2f\",\"brightness\":\"%d\"}", tempF, brightness);
  Particle.publish("engineReading", message);

  softDelay(4000);
}
