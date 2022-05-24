// https://leetcode.com/problems/reverse-integer/
#include <bits/stdc++.h>
using namespace std;

void reverse(int n)
{   
    int ans=0;
    while(n!=0){
       int digit= n%10;
       n=n/10;
        // no need to make long long int
        if(ans>INT_MAX/10 || ans<INT_MIN/10) // ans*10 > INT_MAX 
            { ans=0;
              break;
            }
        ans = ans*10+digit;
    }
    cout<<ans<<"\n";
}
int main()
{
    int n;
    cin>>n;

    reverse(n);
}