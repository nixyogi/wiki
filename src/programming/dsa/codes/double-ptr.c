// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create an array of pointers and initialize them using a double pointer. 

int main() {
    int **arrOfptr = NULL; 
    int i;
    arrOfptr = (int **)malloc(10*sizeof(int*)); 
    
    for(i = 0; i < 10; i++) {
        arrOfptr[i] = (int *)malloc(sizeof(int));
        **(arrOfptr + i) = i; 
    }
    for(i = 0; i < 10; i++) {
        printf("%d, ", **(arrOfptr + i));   
    }
    
    return 0;
}
