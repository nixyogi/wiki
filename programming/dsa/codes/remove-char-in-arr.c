// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeChar(char *str, char charToRemove) {
    char *src = str, *dst = str;

    while (*src != '\0') {
        if (*src != charToRemove) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

int main() {
    char *string;
    string = (char*)calloc(6, sizeof(char));
    strncpy(string, "tester\0", strlen("tester\0"));
    //*string = 'k';
    int len = strlen(string);
    int j, k, l;
    char *string2 = string;
    for(j=0;j<len;j++){
        for(k=j+1; k < len; k++) {
            printf("%c = %c\n", string[j], string[k]);
            removeChar(string2++, string[j]);
        }
    }
    
    int i;
    for(i=0;i<len;i++){
        printf("%c", string[i]);
    }

    return 0;
}