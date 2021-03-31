#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{ int t;
  cin>>t;

 while(t--)
 {  int n;
    cin>>n;


     long long int arr[n];
   for(int i=0;i<n;i++)
        cin>>arr[i];

   long long int c1,c2;
   sort(arr,arr+n);

   c1=arr[n-1]*arr[n-2]+arr[n-1]-arr[n-2];

    c2 = arr[0]*arr[1] +  arr[1]-arr[0];
//  c2 = arr[0]*arr[1] +  arr[0]-arr[1];  is wrong eg. -10 -5 3 4    c2 = -10 * -5 + -10 + 5 = 45  and c2 = -10 * -5 + -5 + 10 = 55
    c1=max(c1,c2);
   cout<<c1<<"\n";
 }

}
