/*Program III – Square of 13 is 169 and square of 31 is 961. Here, reverse of 13 = 31, interestingly square of these numbers, i.e. 169 and 961 are also reverse of each other. Write a program to find all such numbers in the range of 1 to 100.
*/
#include <stdio.h>

// Function to reverse the digits of a number
int reverse(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

// Function to find and print all such pairs in the range from 1 to 100
void findReversePairs() {
    int a, b, a_squared, b_squared, a_squared_reverse;
    
    for (a = 11; a < 101; a++) {
        b = reverse(a);  // Reverse of a
        //printf("Reverse: %d\n", b);
        // Check if b is within the range and it's a reverse pair
        if (b <= 100 && a != b) {
            a_squared = a * a;
            b_squared = b * b;
            //printf("Squared : %d & %d\n", a_squared, b_squared);
            a_squared_reverse = reverse(a_squared);
            // Check if squares are equal
            if (a_squared_reverse == b_squared) {
                printf("Pair: %d and %d, squared: %d\n", a, b, a_squared);
            }
        }
    }
}

// Main function to run the program
int main() {
    findReversePairs();
    return 0;
}
