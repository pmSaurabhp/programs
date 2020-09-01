#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_square(long long n)
{

    int fib[301];  // max length of array 10^5

    int i,k,j;
    int sum300;
    fib[0]=0;
    fib[1]=1;
    if(n>=1)
    {
        sum300=1;
    }
  for(i=2;i<=300;i++)
  {
      fib[i]=fib[i-1]+fib[i-2];   // modulus values are stored in fib[]
      fib[i]=fib[i]%10;
    sum300=sum300+fib[i]*fib[i];
    sum300=sum300%10;
  }
  k=n/300;
  sum300=k*sum300;
  sum300=sum300%10;

  j=n%300;
  for(i=1;i<=j;i++)
  {
    sum300=sum300+fib[i]*fib[i];
     sum300=sum300%10;
  }

return sum300;

}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_square(n);
}
