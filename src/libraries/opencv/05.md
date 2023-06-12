# Reading and capturing an image 

## Reading an image from the file 
OpenCV provides `imread()`  function to read a image from the storage (hardisk or SD).

Usage: 
```c
/* Read from the file */
Mat in_image = imread("logo.png", CV_LOAD_IMAGE_COLOR);
        if (in_image.empty()) { 
                /* Check if read successful */
                cout << "Error! Input image cannot be read...\n";
                return -1;
        }
```

## Writing an image from the file 
OpenCV provides `imwrite()` function to write the image to a file.

Usage: 
```c
/* Write image to file */
imwrite("out.png", out_image); 
/* Note: the out_image is a Mat variable with some values */
```

## Show the image to the user
OpenCV provides `imshow()` function to show the image to the user by creating a window. But this function is not persistent (the window closes before the user can see it). To make it persistent we use `waitkey()` function.

Usage: 
```c
/* Shows output image on window */
imshow("Flipped", out_image); 

/* Let the user know how to close the windows */
cout << "Press any key to exit...\n";
/* Wait infinitely for key press */
waitKey(); 
```

## Capture a live video 
OpenCV provides `Videocapture` class function to capture a live video from 
the webcam or any connected camera device. 


Usage: 
```c
// Create a VideoCapture object and open the input file
// If the input is the web camera, pass 0 instead of the video file name
VideoCapture cap(0); 

// Check if camera opened successfully
if(!cap.isOpened()){
        cout << "Error opening video stream or file" << endl;
        return -1;
}

while(1){

        Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
                break;

        // Write your processing code here 
}
```
