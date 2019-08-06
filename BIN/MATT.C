#include<conio.h>
#include<stdio.h>
void main()
{

int a[2][2],b[2][2],i,j,s[2][2];
clrscr();
printf("enter no ");
for(i=0;i<2;i++)
{for(j=0;j<2;j++)
{scanf("%d  %d",&a[i][j],&b[i][j]) ;
}}
for(i=0;i<2;i++)
{for(j=0;j<2;j++)
s[i][j]=a[i][j]+b[i][j]    ;
   }
   for(i=0;i<2;i++)
   {for(j=0;j<2;j++)
printf(" %d",s[i][j]);
printf("\n");
 }
getch();
}