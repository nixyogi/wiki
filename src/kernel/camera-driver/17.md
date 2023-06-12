# V4l2 ops 

V4L2 operations contains function pointers to all the operations that the camera can perform for e.g. : Capture an image, capture a video, set the image capture frame size...

These operations are divided into parts 
1. core - core functions e.g. init, exit..
2. video - operations related to the video e.g. capture stream of video or picture. 
3. pads - operations related to the media subsystem pads e.g. : set frame size...

Each of these parts have their own structure.
These structure contain function pointers to respective functions.


# Driver ops 
For every driver there exists operations which are specific to the driver, like for e.g. driver initialization, driver exit, driver association etc.

These operations are stored into a structure which is a collection of function pointers and the functions which perform the operations for the current driver are linked to the structure.

# Probe function
The `probe` function is the function which initializes the camera driver.
Both the camera driver init block and the camera sensor init block that we have discussed in the previous modules are called one by one in the probe function.

# Remove function 

The `remove` function is the function which cleans up the resources used by the driver when the driver exits.

The remove function one by one cleans up all the 
1. structures 
2. allocated memory 
3. operations 

# Match table 
Match table is used to match the driver with the correct device tree node.

This gives the driver its own identity.

# Conclusion 
1. All the functions which perform operations are linked to the V4L2 ops structure. 
2. All the functions which perform initialization and exit of the camera driver are linked to the driver ops structure.
3. Finally the camera driver is linked to the device tree via the match table.
