#include<stdio.h>
#include<conio.h>
int sum();
void diff();
void main()
{
int c,choice;
clrscr();
printf("enter the choice");
scanf("%d",&choice);
switch(choice)
 {
    case'+':
    c=sum();
    printf("%d",c);
    break;
    case '-':
    diff();
    break;
 }
 getch();
}
 void sum()
 {
 int a=4,b=5,c;
 c=a+b;
 return c ;
}
void diff()
{ int a=2,b=4,c;
c=b-a;
printf("%d",c);
}