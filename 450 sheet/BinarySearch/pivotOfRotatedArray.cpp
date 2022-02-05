// pivot (max/min) in a rotated sorted array 
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[],int n)
{   
    int l=0,h=n-1;
    if(arr[l]<=arr[h])          // if array is not rotated      1 2 3 4 5
        return arr[h];
    int mid;
     
    while(h-l!=1)               // loop till only 2 elements are left ( the highest and lowest)
    {
        mid=l+(h-l)/2;
        if(arr[0]<=arr[mid] )   // in left array  
            l=mid;
        else                    // in right array
            h=mid;              // all elemnts in right array are small than a[0]
    }

    if(arr[l]>arr[h])           // find highest of both
        return arr[l];
    else
        return arr[h];
return 0;
}
int main()
{
    int arr[]={8,10,17,3};
    int n=sizeof(arr)/sizeof(arr[0]);
   
    cout<<findPeak(arr,n);
}