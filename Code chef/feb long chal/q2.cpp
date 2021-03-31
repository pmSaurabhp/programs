#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Frog
{
public:

    int w,jump,p;
};

bool compare_fun(Frog f1,Frog f2)
{
    return f1.w<f2.w;
}

int factor(int p1,int p2,int j)
{ int f=(p1-p2)/j;

   return f+1;
}

int main()
{ int t;
cin>>t;

 while(t--)
 {
     int n;
     cin>>n;

     Frog arr[n];

     for(int i=0;i<n;i++)
        cin>>arr[i].w;

     for(int i=0;i<n;i++)
        cin>>arr[i].jump;
     for (int i=0; i<n; i++)
        arr[i].p=i+1;

    sort(arr,arr+n,compare_fun);


    for(int i=0;i<n;i++)
        cout<<arr[i].w<<" ";
    for(int i=0;i<n;i++)
        cout<<arr[i].jump<<" ";
    for(int i=0;i<n;i++)
        cout<<arr[i].p<<" ";
  int hit=0;
    for (int i=1; i<n; i++)
    {
        if(arr[i-1].p >= arr[i].p)
        { int f=factor(arr[i-1].p,arr[i].p,arr[i].jump);
          hit+=f;

         arr[i].p = arr[i].p + arr[i].jump * f;
        }

    }

    cout<<hit<<"\n";

 }
}
