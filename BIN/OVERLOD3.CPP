  // Overloading binary operator << extraction operator
#include<iostream.h>
#include<conio.h>
class bin
{ int a;
 public:
  friend void operator>>(istream &in,bin &c)   // friend istream &operator>>(istream &in,bin &c)
  { in>>c.a;					  //  {  in>>c.a;
  }						  //     return in;
  friend void operator<<(ostream &out,bin c)	  //  }
  { out<<c.a;     				  //  friend ostream &operator<<(ostream &out,bin &c)
  }						  //  {  out<<c.a<<endl;
};						  //     return out;
						  //  }
 void main()
{ clrscr();
  bin obj1;
  cin>>obj1;
  cout<<obj1;
   getch();
}