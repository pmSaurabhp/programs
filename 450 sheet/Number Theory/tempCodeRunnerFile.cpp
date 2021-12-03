#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int binary=0;
    int i=0;
    while(n!=0)
    {  
        int digit=n%2;                      // 1 0 1
        n=n/2;                               // 2 1 0

        binary+=digit*int(pow(10,i));      // 1 1 101
        cout<<digit<<" "<<n<<" "<<binary<<"\n";
        i++;                                // 1 2 3
    }

    cout<<binary;
}