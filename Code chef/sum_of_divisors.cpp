#include<iostream>
using namespace std;

int main()
{
    int n,temp,sum=1;
    cin>>n;
    temp=n;
    for(int i=2;i<temp;i++)
    { if(n%i==0)
        {
            temp=n/i;
            sum=sum+i+temp;
        }

    }
    if(sum==n)
    {
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
return 0;
}
