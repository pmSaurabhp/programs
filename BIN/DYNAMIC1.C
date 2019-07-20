#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,*ptr,n;
clrscr();
 printf("no. of elements");
 scanf("%d",&n);
  ptr=(int*)malloc(n*sizeof(int)); // dynamic memory alocation (heap memory)
  for(i=0;i<n;i++)
  { ptr[i]=i+1;
  }
  free(ptr);                    // frees the heap memory
  for(i=0;i<n;i++)              // ptr still points heap memory
 { printf(" %d",ptr[i]);
 }
 printf("\n");
 ptr=NULL;                      // ptr points null address in stack memory
 for(i=0;i<n;i++)
 { printf(" %d",ptr[i]);
 }
 getch();
}