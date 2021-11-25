#include <iostream>
#include <string>
using namespace std;

int main()
{ string str;
  cin>>str;

   int f=0;
   int n=str.size()-2;
   cout<<n;
    for(int i=0;i<n;i++)
    {
        if(str[i]==str[i+2])
          {  if(f==1)
                cout<<",";
              cout<<str[i]<<str[i+1]<<str[i+2];
              f=1;
          }
    }
}
