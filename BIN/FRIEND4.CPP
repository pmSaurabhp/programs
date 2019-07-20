// add length in feet and inches and returning object
#include<iostream.h>
#include<conio.h>
class length
{ int feet;
 int inches;
 public:
 void take()
 {
   cin>>feet>>inches;
 }
length add(length obj2)
  { length obj3;
   obj3.feet=feet+obj2.feet+(inches+obj2.inches)/12;
    obj3.inches=(inches+obj2.inches)%12;
    cout<<obj3.feet<<" "<<obj3.inches;
   return obj3;
  }
  void disp()
  { length obj3;
   cout<<obj3.feet<<"feet"<<" "<<obj3.inches<<"inches";
  }
 };
 void main()
 { clrscr();
 class length obj1,obj2,obj3;
   obj1.take();
   obj2.take();
  obj3=obj1.add(obj2);

   getch();
}