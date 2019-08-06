#include<stdio.h>
#include<conio.h>
struct std
{ int id;
} ;
void main()
{clrscr();

struct std b,*p;
p=&b;
   scanf("%d",&p->id);
printf("%d \n",p->id);
printf("%u \n",&p->id);
   printf("%u",&b.id);
getch();
}