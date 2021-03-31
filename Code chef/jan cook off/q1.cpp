#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

void SieveOfEratosthenes(bool prime[],int n)
{
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        { for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


int main()
{
 int t;
 cin>>t;
 bool prime[1000001];
 memset(prime, true, sizeof(prime)); // initialize all with true
SieveOfEratosthenes(prime,1000000);

 vector<int> precompute(1000000);

  int c=0,x=3;
   for(int i=1;i<=1000000;i++)       // T(n) = O(1)
   {

       if(i<5) precompute[i]=0;

    else{
         if(prime[i])
        {
            if(i-x==2)
                c++;

            x=i;
         }
         else
            precompute[i]=c;
       }

   }

 while(t--)    // T(n)= t * O(1)   =  O(t)
 { int n;
   cin>>n;
  cout<<precompute[n]<<"\n";

 }

}
