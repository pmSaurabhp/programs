#include <iostream>
using namespace std;

int main()
{ int n;
cin>>n;

long long int b[n],h[n];

for(int i=0;i<n;i++)
    cin>>b[i];

for(int i=0;i<n;i++)
    cin>>h[i];

for(int i=0;i<n;i++)
{ int t=b[i]+h[i];
 for(int j=i+1;j<n;j++)
    { if(t>=b[j]&&t<b[j]+h[j])
        { t=b[j]+h[j];
        }
        if(t<b[j])
            break;
    }
    cout<<t<<"\n";
}

}
