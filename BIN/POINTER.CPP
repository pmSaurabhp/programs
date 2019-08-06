#include<iostream.h>
#include<conio.h>
void sum(int b[]);
void main()
{ clrscr();
int a[5]={1,2,3,4,5},*p;
 p=a;
 sum(p);
 getch();
 }
 void sum(int b[])
 { int i,sum=0;
 for(i=0;i<5;i++)
 {sum=sum+b[i];
 }
 cout<<sum;
 }