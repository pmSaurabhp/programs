#include<conio.h>
#include<stdio.h>
void fn(int a,int b,int n,int i);
void main()
{clrscr();
 int a=0,b=1,c,i=3,n;
scanf("%d",&n);
printf("%d %d",a,b);
fn(a,b,n,i);
 getch();
 }
 void fn(int a,int b,int n,int i)
{ int c;
   if(i<=n)
  {c=a+b;
  a=b;
  b=c;
  i=i++;
  printf(" %d",c);
  fn(a,b,n,i);
  }
}