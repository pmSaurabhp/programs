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
//   cout<<h-l<<" ";
    return h-l+a+b;
}
int cut(vector<int> arr,int n,vector<int> store)
{ if(arr.size()==0)
     return costofCut(store,0,0,n);

  int c=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        vector<int> temp=arr;
        vector<int> temp_store=store;

        temp_store.push_back(arr[i]);
        temp.erase(temp.begin()+i);

      int k=cut(temp,n,temp_store);

      c=min(c ,k);
    }

    return c;
}
 int minCost(int n, vector<int> arr)
 {  vector<int> store;

    return cut(arr,n,store);

    }
int main()
{   int n;
   n=7;

  vector<int> arr{1, 3, 4, 5};


cout<<minCost(7,arr);
}
