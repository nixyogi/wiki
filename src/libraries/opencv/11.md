# Thresholding 
Thresholding is where you apply a threshold and bring all the pixel values 
above the threshold to one value and below the threshold to another value.

If some one is from electronics then it is vary similar to Analog to Digital conversion, but in ADC there are many thresholds but here there is only one.

OpenCV provides a function for thresholding called `threshold()`
```c
threshold(input_image, output_image, threshold_value, max_value, type);
```

Where `type` argument determines the type of the threshold that is getting applied.

Table for Types of threshold are 

| **Type** | **Result image**  |
| ------ | ------ |
| THRESH_BINARY | `max_value` if pixel(x,y) value is greater than **threshold_value** and else `0` |
| THRESH_BINARY_INV | `0` if pixel(x,y) value is greater than **threshold_value** and else `max_value` |
| THRESH_TRUNC | `threshold_value` if pixel(x,y) value is greater than **threshold_value** and else pixel(x,y) value is unchanged | 
| THRESH_TOZERO | pixel(x,y) value is unchanged if pixel(x,y) value is greater than **threshold_value** and else `0` | 
| THRESH_TOZERO_INV | `0` if pixel(x,y) is greater than **threshold_value** and else pixel(x,y) value is unchanged | 

Other Types of thresholding are 

1. Adaptive thresholding 
2. Otsu thresholding 
3. Triangle Binarization
