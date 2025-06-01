## Dynamic Memory Allocation 
It is a way to allocate memory during runtime. This also allows us to change the 
size of the data structure after initialization.

### Functions for Dynamic Memory Allocation 

1.  `malloc(bytesToBeAllocated)` - It allocates memory with the given number of bytes.
    ```c
    int *ptr;
    ptr = (int *) malloc(30 * sizeof(int)); /*This will allocate the memory for storing 30 integers */

    /* Check if allocation is successfull */
    if(NULL == ptr) {
        /* Memory not allocated handle error*/
    }
    ```
1.  `calloc(noOfBlocks, sizeOfEachBlock)` - It allocates continious memory with the given number of blocks.
    ```c
    int *ptr;
    ptr = (int *) calloc(30, sizeof(int)); /*This will allocate the memory for storing 30 integers */

    /* Check if allocation is successfull */
    if(NULL == ptr) {
        /* Memory not allocated handle error*/
    }
    ```

1.  `realloc(ptr, newsize)` - It is used to resize the previous memory allocation. 
    ```c
    int *ptr;
    ptr = (int *) calloc(30, sizeof(int)); /*This will allocate the memory for storing 30 integers */

    /* Check if allocation is successfull */
    if(NULL == ptr) {
        /* Memory not allocated handle error*/
    }
    ptr = realloc(ptr, 40 * sizeof(int)); /*This will resize the memory for storing 40 integers */
    ```