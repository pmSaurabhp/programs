#include <bits/stdc++.h>
using namespace std;


int CountTriplets(int a[], int n)   // O(n^2)
{

    // To store count of total triplets
    int ans = 0;

    for (int i = 0; i < n; i++) {

        // Initialize count to zero
        int cnt = 0;

        for (int j = i + 1; j < n; j++) {

            // If a[j] > a[i] then,
            // increment cnt
            if (a[j] > a[i])
                cnt++;

            // If a[j] < a[i], then
            // it mean we have found a[k]
            // such that a[k] < a[i] < a[j]
            else
                ans += cnt;
        }
    }

    // Return the final count
    return ans;
}

// Driver code
int main()
{
    int arr[] = { 2, 5, 1, 3, 0 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << CountTriplets(arr, n) << endl;

    return 0;
}
