#include <stdio.h>

// Function to return the only odd
// occurring element
int findOdd(int arr[], int n)
{
	int res = 0, i;
	for (i = 0; i < n; i++)    // XOR takes two numbers as operands and does XOR on every bit of two numbers.
        res = res^arr[i];     // The result of XOR is 1 if the two bits are different.
		                      // 90^90 = 0
	return res;
}

// Driver Method
int main(void)
{
	int arr[] = { 12, 90, 14, 90, 14, 14, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The odd occurring element is %d ",
		findOdd(arr, n));
	return 0;
}
