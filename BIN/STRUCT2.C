
#include<conio.h>
#include<stdio.h>
struct dob
{ int day;                      //nested struct
  int month;
  int year;
};
struct employee
{ int empid;
char name[10];
struct dob a;
};
void main()
{clrscr();
struct dob a;
struct employee b;      // run time
 struct employee c={1007,"sks",29,9,1997};  //compile time
 scanf("%d %s %d %d %d ",&b.empid,&b.name,&b.a.day,&b.a.month,&b.a.year);
 printf("%d %s %d %d %d \n",b.empid,b.name,b.a.day,b.a.month,b.a.year);
  printf("%d %s %d %d %d",c.empid,c.name,c.a.day,c.a.month,c.a.year);
getch();
}