// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 10
// Take a string in char pointer and remove the duplicate char. 

int main() {
    char *string = NULL; 
    int i, j;
    string = (char *)malloc(STR_MAX * sizeof(char)); 
    strcpy(string, "tester"); 
    int len = strlen(string);
    for(i = 0; i < len; i++) {
        for(j = i+1; j < len; j++) {
            if(string[i] == string[j]) {
                strcpy(string + j, string + (j+1));
            }   
        }
    }
    printf("%s", string);
    free(string);
    return 0;
}
