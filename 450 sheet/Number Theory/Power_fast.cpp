#include <iostream>

using namespace std;
                                //  for(i=1;i<n;i++)      // O(n)
                                //       x *= x;

                                //  power(x,n)                  //  T(n)=T(n-1)
                                //  { return x * power(x,n-1);  //      = O(n)
                                //    }
long long int power_recur(int x,long long int p)  // T(n) = 2 * T(n/2) + c
{ int limit=1000000007;                            //     = O(n)

    if(p==0)
        return 1;

    if(p%2==0)
        return (power_recur(x,p/2)*power_recur(x,p/2))%limit;
    else
        return ((x%limit)*(power_recur(x,p/2)*power_recur(x,p/2))%limit)%limit;

}
long long int power(int x,long long int p)   // T(n) =  T(n/2) + c
{ int limit=1000000007;                      //  T(n) =  O(log n)

    if(p==0)
        return 1;
    long long int temp=power(x,p/2)%limit;

    if(p%2==0)
        return (temp*temp)%limit;
    else
        return ((x%limit)*(temp*temp)%limit)%limit;

}
long long int exponentMod(int A, int B, int C) // T(n) = O(log n)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    long long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }

    // If B is odd
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }

    return (long long int)((y + C) % C);
}
int main() {




   for(long long int i=1;i<=600;i++)
        cout<<i<<" "<<power(2,i)<<" "<<exponentMod(2,i,1000000007)<<"\n";



	return 0;
}
