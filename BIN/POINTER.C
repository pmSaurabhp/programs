#include<conio.h>
#include<stdio.h>
void main()
{int a=5,*b,**c;
clrscr();
b=&a;
c=&b;
printf("%u %u %u %u %u %u %u %u",*c,**c,c,b,*b,a,&a,&b);
getch();
}