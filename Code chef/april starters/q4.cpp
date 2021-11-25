#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

int visit(vector<string> &arr,int i,int j)
{ int c=1;
     arr[i][j]='0';
int n=arr.size(),m=arr[0].size();
   if(i+1<n)
   { if(arr[i+1][j]=='1')  // down
            c=c+visit(arr,i+1,j);
   }

    if( j+1<m)
   {  if(arr[i][j+1]=='1')
            c=c+ visit(arr,i,j+1);
   }

   if(j-1>=0)
   { if(arr[i][j-1]=='1')
        c=c+ visit(arr,i,j-1);
   }
    if(i-1>=0)
    {if(arr[i-1][j]=='1')
            c=c+ visit(arr,i-1,j);
    }

    return c;

}
int main() {
	int t;
  cin>>t;

 while(t--)
 {  int n,m;
    cin>>n>>m;
  vector<string> arr;
   for(int i=0;i<n;i++)
   { string temp;
    cin>>temp;
    arr.push_back(temp);
    }

   vector<int> store;

   for(int i=0;i<n;i++)
   { for(int j=0;j<m;j++)
       {
           if(arr[i][j]=='1')
           {
               int k=visit(arr,i,j);
             store.push_back(k);
            // cout<<"k = "<<k<<" ";

//            for(int i=0;i<n;i++)
//            {  for(int j=0;j<m;j++)
//                    cout<<arr[i][j]<<" ";
//              cout<<"\n";
//           }
       }
    }
   }

   sort(store.begin(),store.end());

   int c=0;
   for(int i=store.size()-2;i>=0;i=i-2)
   {
       c+=store[i];

   }
//    for(int i=0;i<store.size();i++)
//         cout<<store[i]<<" ";
//
//        cout<<"\n";

 //  cout<<"store size"<<store.size();
   cout<<c<<"\n";
 }
	return 0;
}
