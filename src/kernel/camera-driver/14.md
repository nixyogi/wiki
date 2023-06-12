# V4l2 subdevices 

Sub devices are treated as devices and they have their own device data 
structure and their own functions (operations)

# v4l2 media entity init
If we want to use a media framework with the v4l2 subdevice then we need to do initialize the media entity, using media entity init. 

# V4l2 ctrl handler 

V4l2 ctrl handler is nothing but the controls provided by the device driver to the userspace.

All the user operations are mapped to the driver functions in this v4l2 ctrl operations, and a switch case.

# V4l2 async register 
Registers the camera device driver with the kernel.
