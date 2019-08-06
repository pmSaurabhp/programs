#include<iostream.h>
#include<conio.h>
#include<math.h>
int fact(int n);
void main()
{
int j,n;
double x,sum=0,term,r;
clrscr();
cout<<"Enter the value of x and n respectively :\n";
cin>>x>>n;
r=x*3.14/180;
cout<<"\n converting "<<x<<" into radians :"<<r<<endl;
for(j=1;j<=n;j++)
  {
   sum=sum+pow(-1,j+1)*pow(r,2*j-1)/fact(2*j-1);
  }
cout<<"The sum of series is : "<<sum;
getch();
}

int fact(int k)
{
int f=1,i;
for(i=0;i<k;i++)
{
f=f*(k-1);
}
return f;
}