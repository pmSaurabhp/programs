#include<iostream.h>
#include<conio.h>
class base
{ protected:
int a;

public:
  int take()
 {cout<<"a=";
  cin>>a;
  return a;
 }
  void disp()
  {
  cout<<" a="<<a<<endl;
  }
};
class derived:public base
{int i;
public:
   void t()
  { cout<<"i=";
  cin>>i;
  }
  void add()
  { cout<<" \n i+a="<<i+a;
  }
  void d()
  {cout<<" i="<<i;
  }
};
void main()
{ clrscr();
base o1;
derived obj;
 obj.take();
 o1.disp();
 obj.disp();
 obj.t();
 obj.d();
 obj.add();
 getch();
}