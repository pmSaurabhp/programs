#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{ int t;
  cin>>t;

 while(t--)
 {  string str;
    cin>>str;

   unordered_map<char,int> arr;


   for(int i=0;i<str.size();i++)
      arr[str[i]]++;

 for(int i=0;i<str.size();i++)
 { if(arr[str[i]]!=0)
    {
        cout<<str[i]<<arr[str[i]];
        arr[str[i]]=0;
    }

 }
 }

}
