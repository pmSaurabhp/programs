#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int fibonacci_last_digit_fast(int n) {
    int a[n];
    if(n==0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {if(i<=1)
     {a[i]=1;
     }
     else{
         a[i]=(a[i-1]+a[i-2])%10;
     }

    }

    return a[n-1];
}
int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c=fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    return 0;
    }
