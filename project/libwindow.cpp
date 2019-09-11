
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string>
#include <windows.h>

using namespace std;


void writec(char a[]);
void writei(long int b);
void read();
void issue();
void search();
void count();
int frame();
void action();
void menu();
void disp();
void edit();

int k=0,i=0,j=0,q=0,flag=0,x=0,y=1,v,pointer=0,pointer2=-1;

int main()
{

    frame();



 return 0;

}
void issue()
{ int id;
long int date,bookid;
char a[10],book[10];

cout<<" student id :";
cin.ignore();
cin>>id;
flag=2;
writei(id);
flag=0;
cin.ignore();

cout<<"Enter student name :";
  gets(a);
  writec(a);
cout<<"Enter book name :";
  gets(book);
  writec(book);
cout<<"Enter book id";
  cin>>bookid;
  writei(bookid);
cout<<"Enter date :";
  cin>>date;
  flag=1;
  writei(date);
  flag=0;

 read();

}
void writec(char a[])
{
 ofstream fout;
 fout.open("myfile.txt",ios::app);

fout<<"\t";
 for(int i=0;i<strlen(a);i++)
{ fout<<a[i];   }
if(flag==1)
{ fout<<"\n"; }

 fout.close();

}
void writei(long int b)
{
 ofstream fout;
 fout.open("myfile.txt",ios::app);

 if(flag!=2)
 { fout<<"\t"; }
 fout<<b;
if(flag==1)
{ fout<<"\n"; }

 fout.close();

}
void read()
{  ifstream fin;
 char ch;
 fin.open("myfile.txt");         // end of function = end reached = 1

 while(fin.eof()!=1)
 { ch=fin.get();      // \n is not a data separator for get() function
   cout<<ch;
 }

count();
 }

 void search()
{  ifstream fin;

int j=0,c=0;
 char ch[10],s[10],word[70];
 fin.open("myfile.txt");         // end of function = end reached = 1
 cout<<"Enter id To search";
 gets(s);

 while(fin.eof()!=1)
 {
 ch[j]=fin.get();      // \n is not a data separator for get() function
   if(j==3)
  {  ch[4]='\0';
     if(strcmp(ch,s)==0)
     {  cout<<endl;
    printf("%s",ch);
	fin.getline(word,70);
	cout<<word;
     }
     else
     { c++;
	fin.getline(word,70);
       for(j=0;j<4;j++)
       { ch[j]=0;  }
       j=0;
     }

  }
  else
  { j++;   }

  }
  if(c>k)
  {cout<<"not found"; }

_getch();
 fin.close();

 }
void count()
{
  char word[70];
   ifstream fin;
  fin.open("MYFILE.txt");
  while(fin.eof()!=1)
  { fin.getline(word,70);
    k++;
  }
  k=k-1;
}

void action()
{  if(pointer==0)
  { read();
      _getch();
  }
    else if(pointer==1)
   {
       menu();
      _getch();
   }
   else if(pointer==2)
   {
       edit();
        _getch();
   }
}

void menu()
{   cout<<"*****Menu****** \n";
  cout<<"1. Issue books \n";
  cout<<"2. View Record \n";
  cout<<"3. Search \n";
  cout<<"4. Quit \n";
}
void disp()
{ cout<<"huhahahak \n";
  cout<<"gkadhlda \n";
  cout<<"ccccccccc \n";
}
void edit()
{
  string Menu2[2]={"ISSUE","SEARCH"};
for (int i = 0; i < 2; ++i)
		{
			if (i == pointer2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Menu2[i] <<endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		 		cout << Menu2[i] <<endl;
			}
		}


}


int frame()
{  int prev=-1;

	string Menu[4] = {"READ", "MENU" , "EDIT" , "Exit"};


	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Main Menu\n\n";

		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Menu[i] <<"     ";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] <<"     ";
			}
		}
         cout<<endl;
         cout<<endl;
		while(true)
		{
			if (GetAsyncKeyState(VK_LEFT) != 0)
			{  pointer2=-1;
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}

				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0)
			{    pointer2=-1;
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer2 -= 1;
				if (pointer2 == -1)
				{
					pointer2 = 1;
				}

				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer2 += 1;
				if (pointer2 == 2)
				{
					pointer2 = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer2)
				{
                    case 0:
					{  issue();
                        GetAsyncKeyState(VK_RETURN) == 0;
                        Sleep(1000);
					} break;
					case 1:
						search();
						GetAsyncKeyState(VK_RETURN) == 0;
						Sleep(1000);
					    break;
				}

                switch(pointer)
                {
                   case 3:
                        return 0;
                        break;
				}
                break;
			}
                action();
                break;
         }

Sleep(100);
	}

}

