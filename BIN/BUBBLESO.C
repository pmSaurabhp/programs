#include<conio.h>
#include<stdio.h>
//int swap(int,int);
int main()
{
 int a[20],i,n,temp;
 printf("Enter the no. of elements:\n");
 scanf("%d",&n);
 printf("Enter the values:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
  if(a[i]>a[i+1])
  {
   temp=a[i];
   a[i]=a[i+1];
   a[i+1]=a[i];
  }//swap(a[i],a[i+1]);
 }
 for(i=0;i<n;i++)
 {
  printf("%d",a[i]);
 }
getch();
return 0;
}

/*int swap(int x, int y)
{
 x=x+y;
 y=x-y;
 x=x-y;
 return(x,y);
} */
