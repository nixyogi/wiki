## Masking 
A mask defines which bits you want to keep, and which bits you want to clear.

Masking is the act of applying a mask to a value. This is accomplished by doing:

-   Bitwise ANDing in order to extract a subset of the bits in the value
-   Bitwise ORing in order to set a subset of the bits in the value
-   Bitwise XORing in order to toggle a subset of the bits in the value

Below is an example of extracting a subset of the bits in the value:
```sh
Value:  0b01010101
Mask:   0b00001111

```
Applying the mask to the value means that we want to clear the first (higher) 4 bits, and keep the last (lower) 4 bits. Thus we have extracted the lower 4 bits. The result is:

```sh
Value:  0b01010101
Mask:   0b00001111
Result: 0b00000101
```

For Example: 
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
You are given an unsigned 32-bit integer, and your task is to reverse its bits. That is, the bit at position 0 should be swapped with the bit at position 31, the bit at position 1 should be swapped with the bit at position 30, and so on.

Input: 43261596 (which is 00000010100101000001111010011100 in binary)
Output: 964176192 (which is 00111001011110000010100101000000 in binary)
*/

int main()
{
    uint32_t input = 43261596; 
    uint8_t i, j; 
    uint8_t bin_arr[32];
    uint32_t output = 0; 
    // Extract all the values and store into an array. 
    for(i = 0; i < 32; i++) {
        unsigned int mask = 0x01; 
        bin_arr[i] = input & mask; 
        input = input >> 1;
    }
    printf("\n");
    // Create a new number with the array 
    for (j = 0; j < 32; j++) {
        output = output << 1;
        output = output | bin_arr[j];
    }
    printf("\n%d\n", output);
    
    return 0;
}
```

