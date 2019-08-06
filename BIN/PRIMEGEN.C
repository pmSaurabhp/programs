#include<stdio.h>
int main()
{
int t,flag,i=1,j,k;
long m[t],n[t];
printf("enter the no of test cases: ");
scanf("%d",&t);
if(t<=10)
  {
  printf("enter the intervals: ");
  while(i<=t)
  {
  scanf("%d\t%d",&m[i],&n[i]);
  if(1<=m[i]<=n[i]<=1000000000 && n[i]-m[i]<=100000)
   {
   i++;
   }
  else
  {printf("invalid entry");
   break;}
  }
  for(i=1;i<=t;i++)
  {
    for(j=m[i];j<=n[i];j++)
    {
     flag==0;
     for(k=2;k<=n[i]/2;k++)
     {
       if(j%k==0)
       {
	flag==1;
	break;
       }
     }
     if(flag==1)
       printf("\n %ld",j);
    }
  }
 return 0;
}