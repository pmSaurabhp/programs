// spiral matrix
// https://leetcode.com/problems/spiral-matrix/submissions/

class Solution {
public:
    //     complex solution & not working
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int r=matrix.size();
//         int c=matrix[0].size();
        
//         //cout<<r<<"\n";
//         vector<int> ans;
//         int i,j;
//         for(int k=0;k<r;k++)
//         { 
//             for(j=k;j<c;j++)
//             {
//                 cout<<matrix[k][j]<<" ";
//                 ans.push_back(matrix[k][j]);
//             }
//             j--;
//             cout<<"a\n";
//             for(i=k+1;i<r;i++)
//             { cout<<matrix[i][j]<<" ";
//                  ans.push_back(matrix[i][j]);
//             }
//             i--;
//             cout<<"b\n";
//             if(j-1-k>0)
//             {for(j=j-1;j>=k;j--)
//                 { 
//                 cout<<matrix[i][j]<<" ";
//                   ans.push_back(matrix[i][j]);
                
//                 }
//             }
//              cout<<"c\n";
//              for(i=i-1;i>k;i--)
//              {  cout<<matrix[i][k]<<" ";
//                  ans.push_back(matrix[i][k]);
//              }
//              cout<<"d\n";
//               r--;
//             c--;
            
//         }
//         return ans;
//     }
     vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        //cout<<r<<"\n";
        vector<int> ans;
        int startrow=0,endrow=r-1;
        int startcol=0,endcol=c-1;
        int count=0,total=r*c; 
         cout<<total<<" ";
        while(count<total)
        { 
            for(int i=startcol;count<total && i<=endcol;i++)
            {
                cout<<matrix[startrow][i]<<" ";
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            cout<<"a\n";
           for(int i=startrow;count<total &&i<=endrow;i++)
            { //cout<<i<<" ";
                cout<<matrix[i][endcol]<<" ";
                ans.push_back(matrix[i][endcol]);
               count++;
            }
            endcol--;
            cout<<"b\n";
            for(int i=endcol;count<total && i>=startcol;i--)
            {
                cout<<matrix[endrow][i]<<" ";
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
             cout<<"c\n";
             for(int i=endrow;count<total && i>=startrow;i--)
            {
                cout<<matrix[i][startcol]<<" ";
                ans.push_back(matrix[i][startcol]);
                 count++;
            }
           startcol++;
            cout<<" count "<<count<<"\n";
        }
        return ans;
    }
};