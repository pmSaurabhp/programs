#include<iostream>
#include<algorithm>
using namespace std;
void  fun(int a[],int b[],int n)
{ sort(a,a+n);
  sort(b,b+n);
  if(a[0]>b[0])
  {cout<<b[0];
  }
  else
  { cout<<a[0];
  }
}

int main()
{ int n;
 cin>>n;
 int a[n],b[n];
 for(int i=0;i<n;i++)
 { cin>>a[i];
 }
 for(int i=0;i<n;i++)
 { cin>>b[i];
 }
 fun(a,b,n);
 return 0;
}
