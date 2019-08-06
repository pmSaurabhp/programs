//to print series 2 3 4 6 6 9 8......
#include<conio.h>
#include<stdio.h>
void main()
{
int i,j;
clrscr();
for(i=1,j=1;i<=10 && j<=5;i++,j++)
 {
  printf("%d\t",j*2);
  i++;
  printf("%d\t",j*3);
 }
getch();
}