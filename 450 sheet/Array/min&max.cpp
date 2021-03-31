#include <iostream>

using namespace std;
int main()
{ int n,s,l,t;
  cin>>n;

  int a[n];
  for(int k=0;k<n;k++)
    cin>>a[k];

    s=a[0]; l=a[0];
 for(int k=1;k<n;k++)
 { if(a[k]<s)
        s=a[k];
    else if(a[k] >l)
        l=a[k];
 }


    cout<<"min : "<<s<<" max : "<<l;
return 0;
}
