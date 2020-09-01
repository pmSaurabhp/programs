// CPP program to print all subsets with given sum
#include <bits/stdc++.h>
using namespace std;

// The vector v stores current subset.
void printAllSubsetsRec(int arr[], int n, vector<int> v)
{
	// If remaining sum is 0, then print all
	// elements of current subset.
	if (n == 0) {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
		return;
	}

	// If no remaining elements,
	if (n == 0)
		return;

	// We consider two cases for every element.
	// a) We do not include last element.
	// b) We include last element in current subset.
	printAllSubsetsRec(arr, n - 1, v);
	v.push_back(arr[n - 1]);
	printAllSubsetsRec(arr, n - 1, v);
}

// Wrapper over printAllSubsetsRec()
void printAllSubsets(int arr[], int n)
{
	vector<int> v;
	printAllSubsetsRec(arr, n, v);
}

// Driver code
int main()
{
	int arr[] = { 1,2,3,4,5};

	int n = sizeof(arr) / sizeof(arr[0]);
	printAllSubsets(arr, n);
	return 0;
}
