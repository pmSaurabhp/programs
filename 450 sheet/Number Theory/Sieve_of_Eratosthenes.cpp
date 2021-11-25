// C++ program to print all primes
// smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
#define int long long
void SieveOfEratosthenes(int n)
{

    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    int prime[n + 1];
    for(int i=0;i<n+1;i++)  // initialy all are prime
        prime[i]=1;

    for (int p = 2; p <= sqrt(n); p++)
    {
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple of p .
            //
            //  less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }                                         // T(n) = O( n*log(log(n)) )

    // Print all prime numbers
//    for (int p = 2; p <= n; p++)
//        if (prime[p])
//            cout << p << " ";
}

// Driver Code
int32_t main()
{
    int n = 1000000;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
