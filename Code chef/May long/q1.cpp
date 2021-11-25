#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int power(int x,int p)
{ int limit=1000000007;

    if(p==0)
        return 1;
    int temp=power(x,p/2);

    if(p%2==0)
        return ((temp%limit)*(temp%limit))%limit;
    else
        return ((x%limit)*(temp%limit)*(temp%limit))%limit;

}
int main() {


	int t;
  cin>>t;

 while(t--)
 {  int n;
    cin>>n;

    cout<<power(2,n-1)<<"\n";
 }
	return 0;
}
