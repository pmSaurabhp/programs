#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class str
{
  char a[10];
  public:
  void take();
  void operator+(str obj);
  void disp()
  { cout<<"concatenated string = "<<a;
  }
};

 void str::take()
 {
   cout<<"enter string";
   gets(a);

 }

  void str::operator+(str obj)
  {
  strcat(a,obj.a);

  }

void main()
{ clrscr();
  str obj1,obj2;
  obj1.take();
  obj2.take();
  obj1+obj2;
  obj1.disp();

  getch();
}