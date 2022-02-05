// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

vector<int> searchRange(vector<int>& nums, int target) {
        
        // Here implemented F*T*
        
        int n = nums.size();
        
        if(n == 0) return {-1,-1};
        
        int lo = 0, hi = n-1, mid;
        vector<int> res;
        
        // Finding first T in F*T*, FFFFTT
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        // Sanity c
    if(nums[lo] == target) res.push_back(lo);
        else return {-1,-1};
        
        lo = 0, hi = n-1;
        
        // Finding last F in F*T*
        while(lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            if(nums[mid] > target) hi = mid - 1;
            else lo = mid;           // Finding last F 
        }
        res.push_back(lo);
        return res;
    }