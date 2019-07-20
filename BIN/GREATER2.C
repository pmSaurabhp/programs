#include<conio.h>
#include<stdio.h>
void main()
{
clrscr()    ;
int a,b,c ;
printf ("the value of a,b,c");
scanf("%d%d%d",&a,&b,&c);
if( a>=b+c)
{
printf (" a is greater");
    }
    if(b>=a+c)
{ printf(" b is greater")   ;
}
if(c>=a+b)
{printf("c is geater");
}
getch()         ;
}
