// First Negative Number in every Window of Size K | Sliding Window
//  i/p 12 -1 -7 3 -2 8 4 6
//  o/p  -1 -1 -7 -2 -2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void fun(vector<int> arr,int k)
{ int i,j,n;
  queue<int> q;
  i=0; j=0; n=arr.size();
  while(j<n)
  { if(arr[j]<0) q.push(arr[j]);

    if(j-i<k-1) j++;
    else{
    if(!q.empty())
    { cout<<q.front()<<" ";
      if(arr[i]==q.front()) q.pop();
    }
    i++;  j++;
    }
  }
}
int main()
{ int n,k;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  { cin>>arr.at(i); }
  cin>>k;
  fun(arr,k);
 return 0;
}
