#include<conio.h>
#include<stdio.h>
void main()
{
int i,n,high,low=0,m,s,a[10];
clrscr();

printf("enter n");
scanf("%d",&n);
high=n-1;
printf("enter elements of array");
for(i=0;i<n;i++)
{ scanf("%d",&a[i]);
}
printf("enter no. to be searched");
scanf("%d",&s);
while(low<=high)
{  m=(low+high)/2;
if(a[m]==s)
   { printf(" found at location%d",m+1);
     break;
     }
     else if(a[m]>s)
     { high=m-1;}
   else
    { low=m+1;  }
   }
   if(low>high)
   printf("%d is not presnt",s)  ;
   getch();
   }