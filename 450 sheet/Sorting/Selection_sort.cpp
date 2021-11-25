#include <iostream>

using namespace std;
void Selection_sort(int arr[],int n)
{
  for(int i=0;i<n;i++)
  { int m=i;
    for(int j=i+1;j<n;j++)
    { if(arr[m]>arr[j])
        m=j;
    }
    // swap
    arr[m]=arr[m]+arr[i];
    arr[i]=arr[m]-arr[i];
    arr[m]=arr[m]-arr[i];
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
  }


}
int main()
{ int n=9;
  int arr[]={5,2,7,4,1,3,6,9,8};

for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
Selection_sort(arr,n);

}
