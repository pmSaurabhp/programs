#include<conio.h>
#include<stdio.h>

struct employee
{ int empid;
char name[10];
int sal;
};
void main()
{clrscr();
 int i;
struct employee a[10];
for(i=0;i<10;i++)
{ printf(" employes id,name,salary " )  ;
scanf("%d  %s %d",&a[i].empid,a[i].name,&a[i].sal);
}
for(i=0;i<10;i++)
{printf("%d %s %d",a[i].empid,a[i].name,a[i].sal);
}


getch();
}