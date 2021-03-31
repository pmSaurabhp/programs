//Move all negative numbers to beginning and positive to end with constant extra space

#include <iostream>

using namespace std;
void fun(int a[],int n)
{ int i,j;
 i=0; j=n-1;
 while(i<j)
 { if( a[i]>=0&&a[j]<0)
    { swap(a[i],a[j]);
      i++;  j--;
    }
    else{
    if(a[i]<0)
        i++;
    if(a[j]>=0)
        j--;
    }
 }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];

 fun(arr,n);

return 0;
}
