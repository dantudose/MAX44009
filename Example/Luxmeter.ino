#include <Wire.h>
#include <MAX44009.h>

MAX44009 light;
 
void setup() 
{
	if(light.begin())
  	{
    		Serial.println("Could not find a valid MAX44009 sensor, check wiring!");
		while(1);
	}

	delay(500);
	Serial.begin(9600);
	delay(500);
}
 
void loop() 
{
	Serial.print("Light (lux):    ");
	Serial.println(light.get_lux());
	delay(1000);
}
