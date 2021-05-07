import smbus #https://www.engineersgarage.com/raspberrypi/articles-raspberry-pi-i2c-bus-pins-smbus-smbus2-python/
from time import sleep # Import the sleep function from the time module
#https://docs.particle.io/tutorials/learn-more/about-i2c/

#setup the bus
bus = smbus.SMBus(1)
    
while True:
    randAge = bus.read_byte_data(0x10, 1)
    
    if(randAge >= 50):
        print("You are old: " + str(randAge))
    elif(randAge >= 30 and randAge < 50):
        print("You are getting old: " + str(randAge))
    elif(randAge >= 18 and randAge < 30):
        print("You are young: " + str(randAge))
    else:
        print("You are very young: " + str(randAge))
        
    sleep(5)
    
GPIO.cleanup() # when program exits, tidy up