//      Bitwise OR of sum of all subsequences of an array
// https://www.geeksforgeeks.org/bitwise-or-of-sum-of-all-subsequences-of-an-array/
#include <bits/stdc++.h>
using namespace std;

int findOR(int nums[], int N)
{

	int prefix_sum = 0;

	int result = 0;

	for (int i = 0; i < N; i++) {

		// Bits set in nums[i] are also set in result
		result |= nums[i];

		prefix_sum += nums[i];

		// Bits set in prefix_sum also set in result
		result |= prefix_sum;
	}


	return result;
}

int main()
{
	int arr[] = { 4, 2, 5 };

	int N = sizeof(arr) / sizeof(arr[0]);

	cout << findOR(arr, N);

	return 0;
}
