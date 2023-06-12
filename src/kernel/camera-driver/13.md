# Power on sequence
Sequence of instructions that we follow to power on camera sensor.

Sensor is said to be powered on when we can send initialization instructions 
to the sensor via I2C.

Every sensor has a unique power on sequence.

Power on sequence for OV5647 (as mentioned in the datasheet)
1. Supply power to the camera sensor 
2. Wait for 5ms or more to stabilize the supply
3. Provide clock with correct clock rate to the camera sensor 
4. Wait for 1ms or more for the clock to stabilize the sensor.
5. Wait 20 ms or more until the camera gets ready for accepting instructions via the I2C bus.

# Getting and Setting Clock

The clocks supplied to the camera sensor are all software controlled 

The kernel APIs to control the clock are 
1. devm_clk_get - get the clock resource from the kernel
2. clk_get_rate - get the current rate of the clock from the kernel
3. clk_set_rate - set desired clock rate to the clock 
4. clk_prepare - prepare for starting the clock
5. clk_enable - enable the clock
6. clk_disable - shutdown the clock
7. clk_unprepare -  Unprepare the clock that has been prepared before.

# Getting and Setting the Voltage regulators 

The Voltages supplied to the camera sensor are also software controlled,
The Kernel API's to control the Voltage regulators are :

1. devm_regualtor_bulk_get - get the regulator resource from the kernel
2. regulator_bulk_enable - Enable the regulators (starts supplying voltage) 
3. regualtor_bulk_disable - Disable the regulators (stops supplying voltage)
4. regulator_bulk_free - Free the regulator resources that have been allocated previously.

# Getting and setting the GPIO pins

Many camera's have a reset pin which can be controlled via GPIO, hence the 
driver needs to control these pins via GPIO

The GPIO api for the kernel are 

1. devm_gpiod_get_optional - Initializes the gpio pins 
2. gpiod_set_cansleep - Set the gpio pins to HIGH or LOW when the kernel has a 
possibility to sleep.

# Init Sequence
The init sequence depends upon the camera sensor and the sensor manufacturer, 
This init sequence is a sequence of registers (memory locations) and their 
values that need to be set to make the camera sensor ready for capturing the 
image.
