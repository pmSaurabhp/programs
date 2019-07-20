#include<iostream.h>
#include<conio.h>

class test
{ int a;
public:
 test(int x)             // parameterized constructor
 { a=x;
 }
 test(const test &t)     // copy constructor
 { a=t.a;
 }
 void count()
 { a++;
 }
 void disp()
 { cout<<"value of a="<<a<<endl;
 }
};
 void main()
 { clrscr();
 test obj1(2),obj3(0);
   obj1.count();

 test obj2(obj1);
   obj2.count();
   obj3.count();
   obj1.count();
   obj1.disp();
   obj2.disp();
   obj3.disp();
   getch();
 }