#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class str
{
  char a[10];
  public:
  void take();
  void operator==(str obj);

};

 void str::take()
 {
   cout<<"enter string";
   gets(a);
 }

  void str::operator==(str obj)
  { if( strcmp(a,obj.a)==0)       // sksA==sks
     { cout<<" equal";   }        // diff= 65
  else
   {
   cout<<" not equal";}
   cout<<strcmp(a,obj.a);
  }

void main()
{ clrscr();
  str obj1,obj2;
  obj1.take();
  obj2.take();
   obj1==obj2;

  getch();
}