#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{ string s;
  cin>>s;

  int arr[26]={0};

  for(int i=0;i<s.size();i++)
    arr[s[i]-'a']++;

  int ans=arr[0];
    int c=0;
   for(int i=1;i<26;i++)
  { if(ans==arr[i])
        c=1;
    if(ans<arr[i])
      {ans=arr[i];
       c=0;
      }

  }

 if(c==1)
    cout<<"0";
 else
    cout<<ans;


//  for(int i=1;i<26;i++)   // i used this as
//  { if(ans<arr[i])
//     ans=arr[i];
//  }
//
//  sort(arr,arr+26);
//  if(arr[24]==arr[25])
//    cout<<"0";
//  else
//    cout<<ans;
}
