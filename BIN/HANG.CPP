#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
void main()
{ clrscr();
char movie[]="chennai";
char movie2[]="dangal";
int n=strlen(movie);
char a[]="*******";
char b;
int exit=1;
while(exit)
{

cout<<"enter a alphabet =";
 cin>>b;
 for(int i=0;i<n;i++)
 {
   if(movie[i]==b)
   { a[i]=b; }
 }
 puts(a);
 if(strcmp(movie,a)==0)
 {exit=0; }
}
getch();
}