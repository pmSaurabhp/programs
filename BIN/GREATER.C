#include<conio.h>
#include<stdio.h>
void main()
{
clrscr()    ;
int a,b,c ;
printf ("the value of a,b,c");
scanf("%d%d%d",&a,&b,&c);
if( (a>b)&&(a>c))
{
printf (" a is greater");
    }
    if((b>c)&&(b>a))
{ printf(" b is greater")   ;
}
else
{printf("c is grter");
}
getch()         ;
}
