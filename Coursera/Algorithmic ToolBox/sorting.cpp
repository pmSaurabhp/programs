// not working for reverse array 5 4 3 2 1

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int i=l+1,j = r;
  while(i<=j) {
    if(a[i]>a[j])
    {  swap(a[i],a[j]);
        i++;
        j--;
    }
    if(a[i]<=x)
    { i++; }
    if(a[j]>x)
    { j--;}

  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }


  int m = partition2(a, l, r);
  int m1=m;
    for(int i=l;i<m1;i++)
    {
       if(a[i]==a[m])
        { swap(a[i],a[--m1]);
          if(a[i]==a[m]){ i=i-1; }
         }

    }
  randomized_quick_sort(a, l, m1-1);
  randomized_quick_sort(a, m+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
