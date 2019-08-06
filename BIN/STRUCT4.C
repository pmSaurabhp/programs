
#include<conio.h>
#include<stdio.h>
void ftn(struct employee *p);      // passing address of structure

struct employee
{ int empid;
char name[10];
float sal;
};

void main()
{clrscr();
struct employee a;
scanf("%d %s %f",&a.empid,&a.name,&a.sal);
ftn(&a);
getch();
}
void ftn(struct employee *p)
{ printf("%d %s %f",p->empid,p->name,p->sal);
}
