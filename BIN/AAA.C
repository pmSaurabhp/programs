#include<stdio.h>
#include<conio.h>
void main()
{ clrscr();
int a=5,b,c;
b=a--;
b=--a;
c=(a-- + ++a)    ;
printf ("%d  %d",b,c);
getch();
}
