#include<math.h>
#include<conio.h>
#include<stdio.h>
void main()
{clrscr();
int i,n,s=1;
printf("enter n");
scanf("%d",&n) ;
for(i=n;i>=1;i=i-1)
{s=s*i; }
printf("the FACTORIAL is %d",s);
getch();
}