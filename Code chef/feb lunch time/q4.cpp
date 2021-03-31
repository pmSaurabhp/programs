#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{ int t;
  cin>>t;

while(t--)
 {
    string str;
    cin>>str;

      int arr[26]={};

     for(int i=0;i<str.size();i++)
     {
         arr[str[i]-'a']++;
     }

//      for(int i=0;i<26;i++)
//        cout<<arr[i]<<" ";

     int even=0,odd=0;
     for(int i=0;i<26;i++)
     {
         if(arr[i]%2==0)
            even+=arr[i]/2;
         else
         {
             even+=arr[i]/2;
             odd++;
         }
     }

    if(even>=odd)
        cout<<"YES\n";
    else
        cout<<"NO\n";
 }
}
