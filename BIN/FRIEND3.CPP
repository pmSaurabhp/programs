#include<iostream.h>
#include<conio.h>
class c;
class a
{ int b;
public:
  int take()
  { b=2;
  cout<<"b="<<b<<endl;
  return b;
  }

 };
class c
{ int d;
public:

int take()
{ d=8;
 cout<<"d="<<d<<endl;
 return d;
}
};

void main()
{
clrscr();
 a obj1;
 c obj2;

int t;
t=obj1.take();
obj1.take()=obj2.take();               // left value
obj2.take()=t;                         // 5=a
cout<<"swapped no. are b=";
cout<<obj1.take()<<"  d="<<obj2.take()<<endl;

getch();
}
