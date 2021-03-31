#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
long long sum_3(int x,int y,int z)
{ long long t=abs(x-y)+abs(y-z)+abs(z-x);

    return t;
}
long long sum(vector<int> store)
{
    long long c;
    c=abs(store[0]-store[1])+abs(store[1]-store[2])+abs(store[2]-store[0]);
    return c;
}
long long triples(vector<int> arr,int n,vector<int> store)
{

    if(store.size()==3)
        return sum(store);
    if(n==0)
        return 0;
    if(n<=2&&store.size()==0)
        return 0;

    int k1=0,k2=0;

    k1=triples(arr,n-1,store);

    store.push_back(arr[n-1]);
    k2=triples(arr,n-1,store);

 return max(k1,k2);
}
int main()
{ int t;
cin>>t;

 while(t--)
 {
     int n;
     cin>>n;

     vector<int> arr(n);
     for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr.begin(),arr.end());

    int x=arr[0],y,z=arr[n-1];

    long long int c=0;

    for(int i=1;i<n-1;i++)
    { y=arr[i];
      c=max(c,sum_3(x,y,z));

    }

    cout<<c<<"\n";

//    int c=0;                        // branch and boumd solution   TLE
//    for(int i=1;i<n;i++)
//    {
//        if(arr[i]==arr[i-1])
//        { c++;
//        }
//        else
//          c=0;
//        if(c>=1)
//           { if(n==3)
//                break;
//               arr.erase(arr.begin()+i);
//               i--;
//               n--;
//           }
//    }
//     vector<int> store;
//    cout<<triples(arr,n,store)<<"\n";
 }
}
