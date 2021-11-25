#include <iostream>
#include <vector>
using namespace std;
int main()
{   vector<int> arr={45, 8, 57, 9, 10, 167,8};

  int  a=arr[0],b=arr[1];    //  a smallest integer               b   next smallest integer
  if(a>b)    // swap
    { a=a+b;
      b=a-b;
      a=a-b;
    }

   for(int i=2;i<arr.size();i++)
 {   if(arr[i]<=a)
     { b=a;
       a=arr[i];
     }
   else if(arr[i]<b)
     { b=arr[i];
     }
 }

cout<<"Smallest Integer: "<<a<<"\n";
cout<<"Next Smallest Number :"<<b<<"\n";
cout<<"Sum of 2 smallest Integers:"<<a+b<<"\n";
}
