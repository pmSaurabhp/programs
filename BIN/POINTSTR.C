#include<stdio.h>
#include<conio.h>
struct node
{ struct node *j;
};
void main()
{
struct node *a,*b,*c;
clrscr();

  a->j=b;
  b->j=c;
  c->j=a;

  printf("%u %u %u %u %u %u",a,&b,b,*b,&c,c,&a);
  getch();
}

