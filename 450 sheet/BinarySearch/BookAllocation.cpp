// https://www.interviewbit.com/problems/allocate-books/
// https://www.youtube.com/watch?v=YTTdLgyqOLY&t=53s
#include <bits/stdc++.h>
using namespace std;
// int Solution::books(vector<int> &A, int B) {
    
//     int min=0,max=0;
//     for(auto i:A)
//         max+=i;
//     int ans=0;
//     int mid=min+(max-min)/2;
//     //cout<<"hello ";
//     while(min<max)
//     {
//         mid=min+(max-min)/2;
//         int c=0,i=0,temp=0;
//         while(1)
//         {
//            // cout<<mid<<" "<<i<<"\n";
//             temp+=A[i];
//             i++;
//             if(temp>mid)
//             { i--;
//               c++;
//               temp=0;
              
//             }
            
//             if(c==B-1 && i == A.size()){
//              max=mid;
//              break;
//             }
//             if(c==B )
//             { min=mid+1;
//              break;
//             }      
//         }
        
//     }
//     //cout<<"end ";
    
//     return mid+1;
// }

// T(n)= log(sum)*(n) 
//	   = n*log(sum)

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if( arr[i] > mid )
            return false;
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m ) {
                return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}
// with framework
int Solution::books(vector<int> &arr, int m) {
    if(arr.size()<m)
        return -1;
    if(arr.size()==1)
        return arr[0];
    int s = 0;
    int sum = 0;
    int n=arr.size();
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    while(s<e)
    {   int mid = s + (e-s)/2;       
    //     use mid = l + (h-l)/2; when updating l         lower mid
	// use mid = l + (h-l+1)/2; when updating h       higher mid 

        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid ;
        }
        else
        {
            s = mid + 1;
        }
        
    }
    return ans;
}
// without framework
int Solution::books(vector<int> &arr, int m) {
    if(arr.size()<m)
        return -1;
    int s = 0;
    int sum = 0;
    int n=arr.size();
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}