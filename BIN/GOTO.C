#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{ int n;
clrscr();
printf("enter no. of goals");
scanf("%d",&n);
if(n<2)
goto sos;
else
{printf("india will win");
}
exit
sos:
printf("lose");
getch();
}