  // Overloading unary operator ++
#include<iostream.h>
#include<conio.h>
class bin
{ int a;
 public:
 void take()
 { cin>>a;
 }
  bin operator++()
  {  bin e;
  e.a=a++;
    return e;
  }
  void disp()
  { cout<<a;
  }
 };

 void main()
 { clrscr();
 bin obj1,obj2;
 obj1.take();
 obj2=obj1++;
  obj1.disp();
  obj2.disp();
   getch();
}