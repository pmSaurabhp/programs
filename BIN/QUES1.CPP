#include<conio.h>
#include<stdio.h>
void main()
{ clrscr();
int a=1,b=1,c;
c=a||--b;
int d=a--&&--b;
printf("a=%d b=%d c=%d d=%d",a,b,c,d);
getch();
}