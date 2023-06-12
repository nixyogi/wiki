# OpenCV Basics 

## What will you learn 
1. Installation steps 
2. Intro to API 
3. Basic Data Types 

## At the end you should be able to 
1. Understand OpenCV Data types  
2. Understand Mat data Type

---

# Installation 

I personally use Ubuntu 16.04 64 bit x86, Hence all these steps are tried and 
tested on my system, I would suggest you to mirror my configuration for 
smoother experience with the course.

Most online resources say to compile OpenCV 3 on Ubuntu, But since I am lazy 
I found out an ppa for OpenCV 3, ppa looks good, I just hope that it does not come back and bite me in my ass later.

Here are the steps for installing openCV 3 on Ubuntu 16.04
```sh
sudo add-apt-repository ppa:lkoppel/opencv
sudo apt-get update
sudo apt install libopencv-calib3d3.2 libopencv-core3.2 libopencv-features2d3.2  libopencv-flann3.2 libopencv-highgui3.2 libopencv-imgcodecs3.2 libopencv-imgproc3.2 libopencv-ml3.2 libopencv-objdetect3.2 libopencv-photo3.2 libopencv-shape3.2 libopencv-stitching3.2 libopencv-superres3.2 libopencv-video3.2 libopencv-videoio3.2 libopencv-videostab3.2 libopencv-viz3.2 libopencv3.2-jni libopencv3.2-java libopencv-contrib3.2 

sudo apt install libopencv-calib3d-dev libopencv-core-dev libopencv-features2d-dev  libopencv-flann-dev libopencv-highgui-dev libopencv-imgcodecs-dev libopencv-imgproc-dev libopencv-ml-dev libopencv-objdetect-dev libopencv-photo-dev libopencv-shape-dev libopencv-stitching-dev libopencv-superres-dev libopencv-video-dev libopencv-videoio-dev libopencv-videostab-dev libopencv-viz-dev libopencv-contrib-dev libopencv-dev
```


# Introduction to OpenCV API
OpenCV program is divided into modules each module is a collection of API's 
related to one particular function in CV.

Most common modules are 

1. core - Contains basic datatypes and Mat type.
2. highgui - provides UI capabilities and video and image capturing capabilities
3. imgproc - includes image processing functions like filtering, color space conversion etc.
4. features2d - Contains API for feature detection, feature matching and feature description 
5. objdetect - Containd API for object detection and predefined classes for (face, eyes, smile etc..)
6. video - Contains API for video analysis like motion and tracking.
7. gpu - Contains API for gpu accelerated algorithms 
8. ml - Contains API for Machine learning tools like classification, regression and data clustering.

# OpenCV Classes 

1. All opencv functions are in one class called `cv`.

# OpenCV DataTypes 

All primitive (basic) datatypes for OpenCV are 
1. bool
2. unsigned char 
3. signed char 
4. unsigned short 
5. signed short 
6. int
7. float 
8. double 
9. Tuple of any of the above data types 

These datatypes are defined by 
```c
CV_<bit depth>{U|S|F}C(<number of channels>)
```   

In the above line,  U, S, F Stand for unsigned, signed and float.

For example : Lets say that you have to represent an 8 bit unsigned value then
you will use this data type  
```c
CV_8U 
``` 
Practically this data type would be used to represent an grayscale pixel 

Lets say you want to do the same for RBG then you would use a Tuple of 3 channels (one for R, G and B) of the 8 bit unsigned integer, so the data type becomes. 
```c
CV_8UC(3)
```

# OpenCV Mat Class 
It is used to store n-dimensional single or multi-channel arrays. 

Practically it can be used to store 
1. real valued vectors or matrices 
2. complex valued vectors ot matrices 
3. Colored images 
4. grayscale images 
5. Histograms 


## Create Mat object 
Use constructor to create Mat objects, syntax for the same is 
```c
Mat(nrows, ncols, type[, fillValue])
```

For example:
You want to store an RGB image of Resolution 640x320 and initialize it with Green color.

```c
Mat img_A (640,320, CV_8UC(3), Scalar(0,255,0))
/* Mat with 640 rows and 320 cols 
with data type 8 bit unsigned Tuple with 3 channels (to store B,G,R values)
Initialized to all pixels containing values of Blue=0, Green=255 and Red=0 
*/
```

Note : Scalar is a type of vec datatype in OpenCV
TODO : Study more of Scalar.
