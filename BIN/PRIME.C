//to find prime numbers between 1 and 300
#include<conio.h>
#include<stdio.h>
void main()
{
int i,flag,j;
clrscr();
for(i=2;i<=300;i++)
 {
  flag=0;
  for(j=2;j<=i/2;j++)
  {
   if(i%j==0)
   {
   flag++;
   break;
   }
  }
  if(flag==0)
  printf("%d\t",i);
 }
getch();
}