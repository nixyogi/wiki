## Array
Array is collection of similar elements.

```c
int array1[10] = {0, 1, 2, 3, 4} /* Array of 10 integers, filled with integers from 0 to 4*/ 
int array2[] = {0, 1, 2, 3, 4} /* Array of 5 integers, filled with integers from 0 to 4*/
```

-   Its index starts with 0.
-   The above array will reserve (4 bytes) (int = 4bytes) x 5 = 20 bytes of continious memory.

## Pointer arithmetic
Since arrays are continious memory locations, a pointer can be incremented to point to the next location of that type. This is called as pointer arithmetic.

For example: 

```c
// Online C compiler to run C program online
#include <stdio.h>

void main () {
    int arr[] = {5, 10, 15, 20, 25};
    int *ptr = NULL;
    char *ptr2 = NULL;
    ptr = arr; /* arr is actually pointer to the first element, so this assignment works */
    ptr2 = (char *)arr;
    /* Printing array using ptr variable */
    int i;
    for(i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d, ", *(ptr + i)); /* Print the value at address (ptr + i) */ 
    }
    printf("\n");
    /* Printing array using arr variable */
    for(i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d, ", *(arr + i)); /* Print the value at address (arr + i) */ 
    }
    printf("\n");
    /* Printing array using ptr2 variable */
    for(i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d, ", *(ptr2 + i)); /* Print the value at address (ptr2 + i) but this will not work because the ptr2 is an char pointer */ 
    }
    printf("\n");
    /* Printing array using ptr2 variable */
    for(i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d, ", *((int*)ptr2 + i)); /* Print the value at address (ptr2 + i) char pointer is converted to int pointer to make it work */ 
    }
}
```

Output: 

```sh
5, 10, 15, 20, 25, 
5, 10, 15, 20, 25, 
5, 0, 0, 0, 10, 
5, 10, 15, 20, 25, 
```

## Multi-dimensional array 
An array of 2/3/n dimensions. Array of 2 dimensions is a Matrix. 

2D array can be defined as 

```c
int arr[3][2] = {   {1, 2}, 
                    {3, 4},
                    {5, 6} };

/* Access it using */
arr[0][0] /* This is value 1, */
```
-   2D array like 1D array are stored in continious memory location like this |1|2|3|4|5|6|