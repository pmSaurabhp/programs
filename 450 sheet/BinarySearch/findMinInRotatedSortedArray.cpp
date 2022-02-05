// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// sanjay solution

int findMin(vector<int>& arr) {
int n = nums.size(), lo, hi, mid;
         // F*T*     FFFTT    
        lo = 0; hi = n-1;
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[0] > nums[mid]) hi = mid;   // finding 1st T
            else lo = mid +1;
        }
        if(nums[0] > nums[hi]) return nums[hi];
        else return nums[0];
}
int findMin(vector<int>& arr) {
    
    int l=0,h=arr.size()-1;
  
    if(arr[l]<=arr[h])
        return arr[l];
    int mid;
      // cout<<"a";
    while(h-l!=1)
    {
       // cout<<"b";
        mid=l+(h-l)/2;
      //  cout<<"mid "<<mid<<" "<<l<<" "<<h<<"\n";
        if(arr[0]<=arr[mid] )
            l=mid;
        else
            h=mid;
    }
    if(arr[l]>arr[h])
        return arr[h];
    else
        return arr[l];
return 0;
    }
