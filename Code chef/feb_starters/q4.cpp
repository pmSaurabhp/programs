// my solution differenr from editorial  :) and faster
#include <iostream>
#include <string>
using namespace std;

int check(string s, int n,int c)
{
    int d=-1;
   for(int i=0;i<n;i++)
   {     if(s[i]=='1')
          { if(d==-1)
              d=i;
            else if(i-d-1>c)
                {
                    return 0;
                }
                else
                d=i;
          }

   }
   return 1;
}
int max_dist(string s, int n,int c)
{
    int d=-1;
   for(int i=0;i<n;i++)
   {     if(s[i]=='1')
          { if(d==-1)
              d=i;
            else if(i-d-1>c)
                {
                    return i;
                }
                else
                d=i;
          }

   }
   return 0;
}
int main() {
	int t;
  cin>>t;

 while(t--)
 {  int n,c;
    cin>>n>>c;

    string s;
    cin>>s;

    int f1;


    int m=max_dist(s,n,c);  // we find max distance between 1

    if(m==0) f1=1;
    else{
        int j=n-m;
    while(j--)       //   we bring that 1 at front by rotating
    {int temp=s[n-1];
    for(int i=n-1;i>=0;i--)
       {
            s[i]=s[i-1];

       }
    s[0]=temp;
    }

    f1=check(s,n,c);    // check whether this string has gap <= c

    }

   cout<<(f1==1 ? "YES\n" : "NO\n");

 }
	return 0;
}
