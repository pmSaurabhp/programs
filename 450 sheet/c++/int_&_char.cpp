#include <iostream>
#include <string>  // stoi
#include <sstream>  // stringstream

using namespace std;
int main()
{                       // always use '' single quotes to assign  char a='1';   double quotes give error

char a='15';          // its wrong as "char a" means a is character  it cannot be not string i.e. why it
cout<<(int)a<<" ";    // gives ascii value of '5'  i.e last character of '15'
char b='9';
int c=a-b;              // 5-9 = -4  (not 15 - 9)
cout<<c<<"\n";

char f='8';     // change  char to int
int g= f - '0';   //   g = (int)f - (int)'0'
cout<<g<<"\n";  // it  works only   for  0 to 9

int d=4;            // convert  int to char
char e= d + '0';     // it also works only if 0 <= d <=9
cout<<e<<"\n";

//string h="15";     // use double quotes for string   & ' ' for char
//int i=stoi(h);      // it does not works in codeblocks because of mingw
//cout<<i<<"\n";

 string s = "12345";     // convert string to int
 stringstream sst(s);   // object from the class stringstream
 int x;
 sst >> x;      // stream of "12345" goes into x
 x /= 5;
 cout << "Value of x : " << x<<"\n";


 int i=21;
 stringstream its;
        its << i;
        string s1=its.str();       // str() to get and set string object whose content is present in stream
    cout<<"Int "<<i<<" converted to string "<<s1;
}
