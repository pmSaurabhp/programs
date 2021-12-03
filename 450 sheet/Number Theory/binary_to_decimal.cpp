#include <bits/stdc++.h>
using namespace std;

void convert(int n)
{   int decimal=0;
    int i=0;
    while(n!=0){
       int digit= n%10;
       n=n/10;
        if(digit==1)
            decimal += pow(2,i);

        i++;
       
    }
    cout<<decimal<<"\n";
}
int main()
{
    int n;
    cin>>n;

    convert(n);
}