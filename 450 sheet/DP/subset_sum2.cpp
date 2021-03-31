#include <iostream>
#include <vector>

using namespace std;

int subset_sum(int arr[],int n,int sum)
{
   int dp[n][sum+1];

   for(int i=0;i<n;i++)
        dp[i][0]=1;
    for(int i=1;i<sum+1;i++)
        if( i==arr[0])
            dp[0][i]=1;
        else
            dp[0][i]=0;

    for(int i=1;i<n;i++)
    { for(int j=1;j<sum+1;j++)
        { if(dp[i-1][j]==1)
            dp[i][j]=1;
          else if(j>=arr[i])
            dp[i][j]=dp[i-1][j-arr[i]];
          else
            dp[i][j]=0;
        }
    }
    cout<<"\n";
for(int i=0;i<n;i++)
    { for(int j=0;j<sum+1;j++)
        {cout<<dp[i][j]<<" "; }
      cout<<"\n";
    }
    return dp[n-1][sum];
}

int main()
{ int n=6,sum=30;

  int arr[]={3, 34, 4, 12, 5, 2};

  cout<<subset_sum(arr,n,sum);

  cout<<"\n"<<subset_sum(arr,n,sum+4);



}
