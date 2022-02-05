#include <bits/stdc++.h>
using namespace std;

int squareInt(int n)
{
    int l=0,h=n;
    long long int ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        long long int square=mid*mid;
        if(square==n)
            return mid;
        
        if(square<n)
        { l=mid+1;
          ans=mid;
        }
        else
            h=mid-1;
    }
    return ans;
}
// double squarePrecision(int n,int p)
// {
//     double ans=squareInt(n);
//     for(int j=1;j<=p;j++)
//     { double ansTemp;
//         for(double i=1;i<=9;i++)
//         {   double d=i/pow(10,j);
//             double total=ans+d;
//             double square=total*total;
//             if(square<=n)
//                 ansTemp=total;
//             else
//                 break;
//         }
//         ans=ansTemp;
//     }
//     return ans;
// }

// better solution
double squarePrecision(int n,int p)
{
    double ans=squareInt(n);
    double d=1;
    for(double j=1;j<=p;j++)
    { d=d/10;                           // 0.1  0.01    0.001
      for(double i=ans;i*i<=n;i=i+d)    // i=   0.1  0.2  0.3  0.4  ....
      { ans=i;
       // cout<<i<<"\n";
      }
        //cout<<ans<<"\n";
    }
    return ans;
}

int main()
{
    int n=10;
   cout<< squarePrecision(n,3);
}