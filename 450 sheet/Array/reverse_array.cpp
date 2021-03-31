#include <iostream>

using namespace std;
int main()
{ int n,i,j,t;
  cin>>n;
  i=0;   j=n-1;
  int a[n];
  for(int k=0;k<n;k++)
    cin>>a[k];

 while(i<=j)
 { t=a[i];
    a[i]=a[j];
    a[j]=t;
    i++;
    j--;
 }
 for(int k=0;k<n;k++)
    cout<<a[k]<<" ";
return 0;
}
