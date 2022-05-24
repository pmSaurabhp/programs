// https://www.geeksforgeeks.org/two-pointers-technique/
#include <iostream>
#include <algorithm>

using namespace std;
                                                // Naive soln T(n) = O(n^2)
void  two_pointer_sum(int arr[],int n,int x)    // T(n) = O(n)
{

 sort(arr,arr+n);     // { -8 , 1, 4, 6, 10, 45 }
   int l=0,h=n-1;     //    l                h

   while(l<h)
   { if(arr[l]+arr[h]==x)
        {cout<<"Yes "<<arr[l]<<" "<<arr[h];
          return;
        }
     else if(arr[l]+arr[h]>x)
       h--;
     else
        l++;
   }


    cout<<"NO ";
}
int main()
{
    int n=6,x=16;

     int arr[]={1, 4, 45, 6, 10, -8};

      two_pointer_sum(arr,n,x);

}
