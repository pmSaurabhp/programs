// we need to find max sum of elements which are not adjacent
// 6 9 1 3 8 2 4
// 6+1+8+4 = 19
// 9+3+2 = 14
// 9+8+4 = 21
// 6+3+2 = 11
// greedy algorithm fails so we make recursive solution to find all possibilities
// and then optimize it by memoiztion ( DP solution )

#include <iostream>
#include <vector>

using namespace std;
int dpcalc(vector<int> arr,vector<int> &dp,int i)
{ int x=0,y=0;
  if(i+2<=arr.size()-1)
   {  if(dp[i+2]==-1)
        {x = arr[i+2] + dpcalc(arr,dp,i+2);
         dp[i+2]=x;
        }
      else
        x=dp[i+2];
   }
    if(i+3<=arr.size()-1)
    {if(dp[i+3]==-1)
        {y = arr[i+3] + dpcalc(arr,dp,i+3);
         dp[i+3]=y;
        }
     else
        y=dp[i+3];
   }




  return max(x,y);
}
int main()
{ int n;
  cin>>n;

  vector<int> arr(n);  //   vector<int> arr; this error  ate 1 haour time
  vector<int> dp(n,-1);

  for(int i=0;i<n;i++)
    cin>>arr[i];


 cout<<dpcalc(arr,dp,-2);

}
