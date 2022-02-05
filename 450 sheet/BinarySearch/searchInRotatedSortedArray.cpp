// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

// with framework
int findPeak(vector<int>& arr,int n)
{
    int l=0,h=n-1;
    if(arr[l]<=arr[h])
        return h;
   
        while(l<h)
        {
            int mid=l+(h-l)/2;
            
            if(arr[0]>arr[mid]) h=mid;
            else l=mid+1;
        }
        
        return h-1;
}
// no framework
int findPeak(vector<int> arr,int n)
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
        return l;
    else
        return h;
return 0;
}
int binarySearch(vector<int>& arr,int k,int l,int h)
{
    while(l<=h)
    { 
        int mid=l+(h-l)/2;
		//cout<<"mid "<<mid<<" "<<l<<" "<<h<<"\n";
        if(arr[mid]==k)
            return mid;
        if(arr[mid]<k )
            l=mid+1;
        else
            h=mid-1;
    }
return -1;
}
int findPosition(vector<int>& arr, int n, int k)
{   
    if(n==1)
    {
        if(arr[0]==k)
          return 0;
        else
        return -1;
    }
       

    if(n==2)
    { 
        if(arr[0]==k)
            return 0;
        else if(arr[1]==k)
            return 1;
        else    
            return -1;
    }

    int peak=findPeak(arr,n);
    
    //cout<<peak<<"\n";
    if(arr[0]<=k)
    	return binarySearch(arr,k,0,peak);
    else
        return binarySearch(arr,k,peak+1,n-1);
}

int main()
{
    vector<int> arr{10, 1, 2, 5 ,6 };
   
    cout<<findPosition(arr,arr.size(),2);
    return 0;
}