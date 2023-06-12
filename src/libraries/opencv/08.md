# Image Filtering 

The principle of the Iamge filtering is that the center pixel is the average 
of all the other adjacent/neighboring pixels. The *number of neighboring pixels* to average are defined by the `kernel size of the filter`. 
 
The kernel value defines the weights by which each pixel gets
multiplied and then the average of these pixels is taken.

The difference between various filters in the Kernel values, these kernel 
values can be generated using different Statical formulas like Gaussian, 
Median, bilateral etc.  


To apply Filters there are 2 methods 

1. Applying filters with predefined kernels
2. Applying filters with user defined kernels 


## Applying filters with predefined kernels

OpenCV Defines these filters by default 

1. blur 
2. gaussianBlur 
3. MedianBlur
4. BoxFilter
5. bilateralFilter 

## Applying filters with user defined kernels 
I am finding it hard to explain via words hence check it out with code
```c
/**
 * ####################################################################
 *  Applying your own filter by defining your own kernel
 * ####################################################################
 */

// Construct kernel (all entries initialized to 0) 
Mat kernel(3,3,CV_32F,cv::Scalar(0)); 

/**
 * Kernel that I have defined is 
 * 
 * [ 0, -1, 0 ]
 * [-1,  5,-1 ]
 * [ 0, -1, 0 ]
 * 
 * Apparently this kernel sharpens the image 
 * 
 */
// assigns kernel values 
kernel.at<float>(1,1)= 5.0; 
kernel.at<float>(0,1)= -1.0; 
kernel.at<float>(2,1)= -1.0; 
kernel.at<float>(1,0)= -1.0; 
kernel.at<float>(1,2)= -1.0; 

//filter the image 
filter2D(image,result,image.depth(),kernel); 

namedWindow( "Filtered 1", 0 );

/* Show the image */
imshow("Filtered 1", result); // Shows output image on window
```

## Practical uses of Filtering 
1. Blur the image 
2. Sharpen the image 
3. Segmentation
4. Filtering Edges 
5. Skin Detection 
6. Pre-processing for thresholding
