# Cropping an image 

OpenCV does not provide a direct function to crop the image. Rather it is done 
using this logic.

To crop the image we do,
1. Define the area (rectangle) that we want to crop.
2. Copy the defined area into another `Mat cropped_image`

#### Define the area that we want to crop 
Typically the area is a rectangle, to define a rectangle area in our image we need 
1. The x, y co-ordinates of the top-left point of the rectangle
2. The height and width of the rectangle.

To do this in OpenCv we use 
```c
/* Create an Rectangle area for cropping (region of interest) */
Rect roi(x, y, width, height);
```

#### Copy the defined area into another `Mat cropped_image`
To do this in OpenCV you use 
```c
/* Crop the image along the roi rectangle 
 * Store it in another Mat 
 */
out_image = in_image(roi).clone();
```

**Usage** : 

Lets say you want to crop a square of 80 pixels from point (pixel) (10,30) in the image , then you do 
```c
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR)
/* Create an Rectangle area for cropping (region of interest) */
Rect roi(10, 30, 80, 80);

/* Crop the image along the roi rectangle 
 * Store it in another Mat 
 */
out_image = in_image(roi).clone();
```
