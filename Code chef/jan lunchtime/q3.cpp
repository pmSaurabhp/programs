#include <iostream>
#include <string>

using namespace std;

int main()
{
  int t;
  cin>>t;

  while(t--)
  { int n;
   cin>>n;

   string str;

    cin>>str;

  int c,c0=0,c1=0;
  for(int i=0;i<n;i++)
  { if(str[i]=='0')
        c0++;
    else
        c1++;

  }
    int t=c0;
    c1=0;

    for(int i=0;i<n;i++)
    {
         if(str[i]=='1')
            c1++;

         else
            c0--;

         t=min(t,c1+c0);
    }
     cout<<t<<"\n";            // 1 0 1 0 1 1                   1 0 1 0 1 1               1 0 1 0 1 1
  }               //   no. of 1s   ^  n0. of 0s         no. of 1s  ^  n0. of 0s     no. of 1s  ^  n0. of 0s
}                 //   before ptr     after ptr
                  //                                   take minimum of all till ptr reaches end
