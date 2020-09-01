#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if(left!=right)
  {int l,r,m=(left+right)/2,d=(right-left+1)/2+1;
   int countl=0,countr=0;

   l=get_majority_element(a,left,m);
   r=get_majority_element(a,m+1,right);

    for(int i=left;i<=right;i++)
    { if(a[l]==a[i]&&l!=-1)
       { countl++; }
       if(a[r]==a[i]&&r!=-1)
       {countr++;  }
    }

    if(countl>=d)
    { return l; }
    else if(countr>=d)
    { return r; }
    else
        return -1;
  }
  return left;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int x=get_majority_element(a, 0, a.size()-1);
  if(x!=-1)
  {
      std::cout<<"1";
  }
  else{
        std::cout<<"0";}
}
