#include "SparkJson/SparkJson.h"
#include "Particle.h"

SYSTEM_MODE(SEMI_AUTOMATIC); // Disable the Particle Cloud until we do Particle.connect()
SYSTEM_THREAD(ENABLED); // Enable multithreading

inline void softDelay(uint32_t msDelay)
{
  for (uint32_t ms = millis(); millis() - ms < msDelay; Particle.process());
}

int brightness;
double temperature;

void subscribeHandler(const char *event, const char *data)
{

char *mutableData = strdup(data);

  StaticJsonBuffer<1000> jsonBuffer;
  	JsonObject& root = jsonBuffer.parseObject(mutableData);

    if (!root.success()) {
    		Serial.println("parseObject() failed");
    	    return;
    	}

brightness = atoi(root["brightness"].asString());
temperature = atof(root["temperature"].asString());

Serial.printlnf("Temperature: %.2f\t Brightness: %d%%", temperature, brightness);

}

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

  return 0;
}

void setup() // Put setup code here to run once
{

pinMode(A0, INPUT_PULLUP);
pinMode(D7, OUTPUT);

Serial.begin(115200);

Particle.subscribe("engineReading", subscribeHandler);

Particle.function("setLight", toggleLight);

Particle.connect();

}

void loop() // Put code here to loop forever
{

  if (digitalRead(A0) == false)
  {
    Particle.publish("engine-button");
    softDelay(250);
  }

}
