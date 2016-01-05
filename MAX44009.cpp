#include "MAX44009.h"
#include <math.h>


MAX44009::MAX44009() {}


void MAX44009::begin()
{
	// comment this line if using Wire.h
	I2c.begin();
	
	// uncomment this line if using Wire.h
	// Wire.begin(); 
}

uint8_t MAX44009::read_register(uint8_t addr) {
    
	I2c.write(MAX_ADDR, addr);
    I2c.read(MAX_ADDR, (uint8_t) 1);
    
	return I2c.receive();
}


/* Alternate funtion if using Wire.h

uint8_t MAX44009::read_register(uint8_t addr) {
 
	Wire.beginTransmission(MAX_ADDR);
	Wire.write(addr);
	Wire.endTransmission();
	 
	Wire.requestFrom(MAX_ADDR,1);
	 
	return Wire.read();
}
*/

float MAX44009::get_lux(void)
{
	int luxHigh = read_register(0x03);
	
	int luxLow = read_register(0x04);
	
	int exponent = (luxHigh & 0xf0) >> 4;
	
	int mant = (luxHigh & 0x0f) << 4 | luxLow;
	
	
	return (float)(((0x00000001 << exponent) * (float)mant) * 0.045);
	//return (float)((pow(2,exponent) * mant) * 0.045);
 
}

 
