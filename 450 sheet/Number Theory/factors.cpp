// time complexity  O( sqrt(n) )  better than naive O(n)

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
void fast_factors(int n)
{  vector<int> arr;                        //   sqrt(36) = 6
  for(int i=1;i<=sqrt(n);i++)              //   1   36/1 = 36
    { if(n%i==0)                           //   2   36/2 = 18
        arr.push_back(i);                  //   3   36/3 = 12
    }                                      //   4   36/4 = 9
  int s=arr.size()-1;                      //   6   36/6 = 6
  for(int i=s-1;i>=0;i--)
    {                                      // 1 2 3 4 6 9 12 18 36
        arr.push_back(n/arr[i]);
    }

 // print
  for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{ int n;
cin>>n;
fast_factors(n);
return 0;
}
