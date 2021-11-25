#include <iostream>
#include <algorithm>
using namespace std;

int main()
{ int n;
 cin>>n;

 int arr[n];
 for(int i=0;i<n;i++)
  {cin>>arr[i];            // 5 4 3 1
    arr[i]=arr[i]*arr[i]; // square and insert
   }
sort(arr,arr+n);          // 1 9 16 25 64
                          //  a2   b2 c2
                          //    a2+b2 > c2
                         //     a2+b2 < c2

//  for(int i=0;i<n;i++)
//  { for(int j=i+1;j<n;j++)
//    { for(int k=j+1;k<n;k++)
//        { if((arr[i]*arr[i]+arr[j]*arr[j])==arr[k]*arr[k])
//            {f=1;
//              break;
//            }
//        }
//    }
//  }

 int f=0;
 for(int i=n-1;i>=2;i--)
 {  int c2=arr[i];
     int j=0,k=i-1;
     while(1)
    { int a2=arr[j];
      int b2=arr[k];

       if(a2+b2==c2)
       { f=1;
         break;
       }
       else if(a2+b2<c2)
        j++;
       else
        k--;

       if(j>=k)
         break;
    }
    if(f==1)
        break;
 }

  if(f==0)
   cout<<"FALSE";
   else
   cout<<"TRUE";
}
