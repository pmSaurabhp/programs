#include<conio.h>
#include<stdio.h>
int main()
{
int i,n,fact=1;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 if(n==0)
 return 1;
 else
 fact=fact*i;
}
printf("%d",fact);
return 0;
}