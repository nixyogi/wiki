## Summary for the camera sensor 

insert the table here 
name mp type Ports Output format FPS


MIPI CSI summary 
1. MIPI is an alliance and CSI is a camera interface.

The CSI port is a combination of 3 different ports.
1. The Data lines 
2. I2C for control 
3. Extra GPIO pins for other purposes 

Functional Block Diagram 
The flow of the camera is 
driver sends commands via i2c and these commands get stored in a control register (memory)
This activates the camera sensor which captures the image and processes it and produces the final output at the MIPI port
