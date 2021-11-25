#include <iostream>
#include <vector>
#include <set>
//The C++ standard library contains two set implementations:
//
//The structure set is based on a balanced binary tree and its operations work in O(logn) time.
//The structure unordered set uses hashing, and its operations work in O(1) time on average.
//The choice of which set implementation to use is often a matter of taste.
//The benefit of the set structure is that it maintains the order of the elements and provides
//functions that are not available in unordered set. On the other hand, unordered set can be more efficient.
using namespace std;

int main()
{ set<int> A,B,U;

  A.insert(4);
  A.insert(3);
  A.insert(7);
  A.insert(1);
  A.insert(1);

vector<int> arr{4,3,3,3,5,1,1,2,2,2};
  for(int i=0;i<arr.size();i++)
    B.insert(arr[i]);

  //set<int>::iterator it;              //  can also use this in place of auto

  for(auto it=A.begin();it!=A.end();it++)   // sets can be  printed only using iterator
  {                                         // end() returns iterator that is after last element
      cout<<*it<<" ";                       // similar to EOF in strings
  }

  cout<<"\n";
   for(auto it=B.begin();it!=B.end();it++)
  {
      cout<<*it<<" ";
  }
}
