#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--)
 { int n,k;
   cin>>n>>k;

   vector<int> h(n);
   for(int i=0;i<n;i++)
   { cin>>h[i];}

   sort(h.begin(),h.end());

   int mike=0,tracy=0,c=0;

   for(int i=n-1;i>=0;i--)
   { if(mike<k)
     { mike+=h[i];
       if(i-1>=0)
         tracy+=h[--i];
       c+=2;
     }
     else if(tracy<k)
      { tracy+=h[i];
        c++;
      }
      else
        break;

   }

   if(mike>=k&&tracy>=k)
    cout<<c<<"\n";
    else
     cout<<"-1\n";
 }
}

