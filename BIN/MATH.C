#include<math.h>
#include<conio.h>
#include<stdio.h>
void main()
{clrscr();
int x,i,n,s=0;
printf("enter x, n");
scanf("%d%d",&x,&n) ;
for(i=1;i<=n;i=i+1)
{s=s+pow(x,i)*pow(-1,i+1) ; }
printf("the series is %d",s);
getch();
}