#include <iostream>
#include <vector>

using namespace std;

int main()
{ int t;
  cin>>t;

 while(t--)
 {  int k;
    int a[10];
    for(int i=0;i<10;i++)
        cin>>a[i];

    cin>>k;
    int c=1;
    for(int i=9;i>=0;i--)
    {
        if(k==0 && a[i]!=0)
        {  c=i+1;

              break;
        }
        else if(a[i]>=k)
        {
            a[i]=a[i]-k;
            k=0;
//            cout<<a[i]<<" ";
            if(a[i]!=0)
                i++;
        }
        else{
            k=k-a[i];
            a[i]=0;
//            cout<<k<<" ";
        }

    }

    cout<<c<<"\n";

 }

}
