#include <iostream>

using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 { int n,k,x,y;
   cin>>n>>k>>x>>y;

   if(x==y)
    cout<<n<<" "<<n<<"\n";
   else{
   k=k%4;
   if(x>y)
   { if(k==1)
     {  y=n-x+y; x=n;}
     else if(k==2)
     {  x=n-x+y;  y=n;}
     else if(k==3)
     {  y=x-y; x=0;}
     else
     { x=x-y; y=0;}
   }
   else if(x<y)
   {  if(k==1)
     {  x=n-y+x;  y=n;}
     else if(k==2)
        {  y=n-y+x; x=n;}
     else if(k==3)
     { x=y-x; y=0;}
     else
     {  y=y-x; x=0;}


   }
    cout<<x<<" "<<y<<"\n";
   }
 }
}
