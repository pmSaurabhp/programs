#include<iostream.h>
#include<conio.h>
class str
{ int n;
  char a[10];
  public:
  void take();
  void operator==(str obj);

};

 void str::take()
 { int i;
   cout<<"enter n";
   cin>>n;
   cout<<"enter elements of array";
   for(i=0;i<n;i++)
   { cin>>a[i];
   }
  }

  void str::operator==(str obj)
  {  int i,c=0,k;
     if(n>=obj.n)                  // which string is greater
      { k=n; }
     else
     { k=obj.n; }

     for(i=0;i<k;i++)                    // To check each element
	  { if(a[i]==obj.a[i])
	     {  c++;  }
	  }
     if(c==k)
     {cout<<"equal";
     }
     else
     {cout<<"not equal";
     }
  }
void main()
{ clrscr();
  str obj1,obj2;
  obj1.take();
  obj2.take();
   obj1==obj2;

   getch();
}