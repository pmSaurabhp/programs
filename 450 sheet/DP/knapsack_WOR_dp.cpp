#include <iostream>
#include <vector>
using namespace std;

int KWORdp(int wk,vector<int> v,vector<int> w)
{
    vector<vector<int>> dp(w.size(),vector<int> (wk+1));
    for(int i=0;i<w.size();i++)
        dp[i][0]=0;                 // for first column

    for(int i=0;i<w.size();i++)
    {
        for(int j=1;j<=wk;j++)
        {
             if(i==0)            // for all elements of 1st row
            { if(j>=w[0])
                dp[i][j]=v[0];
              else
                dp[i][j]=0;

            }
            else
            { int k1=0,k2=0;

               k1=dp[i-1][j];           // excluding i th element

               if(j>=w[i])
               { k2=v[i]+dp[i-1][j-w[i]]; }         // including i th element

              dp[i][j]=max(k1,k2);
            }


        }
    }
    for(int i=0;i<w.size();i++)
    {
        for(int j=0;j<=wk;j++)
        { cout<<dp[i][j]<<" ";

        }
        cout<<"\n";
    }
    return dp[w.size()-1][wk];
}
int main()
{
    int wk=10;
    vector<int> v={30,14,16,9};
    vector<int> w={6,3,4,2};

    cout<<KWORdp(wk,v,w);
}
