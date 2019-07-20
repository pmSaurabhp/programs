#include<iostream.h>
#include<conio.h>
class c;
class a
{ int b;
public:
  friend void func(a obj1,c obj2);
  void take()
  { b=2;
  cout<<"b="<<b<<endl;
  }
 };
class c
{ int d;
public:
friend void func(a obj1,c obj2);
void take()
{ d=8;
 cout<<"d="<<d<<endl;
}
};
void func(a obj1,c obj2)
{ int t;
t=obj1.b;
obj1.b=obj2.d;
obj2.d=t;
cout<<"swapped no. are b=";
cout<<obj1.b<<"  d="<<obj2.d<<endl;

}

void main()
{
clrscr();
 a obj1;
 c obj2;

obj1.take();
obj2.take();
func(obj1,obj2);

getch();
}
