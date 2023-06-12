# Accessing Pixels and other basic necessary properties of an image  

## Accessing individual Pixels of an image  
OpenCV `Mat` class provides `.at()` operator through which you can access and change individual pixels of a particular channel(B, G, or R channel).

Usage :
```c
/* Read the image */
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR);

/* Define the datatype for one pixel */
Vec3b pixel1 = in_image.at<Vec3b>(100,100));

/* Print BGR values of the pixel at 100th row and 100th col of the image */ 
cout << "Given pixel (B):" << (unsigned int)pixel1[0] << endl;
cout << "Given pixel (G):" << (unsigned int)pixel1[1] << endl;
cout << "Given pixel (R):" << (unsigned int)pixel1[2] << endl;
```

## Get the Size of the image 
OpenCV `Mat` class provides `.size()` operator through which you can get the size of the image.

Usage :

```c
/* Read the image */
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR);

/*Print size for the image read */
Size siz = in_image.size();

cout << "Size of the Image" << endl;
cout << "Width:" << siz.width << endl;
cout << "Height:" << siz.height << endl; 
```

img.size() - will tell you the size of the image read 

## Get the number of channels in an image 
OpenCV `Mat` class provides `.channels()` operator through which you can get the channels of the image.
```c
/* Read the image */
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR);

/*Print channels of the image read */
int ch = in_image.channels();
cout << "Image channels:" << ch << endl;

```
## Get the Bit depth of the image 
OpenCV `Mat` class provides `.depth()` operator through which you can get the bit depth of the image in terms of the `CV_8U` datatypes.

```c
/* Read the image */
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR);

/*Print pixel depth image read */
int d = in_image.depth();
cout << "Image depth:" << d << endl;
```

10. .clone()
## Copy the image to another variable 
OpenCV `Mat` class provides `.clone()` operator through which you can copy one image to another variable.

```c
/* Read the image */
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR);

/* Copy Input image to out variable */
Mat out = in_image.clone();
```

# Color space conversion
OpenCV provides one function `cvtColor()` which can convert the colorspace of the image to predefined desired colorspaces. 

You only need to change the 3rd argument to get the same image in different color spaces. 

Usage : This example shows one image getting converted to 4 different color spaces 
```c
// Define variables to store the image 
Mat image, HSV, Luv, Lab, YCrCb, XYZ, Rimg, Bimg, Gimg;

//Read image
image = imread("02.jpg", CV_LOAD_IMAGE_COLOR);

//Convert RGB image to different color spaces
cvtColor(image, HSV, CV_BGR2HSV);
cvtColor(image, Luv, CV_BGR2Luv);
cvtColor(image, Lab, CV_BGR2Lab);
cvtColor(image, YCrCb, CV_BGR2YCrCb);
cvtColor(image, XYZ, CV_BGR2XYZ);
```
