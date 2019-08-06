#include<conio.h>
#include<stdio.h>
void main()
{

int r,c,a[2][2];
clrscr();
printf("enter no ");
for(r=0;r<2;r++)
 {for(c=0;c<2;c++)
 scanf("%d",&a[r][c]) ;
 }
for(r=0;r<2;r++)
 {for(c=0;c<2;c++)
 printf("%d",a[r][c]);
 printf("\n");
 }
getch();
}