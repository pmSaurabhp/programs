// now working for reverse array 5 4 3 2 1

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void quick_sort(vector<int> &a, int l, int r,int *c)
{
  if (l >= r) return;

  int x = a[l];
  int i=l+1,j = r;
  while(i<=j)
 {
    if(a[i]>x&&a[j]<x)  // only if( a[i]>a[j] ) is wrong
    { std::cout<<"swap "<<a[i]<<" and "<<a[j]<<"\n";
        swap(a[i],a[j]);

        *c=*c+1;
        i++;
        j--;
    }
    if(a[i]<=x)
    { i++; }
    if(a[j]>x)
    { j--;}

  }
  if(a[l]!=a[j])
  { std::cout<<"swap "<<a[l]<<" and "<<a[j]<<"\n";
      swap(a[l], a[j]);
    *c=*c+1;
  }
  quick_sort(a, l, j-1,c);
  quick_sort(a, j+1, r,c);
}
int call_qs(vector<int> &a) {
    int c=0;
  quick_sort(a,0,a.size()-1,&c);
  return c;
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int swaps=call_qs(a);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout<<"\n";
  std::cout<<"No. of swaps = "<<swaps;
}
