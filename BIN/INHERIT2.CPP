     // hybrid inheritance
#include<iostream.h>
#include<conio.h>
class salary
{ protected:
int sal;     // protected members can only be accessed directly
char a[10];  // by member function of base class and derived class

public:                                       salary
  void take()                                   |
 { int j,n;                                     |
 cout<<endl;                                  income    deducte
 cout<<"\n length of name n=";                   |        |
 cin>>n;                                         |        |
 cout<<" name-";                                  - - - -
  for(j=0;j<n;j++)                                   |
  { cin>>a[j];                                      pay
  }
 cout<<"sal=";
  cin>>sal;

 }
  void disp()
  {
  cout<<" sal="<<sal<<endl;
  }
};
class income:public salary
{
protected:
int i,bonus;
public:
   void t()
  { cout<<"bonus=";

  cin>>bonus;
  }
  void add()
  { i=sal+bonus ;
  cout<<"bonus+sal="<<i;
  }
  void d()
  {cout<<" income="<<i;
  }
};
class deducte
{ protected:
  int tax;
  public:
  void take2()
  { cout<<"\n tax=";
    cin>>tax;
  }
};
class pay:public income,public deducte
{ int p;
public:
void total()
{ p=i-tax;
cout<<"p="<<p;
}

void person()
{
 take();
 t();
 add();
 take2();
 total();
}
};
void main()
{ clrscr();
  pay obj1,obj2;
  obj1.person();
  obj2.person();
  getch();
}