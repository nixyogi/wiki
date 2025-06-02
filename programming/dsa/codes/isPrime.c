/**
 * Program to find all the prime numbers from 1 to 100 using recursion. 
 * Why we only try all divisors till n/2, because divisors after n/2 are 
 * always the number itself.
 * 
 */
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

int primeNumbers[50];
int count;
// Function to check if prime
void checkPrime(int num) {
    int i;
    bool isDivisible = false;
    // Loop to check if it is a prime number 
    for(i = 2; i < num/2; i++) {
        if(0 == (num%i)) {
            isDivisible = true;
            break;
        }
    }
    if(!isDivisible) {
        primeNumbers[count] = num; 
        count++;
    }

    if (num < 100 ) {
        checkPrime(num + 1);
    }
}


int main() {
    int i;
    count = 0;
    checkPrime(1); 
    for(i = 0; i < 50; i++) {
        printf("%d, ", primeNumbers[i]);
    }
    printf("\n");
    return 0;
}