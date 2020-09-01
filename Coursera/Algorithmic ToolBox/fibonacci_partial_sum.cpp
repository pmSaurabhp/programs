#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
int fibonacci_sum_fast(long long n)
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
    sum300=sum300+fib[i];
    sum300=sum300%10;
  }
  k=n/300;
  sum300=k*sum300;
  sum300=sum300%10;

  j=n%300;
  for(i=1;i<=j;i++)
  {
    sum300=sum300+fib[i];
     sum300=sum300%10;
  }

return sum300;

}
int fibonacci_mod_10(long long n)
{
    int fib[100000];  // max length of array 10^5

    int i,k;
    fib[0]=0;
    fib[1]=1;
  for(i=2;i<=301;i++)
  {
      fib[i]=fib[i-1]+fib[i-2];   // modulus values are stored in fib[]
      fib[i]=fib[i]%10;

      if(fib[i-1]==0&&fib[i]==1)
      {
          break;
      }
  }


  k=n%300;

return fib[k];
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    int total,i,j;
    i=fibonacci_sum_fast(from-1);
    j=fibonacci_sum_fast(to);
    if(j>i)
    {total=j-i;
    }
    else if(j<i)
    {
        total=10+j-i;
    }
    else{
        total=fibonacci_mod_10(from);
    }
    std::cout<<total;
   // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
