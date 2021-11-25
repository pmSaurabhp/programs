#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fun(vector<vector<int>> arr,int i,int j)
{   int k = INT16_MAX;
    // cout<<i<<" "<<j<<"\n";
     if(i==0||j==0||i==arr.size()-1||j==arr[0].size()-1)
        return 0;
    int l=k,r=k,t=k,b=k;

    if(i-1>=0 && arr[i-1][j]==0)
    { arr[i][j] = 2;
        t = 1 + fun(arr,i-1,j);
    }

    if(j+1<arr[0].size() && arr[i][j+1]==0)
    {  arr[i][j]=2;
        r = 1 + fun(arr,i,j+1);
    }

     if(i+1<arr.size())
    { if(arr[i+1][j]==0)
        { arr[i][j]=2;
            b = 1 + fun(arr,i+1,j);
        }
    }

     if(j-1>=0)
    {  if(arr[i][j-1]==0)
       {  arr[i][j]=2;
          l = 1 + fun(arr,i,j-1);
       }
    }

    //cout<<l<<" "<<b<<" "<<t<<" "<<r<<"\n";
    return min(l,min(b,min(t,r)));
}
int main()
{ int n,m;
  vector<vector<int>> arr={
  {1,1,1,1,1,1,1},
  {1,0,2,0,1,1,1},
  {0,0,1,0,0,0,1},
  {1,1,1,0,1,0,1} };

int ci,cj;
for(int i=0;i<arr.size();i++)
{ for(int j=0;j<arr[0].size();j++)
  {if(arr[i][j]==2)
    { ci=i; cj=j; }
  }
}

//cout<< arr[1][2] << "\n";
cout<<fun(arr,ci,cj) << "\n";

}
