#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void insert();
char a[10];
void main()             //  - = 45
{ clrscr();
   int j;
  a[0]='-';
  for(j=0;j<9;j++)
  { puts(a);
  getch();
    clrscr();
    insert();
  }
 getch();
 }
 void insert()
 { int i;
 for(i=strlen(a);i>=0;i--)
  { a[i+1]=a[i];
  }
  a[0]=' ';
 }