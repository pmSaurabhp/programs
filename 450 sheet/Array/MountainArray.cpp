//          Peak in  Mountain array
//          https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
class Solution {
public:
    //   T(n) = O(n)
//     int peakIndexInMountainArray(vector<int>& arr) {
//        
//      for(int i=0;i<arr.size();i++)
//      { if(arr[i]>arr[i+1])
//           return i
//      }
//         return 0;
//     }
    
    
 //     T(n) = O(log n)   
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l=0,h=arr.size()-1;
        
        while(l<=h)
        { int mid=l+(h-l)/2;  // mid = (l+h)/2  gives integer overflow for long integers
          
          if(mid!=0 && arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
              return mid;
           else if(arr[mid]<arr[mid+1])
               l=mid+1;
            else
                h=mid-1;
        }
        return 0;
    }
};