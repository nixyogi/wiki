## Pointers 
Pointer is a variable which stores the address/location of another variable. Hence it is called as pointer.

For example: 

```c
void main () {
    int i = 20;
    int *p; /* p is an pointer to integer*/
    p = &i; /* p is now pointing to i*/
}
```
-   `*` Means the value at the address stored in the variable. 
-   `&` Means the address of a variable.
-   In the above example itself, `&i` is address of varaiable `i` and `*p` will give the value of address stored in p which is the value of `i`.

Sample Code: 

```c
#include <stdio.h>

void main () {
    int i = 20;
    int *p; /* p is an pointer to integer*/
    p = &i; /* p is now pointing to i*/
    
    printf("Address of i %u\n", &i);
    printf("P variable value (i.e Address of i) %u\n", p);
    printf("Value of i %d\n", i);
    printf("Value stored at address pointed by p (i.e value of i) %d\n", *p);
    printf("Value stored at address pointed by &i (i.e value of i) %d\n", *(&i));
}
```

Output of the Code:
```sh
Address of i 2039267252
P variable value (i.e Address of i) 2039267252
Value of i 20
Value stored at address pointed by p (i.e value of i) 20
Value stored at address pointed by &i (i.e value of i) 20
```

## Dangling Pointer 
Dangling Pointer is Pointer to the variable for which the life has ended. 

For example: 

```c
int *abc (void); 
void main () {
    int *p; 
    p = abc();
}

int *abc(void)
{
    int i = 10; 
    return &i; /* This is returing an address to local variable whose life is ended.*/  
}
```
## Pointer to the Pointer (Double Pointer)

Double pointer is a pointer to a pointer which is pointing to a value. Usecases are like multi-dimensional arrays etc.

Program to initialize the pointer to a pointer array 

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPointers = 4;  // Number of integer pointers
    int **ptrArray;       // Pointer to an array of integer pointers

    // Allocate memory for the array of integer pointers
    ptrArray = (int **)malloc(numPointers * sizeof(int *));
    if (ptrArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each integer pointer and initialize them
    for (int i = 0; i < numPointers; i++) {
        ptrArray[i] = (int *)malloc(sizeof(int));
        if (ptrArray[i] == NULL) {
            printf("Memory allocation failed for ptrArray[%d]\n", i);
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(ptrArray[j]);
            }
            free(ptrArray);
            return 1;
        }
        *ptrArray[i] = (i + 1) * 100;  // Initialize with a value
    }

    // Print the values
    printf("Values in the pointer array:\n");
    for (int i = 0; i < numPointers; i++) {
        printf("ptrArray[%d] = %d\n", i, *ptrArray[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < numPointers; i++) {
        free(ptrArray[i]);
    }
    free(ptrArray);

    return 0;
}

```