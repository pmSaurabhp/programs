#include <iostream>
#include <cmath>    // i forgot this & used math.h
using namespace std;

void sum(long long int m)
{
  int c;
  while(1)
  {  c=0;
      while(m)
      {
        c += m % 10;
        m = m/10 ;
      }
     if(c <= 9)
        break;

    m=c;
  }

    cout<<c<<"\n";
}
int main()
{ int t;
  cin>>t;

 while(t--)
 { long long int n;
    cin>>n;
                        // otimization
    n=n%6;                    // https://math.stackexchange.com/questions/1101403/how-to-calculate-the-sum-of-digits-of-2n/1101435#1101435?newreg=a461f72df8d743bc90df6ebd2aeacf54

    long long m=pow(2,n);

    sum(m);
 }

}
