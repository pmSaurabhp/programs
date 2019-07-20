#include<iostream.h>
#include<conio.h>
class test
{ int a;

 public:
 int b;
 void take()
 { cout<<"a=";
 cin>>a;

 }
 void disp()
 {
 cout<<"a="<<a;
 }
};
void main()
{ clrscr();
 test obj;

 obj.take();
 cout<<"b=";
 cin>>obj.b ;
 obj.disp();
 cout<<"b="<<obj.b;

 getch();
}