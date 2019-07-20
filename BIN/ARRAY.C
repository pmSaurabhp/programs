#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
float m[6],i,s=0;
printf("enter marks");
for(i=0;i<6;i++)
{scanf("%f",&m[i])  ;
s=s+m[i];}
printf("sum is %f",s)  ;
getch();
}