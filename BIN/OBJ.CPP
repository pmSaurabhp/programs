#include<iostream.h>
#include<conio.h>

float area(int);
float area(int,int);

void main()
{
clrscr();
int h=8,b=4,r=5;
cout<<area(b,h)<<endl;
cout<<area(r);

getch();
}
 float area(int a,int b)
 { return a*b/2;
 }
 float area(int a)
 { return 3.14*a*a;
 }