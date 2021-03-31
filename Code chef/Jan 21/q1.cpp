#include <iostream>

using namespace std;

int main()
{ int t;
cin>>t;
 while(t--)
 { int n,k,d,c=0;
   cin>>n>>k>>d;
   int arr[n];


   for(int i=0;i<n;i++)
   { cin>>arr[i];

   }
   for(int i=0;i<n;i++)
   {
       c+=arr[i];
   }

   c = c/k;
   if(c>d)
     cout<<d<<"\n";
   else
     cout<<c<<"\n";

 }
return 0;
}
