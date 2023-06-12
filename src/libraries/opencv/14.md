# Motion and Tracking 

## Optical Flow
A picture is the representation of pattern of brightness observed by the image 
sensor. 

So to track motion in a video we check the change in the brightness pattern from frame to frame of the video. 

The motion (direction) of the change in brightness pattern from frame to frame 
is called as optical flow. 


In simpler terms, Optical Flow is the direction of he pixel that moved in the new frame.


There are many different methods of the Optical Flow.

1. Lukas-Kanade Optical Flow
2. Gunnar-Farneback Optical Flow 


## Object Tracker
Object Tracker is tracking(estimating the position) the given object in the next frame. 

This is done by creating a grid over the object in the reference frame and then applying optical flow to track where all these points in the grid moved to.
