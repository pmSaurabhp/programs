#include<iostream.h>
#include<conio.h>
void main()
{ int a,c=0,i;
clrscr();
cin>>a;
for(i=1;i<=a;i++)
{if(a%i==0)
   { c++;
   }
}
if(c==2)
{cout<<"no. is prime";
}
else
{cout<<"no. is composite";
}
getch();
}