#include <I2C.h>

// uncomment this line if you want to use Wire.h instead
//#include <Wire.h>
#include <MAX44009.h>

MAX44009 light;
 
void setup() {
  

  light.begin();
  
  delay(500);

  Serial.begin(9600);
 
  delay(500);
 
}
 
void loop() {
 

 Serial.print("Light (lux):    ");
 Serial.println(light.get_lux());
 delay(1000);

}
