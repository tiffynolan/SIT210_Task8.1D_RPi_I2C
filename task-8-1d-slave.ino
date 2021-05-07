// This #include statement was automatically added by the Particle IDE.
#include <I2CSlaveRK.h>
//https://docs.particle.io/tutorials/learn-more/about-i2c/
//https://github.com/rickkas7/I2CSlaveRK/blob/master/examples/1-slave-simple/1-slave-simple.cpp

//Setup this argon as an I2C device, address 0x10, with 10 uint32 registers
I2CSlave device(Wire, 0x10, 10);

unsigned long counter = 0; // To compare to millis, need unsigned long as millis() is unsigned long

void setup() 
{
    Serial.begin(9600); 
    device.begin();
}


void loop() 
{
    //Sends data once ever 5 seconds
    if(millis() - counter >= 5000) //millis() returns the number of milliseconds since the device began running the current program
    {
        counter = millis();
        
        //Random number between 0-100 is sent to Raspberry Pi
        device.setRegister(0, random(100));
    }
}