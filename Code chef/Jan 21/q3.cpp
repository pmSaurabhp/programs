#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 { int n,m,c_a=0,c_b=0;
   cin>>n>>m;
   vector<int> a(n),b(m);
   for(int i=0;i<n;i++)
     { cin>>a[i];
        c_a+=a[i];
     }
   for(int i=0;i<m;i++)
   {cin>>b[i];
       c_b+=b[i];
   }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;


            while(c_a<=c_b&&i<n&&m-1-i>=0)
          { if(a[i]<b[m-1-i])
            { c_a= c_a-a[i]+b[m-1-i];
              c_b= c_b+a[i]-b[m-1-i];
                swap(a[i],b[m-1-i]);
                i++;
            }
            else
            break;
          }

          if(c_a>c_b)
            cout<<i<<"\n";
         else
            cout<<"-1\n";


 }
}
