#include <iostream>

using namespace std;

int prime_fast(int n)
{
  if(n<=1) return 0;
  if(n==2||n==3)  return 1;

  if(n%2==0 || n%3==0) // this is done to skip 5 elements between  i & i+6 in for loop
    return 0;          // eg. i = 11 & i+6= 17 so 12 13 14 15 16 are skipped

                             // we go till root(n) as  larger factor of n must be a multiple
                             // of smaller factor that has been already checked
  for(int i=5;i*i<=n;i++)    // as seen in factorization
    { if(n%i==0 || n%(i+2)==0) //difference between most prime number is 2
        return 0;
    }

return 1;
}
int main()
{int n;
    cin>>n;
cout<<(prime_fast(n) ? "True" : "False");
}







