#include<stdio.h>
#include<conio.h>
void wait();
void main()
{ clrscr();
 wait();
 printf("excaped");
 getch();
 }
 void wait()
 { int s;
 while(s<=5)
 { printf("huhahahaha traped");
   scanf("%d",&s);
 }
 }