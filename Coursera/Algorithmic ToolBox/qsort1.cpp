#include<iostream>
#include<cstdlib>

int compare(const void* a,const void* b)
{ const double* x = (double*) a;
	const double* y = (double*) b;

	if (*x > *y)
		return -1;
	else if (*x < *y)
		return 1;
    else
        return 0;
}
int main() {
  int n=5;

  double values[n];

  for (int i = 0; i < n; i++) {
    std::cin >> values[i];
  }
  qsort(values,5,sizeof(double),compare);
  for (int i = 0; i < n; i++) {
   std::cout <<values[i];
  }

  return 0;
}
