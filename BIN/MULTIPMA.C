#include<conio.h>
#include<stdio.h>
void main()
{ clrscr();
int a[2][2],b[2][2],c[2][2],i,j,k;
printf("\n matrix 1:\n") ;
for(i=0;i<2;i++)
 {for(j=0;j<2;j++)
  { scanf("%d ",&a[i][j]);
  }
 }
  for(i=0;i<2;i++)
  {for(j=0;j<2;j++)

   {scanf("%d",&b[i][j]);
    }
  }

  for(i=0;i<2;i++)
  {for(j=0;j<2;j++)
   { c[i][j]=0;
    for(k=0;k<2;k++)
    {c[i][j]=a[i][k]*b[k][j]+c[i][j];
    }
   }
  }
for(i=0;i<2;i++)
 {for(j=0;j<2;j++)
 printf("  %d",c[i][j]);
 printf("\n");
 }

getch();
}