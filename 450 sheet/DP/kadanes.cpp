// i was thinking wrong i.e. a DP solution
// but it has greedy soln

// this is Dp soln :0
// we are using previously calculated values
// https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
// Let’s say somehow I know the local_maximum[4].
// Then we see that to calculate the local_maximum[5],
// we don’t need to compute the sum of all subarrays ending
// with A[5] since we already know the result from arrays ending with A[4]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSubarraySum_naive(int arr[], int n){  // O( n^2 )

    int m=0;
    for(int i=0;i<n;i++)
    { int mt=arr[i];
        m=max(m,mt);
        for(int j=i+1;j<n;j++)
        {  mt += arr[j];
           m=max(m,mt);
        }

    }
    return m;

}
int maxSubarraySum_recursive(int arr[],vector<int> store,int n)
{   if(n==0)
    { int sum=0;
        for(int i=0;i<store.size();i++)
            sum += store[i];
        return sum;
    }

    store.push_back(arr[n-1]);
    int l=maxSubarraySum_recursive(arr,store,n-1);
    store.erase(store.begin(),store.end());
    store.push_back(arr[n-1]);
    int r=maxSubarraySum_recursive(arr,store,n-1);

    return max(l,r);
}
int maxSubarraySum(int arr[], int n)  // O(n)
{
    int max_sum=0,max_so_far=0;

    for(int i=0;i<n;i++)
    { max_so_far = max(arr[i] ,max_so_far + arr[i]);

     if(max_so_far > max_sum)
         max_sum = max_so_far;
    }
    return max_sum;
}
int main()
{

    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> store;
    cout<<maxSubarraySum_recursive(arr,store,8)<<"\n";

    cout<<maxSubarraySum(arr,8);
}
