#include<iomanip.h>
#include<conio.h>
void main()
{ clrscr();

 cout<<"0123456"<<endl;
 cout<<setfill('*');
 cout<<setw(10)<<"789"<<endl;
 cout<<setw(20)<<"0123456789"<<endl;
 cout<<setprecision(2)<<3.14734<<endl;       // round off value
 cout<<setbase(10)<<0101<<endl;
 cout<<setbase(8)<<65<<endl;

 cout<<setfill(' ');
 cout<<endl;
 cout<<setw(20)<<setiosflags(ios::left)<<"cost";
 cout<<"200"<<endl;
 cout<<setw(20)<<setiosflags(ios::left)<<"no. of items";
 cout<<"5"<<endl;
 cout<<setw(20)<<setiosflags(ios::left)<<"name";
 cout<<"saurabh \n \n";


  getch();
}
