#include<conio.h>
#include<stdio.h>
void main()
{ int i,a[10],n,p=4,b=9;
clrscr();
printf("enter n");
scanf("%d",&n);
printf("enter elements");
for(i=0;i<n;i++)
{ scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{ printf("%d",a[i]);
}
 for(i=n-1;i>=p-1;i--)         // loop do not work if p>n
 { a[i+1]=a[i];                // i.e. insert at last position
 }
 a[p-1]=b;

 printf("\n");
 for(i=0;i<n+1;i++)
{ printf("%d",a[i]);
}
getch();
}
