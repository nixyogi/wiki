# Contours 
Contours define the boundary of a shapes 

## Detecting Contours

Contours can be detected using these methods

1. Canny edge detectors 
2. Hough lines 
3. Hough circles 
4. Line Segment Detector

### Canny Edge Detector 

Canny algorithm uses hysteresis thresholding 
At its core it uses Sobel filters 

This is how I understand what Canny does 

Canny actually applies Sobel filter for the low 
threshold 

Since the threshold is low, edges + some other noise will
remain in the image after the filter. 

Then it applies Sobel filter for the High threshold

Which will still detect the edges but the noise will 
be gone (also these edges will start to fade)

Then it combines the 2 edge maps outputs together to form the 
actual map. 

It also does another trick to get the desired output fast and efficiently 

It removes all the edge points whose gradients are not
perpendicular to each other this makes the edge maps thin

Syntax : 
```c
// Apply Canny algorithm
Mat contours;
Canny(input,      // gray-level image
      contours, // output contours
      125,      // low threshold
      130);     // high threshold
```

Usage : 
```c
// Apply Canny algorithm
Mat contours;
Canny(input,      // gray-level image
      contours, // output contours
      125,      // low threshold
      130);     // high threshold
```


## Extracting Components 
OpenCv provides a function to extract components using `findContours()` function

This systematically scans the image until it hits 
a contour.

Then it follows the contour until it gets complete

Then starts scanning again

Thus by the end of the operation all the contours 
can be detected.

Syntax: 
```c
/ Scan the image to find contours /
findContours(input,                   // input image 
             contours,                  // a vector of contours
             CV_RETR_LIST,          // retrieve all contours
             CV_CHAIN_APPROX_NONE); // all pixels of each contours
```

Usage : 
```c
/ Scan the image to find contours /
findContours(tri,                   // input image 
             cont,                  // a vector of contours
             CV_RETR_LIST,          // retrieve all contours
             CV_CHAIN_APPROX_NONE); // all pixels of each contours
```

## Drawing Contours 

OpenCV provides an inbuilt function for drawing contours
called `drawContours()`.

We can use it to draw detected contours on an image and then 
show it to the user or use it for further processing.

Syntax: 
```c
drawContours(result, // Result image
             Contours,   // Contours vector
             -1,     // draw all contours (how many contours to draw ?)
             0,      // in black (line color)
             1);     // with a thickness of 2 (line thickness)
```

Usage :
```c
// draw black contours on a white image
// Define an white image with correct size
cv::Mat result(tri.size(), CV_8U, cv::Scalar(255));

//Draw the contours using that we got using findContours
drawContours(result, // Result image
             cont,   // Contours vector
             -1,     // draw all contours (how many contours to draw ?)
             0,      // in black (line color)
             1);     // with a thickness of 2 (line thickness)

```
