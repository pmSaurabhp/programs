// run this in codechef ide
// given a array of numbers . if a number is not prime then convert it into nearest prime number
// by adding or deleting 1 each time
// find sum of these modifications

// 4
// 4 2 10 25
// output   4
//    4 is betw 3 & 5  so add 1 , 2 is prime number, 10 is betw 7 & 11 near to 11 so 1, 25 is betw 23 & 29 near to 23 so 2
// 1+0+1+2 = 4
#include <bits/stdc++.h>

using namespace std;
 void fun(vector<int> arr)
 {  int n=100000001;
     int sieve[n];

    for(int i=0;i<=n;i++)
        sieve[i]=1;


    for(int i=2;i<=10000;i++)
    {   if(sieve[i]==1)
        {for(int j=i*i;j<n;j=j+i)
         { sieve[j]=0;
         }
        }
    }

    int sum=0;
    for(int i=0;i<arr.size();i++)
    { int l=arr[i],h=arr[i];
        if(arr[i]==1)
            sum+=1;
        if(sieve[arr[i]]==0)
        { while(sieve[l]==0 || sieve[h]==0)
            {
                if(sieve[l]==0)
                    l--;
                if(sieve[h]==0)
                    h++;
            }

            sum+=min(arr[i]-l,h-arr[i]);
        }
    }
    cout<<sum;
 }
int main()
{
  int n;
  cin>>n;

  vector<int> arr(n);
  for(int i=0;i<n;i++)
      cin>>arr[i];

    fun(arr);
}
