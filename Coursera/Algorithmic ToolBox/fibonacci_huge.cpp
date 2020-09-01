#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
int pisano_period(long long n,int m)
{
    int fib[100000];  // max length of array 10^5

    int i,k;
    fib[0]=0;
    fib[1]=1;
  for(i=2;i<=m*m;i++)
  {
      fib[i]=fib[i-1]+fib[i-2];   // modulus values are stored in fib[]
      fib[i]=fib[i]%m;

      if(fib[i-1]==0&&fib[i]==1)
      {
          break;
      }
  }
  i=i-1; // i= pisano period

  k=n%i;

return fib[k];
}

int main() {
    long long n;
    int m;
    std::cin >> n >> m;
//    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
  std::cout<<pisano_period(n,m);

return 0;
}
