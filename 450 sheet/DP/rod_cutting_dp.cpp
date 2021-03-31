#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int costofCut(vector<int> store,int i,int l,int h)
{ if(i==store.size())
    return 0;

  int a=0,b=0;
  if(store[i]>l && store[i]<h)
    { a = costofCut(store,i+1,l,store[i]);

      b = costofCut(store,i+1,store[i],h);
    }
    else
    { i++;
      a = costofCut(store,i,l,h);
      return a;
    }

    return h-l+a+b;
}

 int minCost(int n, vector<int> arr)
 {  int dp[arr.size()][];

    return cut(arr,n,store);

    }
int main()
{   int n;
   n=7;

  vector<int> arr{1, 3, 4, 5};


cout<<minCost(7,arr);
}
