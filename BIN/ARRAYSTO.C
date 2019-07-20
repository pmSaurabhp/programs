#include<conio.h>
#include<stdio.h>
void prin(int a[]);
void main()
 { int i,a[]={5,6,7,8};
 clrscr();
 prin(a);
 getch();
 }
 void prin(int a[])
 { int i;
  for(i=0;i<4;i++)
 {printf("%d",a[i]) ; }
 }