#include<fstream.h>
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
 ifstream fin;
 char ch;
 fin.open("myfile");         // end of function = end reached = 1
  while(fin.eof()!=1)
 { fin>>ch;            // >> operator sees \n as data separator so it
   cout<<ch;           //  does not reads it
 }
 fin.close();
 cout<<endl;

 fin.open("myfile");
 while(fin.eof()!=1)
 { ch=fin.get();      // \n is not a data separator for get() function
   cout<<ch;
 }
 getch();
 }