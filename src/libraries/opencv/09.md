# Histogram 

A histogram is representation of the frequency of the values of pixels. 

Mathematically A histogram is a Table where Entry 0 will contain number of pixels that have `0` value, Entry 1 will contain number of pixels that have `1` value, so on..   

## Compute Histogram in OpenCV 
OpenCV Provides a function to calculate Histogram of any one channel 
```c
calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, 0);
```
Here is the snippet on how to use the function
```c
Mat hist, image;

//Read original image
Mat src = imread("img.jpg");

//Convert color image to gray level image
cvtColor(src, image, CV_RGB2GRAY);

/**
 * Calculate the histogram 
 */
calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, 0);
``` 

To know more, [click here](https://docs.opencv.org/3.4.8/d6/dc7/group__imgproc__hist.html#ga4b2b5fd75503ff9e6844cc4dcdaed35d).


## Equalizing the Histogram
Equalizing means all the table entries of the Histogram must contain equal number of pixels. 

> **Note**: Practically this is not possible so practically the hidtogram equalization tries to do equalize the table entries at its best without deforming the image.

OpenCV provides ready functions for to use
```c
// Equalize the histogram
equalizeHist( image, result );
```
For Example :
```c
Mat hist, image, result;

//Read original image
Mat src = imread("img.jpg");

//Convert color image to gray level image
cvtColor(src, image, CV_RGB2GRAY);

// Equalize the histogram
equalizeHist( image, result );
```

To know more, [click here](https://docs.opencv.org/3.4.8/d6/dc7/group__imgproc__hist.html#ga7e54091f0c937d49bf84152a16f76d6e).

## Practical uses of Histogram equalization 
1. Enhance the image 
2. Adjust Brightness and Contrast 
3. Pre-process the image for edge detection
