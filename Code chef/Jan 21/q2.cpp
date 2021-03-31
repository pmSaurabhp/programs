#include <iostream>
#include <string>
using namespace std;


int main()
{ int t;
 cin>>t;
 char arr[16]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
 while(t--)
 {  int n,p=3;
    cin>>n;

    string s;
    cin>>s;

    for(int k=1;k<=n/4;k++)
    { int i=1,j=16;
     while(1)
     { if(i==j)
       {cout<<arr[i-1];
        break;
        }
        if(s[p]=='0')
            j=(i+j)/2;
        else
          i=(i+j)/2+1;

        p--;
     }

     p=p+8;
    }
    cout<<"\n";
 }

 }
