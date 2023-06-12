# Features 

## Interest points 
Interest points are sudden changes in intensity in the region.
These local features are usually classified as edges, blobs or corners. 

## List of methods to detect features 
List of methods in OpenCV to detect features or interest points or key points

### Normal Feature detectors  
1. Harris corner detector 
2. FAST feature detector 
3. feature detector class 
4. Adapted feature detection 
5. Grid Adapted feature detection 
6. Pyramid Adapted feature detection 


### Scale invariance Feature detectors 
Detect same features regardless of scale of the image 

1. SIFT 
2. SURF 
3. BRISK (Binary Robust Invariant Scalable Keypoints) 
4. ORB (Oriented FAST Rotated BRISK) 

I have tried only 2 methods 
1. FAST 
2. BRISK 

#### FAST Feature Detector 
**Working** : 
It works by selecting a candidate point the forming a circle using radius of 3 pixels 

then it tests all the pixels in the circle they should be either brighter or darker than the central point + threshold   

The speed is achieved by computing 4 points in the 
circle with 90 deg separation (top, bottom, left, right)

if 3 of such points are either brighter or darker 
than the central point then only it proceeds forward

if the condition fails then the central point is changed 

Usage : 
```c
// vector of keypoints 
std::vector<cv::KeyPoint> keypoints;
// Construction of the Fast feature detector object  
cv::Ptr<cv::FeatureDetector> fast =  FastFeatureDetector::create(30);  

// feature point detection  
fast->detect(Resize,keypoints);

// Draw Keypoints on the original image 
cv::drawKeypoints(Resize,    // original image 
                keypoints,                // vector of keypoints 
                out,                   // the output image 
                cv::Scalar(255,255,255), // keypoint color (white)
                cv::DrawMatchesFlags::DRAW_OVER_OUTIMG); //drawing flag 

```

#### BRISK Feature Detector 
**Working** : 


It creates a pyramid of images by down scaling 
the input image by half each layer.
In between these layers the image is again down 
scaled by 1.5 

Then FAST feature extraction is applied to each image
of the pyramid.

Then the key points are applied this criteria 
1. The key point must be local maximum comparing its strength 
with 8 spatial neighbors 
2. Then the key point is compared with neighboring 
points in the layers above and below 
if the score is higher in scale as well then it is accepted 
as an interest point.

Usage : 
```c
// vector of keypoints 
std::vector<cv::KeyPoint> keypoints1;
// Construction of the Fast feature detector object  
cv::Ptr<cv::BRISK> brisk =  BRISK::create();  

// feature point detection  
brisk->detect(Resize,keypoints1);

cv::drawKeypoints(Resize,    // original image 
                keypoints1,                // vector of keypoints 
                out1,                   // the output image 
                cv::Scalar(255,255,255), // keypoint color 
                cv::DrawMatchesFlags::DRAW_OVER_OUTIMG); //drawing flag 

```


# Feature Descriptors

Feature Descriptors are methods which describe the location and neighborhood  
of the feature in vectors or binary form 

Typically the Detectors themselves come with built-in descriptors.

Few Descriptors are: 

1. SURF 
2. SIFT 

These descriptors are very rich and contain floating point vectors of dimension 64 or 128, These are costly, Hence I did not study them.

There a new Descriptors called as binary descriptors 
Examples are 
1. ORB 
2. BRISK 


# Feature Matching 

Feature Matching matching descriptors by calculating distance between the 
descriptors using different techniques. 

Various Methods for Matching Descriptors are :

1. **BruteForce-L1**: This is used for float descriptors. It uses L1 distance and is efficient and fast.

2. **BruteForce**: This is used for float descriptors. It uses L2 distance and can be better than L1, but it needs more CPU usage.

3. **BruteForce-SL2**: This is used for float descriptors and avoids square root computation from L2, which requires high CPU usage.

4. **BruteForce-Hamming**: This is used for binary descriptors and calculates the Hamming distance between the compared descriptors.

5. **BruteForce-Hamming(2)**: This is used for binary descriptors (2 bits version).

6. **FlannBased**: This is used for float descriptors and is faster than brute force at the cost of using more memory.

OpenCV encapsulates them all into one Function with various flags for 
different methods



## Rejecting Matches 
If we use simple Match then many key points get incorrectly matched.
To reduce this we need to reject some matches

1. Cross-checking Matches 
Match using all key points of 1st image to 2nd image 
Repeat the match process with key points of 2nd image to the 1st image 

2. Ratio Test 
Use knn to find the best 2 matches between the images 

3. Distance Thresholding 
Reject Matches that have more distance between the vectors 


