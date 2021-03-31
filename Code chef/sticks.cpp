#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void sticks(int n)
{vector<int> a(n);
for(int i=0;i<n;i++)
{ cin>>a[i];
}
sort(a.begin(),a.end());
int temp=a[0],c=1;
for(int i=1;i<n;i++)
{  if(temp!=a[i])
    { c++;
    temp=a[i];
    }
}
cout<<c<<"\n";

}
int main()
{

int n,t;
cin>>t;
while(t)
{
 cin>>n;
sticks(n);
t--;
}
return 0;
}
