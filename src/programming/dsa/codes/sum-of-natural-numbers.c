/* Program II - If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000. 
*/

#include <stdio.h>
#include <stdlib.h>

int findSumofNatNumbers(int multiple, int below) {
	
	int n, sum; 
	n = ((below-1)/multiple);
	sum = multiple * ((n*(n+1))/2);

	return sum;
}

int main() {

	int sum3 = 0; 
	int sum5 = 0;

	sum3 = findSumofNatNumbers(3, 1000); 
	sum5 = findSumofNatNumbers(5, 1000); 

	printf("the sum of all the multiples of 3 or 5 below 1000 is %d", (sum3 + sum5));
}