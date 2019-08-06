
#include<conio.h>
#include<stdio.h>
void ftn(struct employee *p);
				   //size of data types in structure
struct employee
{ float empid;
int name[3];
float sal;
float f;
int t;
};

void main()
{ int i;
float c=6,d=5;
struct employee a;
clrscr();
printf("%u %u",&c,&d);
scanf("%f %f %f %d",&a.empid,&a.sal,&a.f,&a.t);
for(i=0;i<3;i++)
{ scanf("%d",&a.name[i]);
}
ftn(&a);
getch();
}
void ftn(struct employee *p)
{ int i;
printf("%u %u %u %u %u %u %u %u %u %u %u %u",&p,&p->empid,&p->name,&p->sal,&p->f,&p->t,p->empid,p->sal,p->f,p->t);
for(i=0;i<3;i++)
{printf(" \n %u \n",&p->name[i]);
}

}

