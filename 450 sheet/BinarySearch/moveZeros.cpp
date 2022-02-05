// move all zeroes to right by keeping the order of non zero elements
// https://leetcode.com/problems/move-zeroes/submissions/

 void moveZeroes(vector<int>& nums) {
        // we move all the non zero elements to left
        // instead of moving zero elements to right
        int nonZero=0;
        for(int j=0;j<nums.size();j++)      //       O(n)
        {
            if(nums[j]!=0)
            {
                swap(nums[nonZero],nums[j]);
                nonZero++;
            }
        }
    }