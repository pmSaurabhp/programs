// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
// https://leetcode.com/problems/rotate-image/submissions/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int startrow=0,endrow=n-1;
        int startcol=0,endcol=n-1;
        
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<endrow-startrow;j++)
            {
                int temp=matrix[startrow+j][endcol];
                matrix[startrow+j][endcol]=matrix[startrow][startcol+j];
                
                int t2=matrix[endrow][endcol-j];
                matrix[endrow][endcol-j]=temp;
                 
                temp=matrix[endrow-j][startcol];
                matrix[endrow-j][startcol]=t2;
               
                matrix[startrow][startcol+j]=temp;          
            }
            startrow++;
            endrow--;
            startcol++;
            endcol--;
        }
    }
};

