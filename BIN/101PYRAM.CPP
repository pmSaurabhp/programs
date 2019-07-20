#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
int i,j,k,l,n;
cout<<"Enter now of rows";
cin>>n;
for(i=0;i<n;i++)
{ for(j=n-2;j>=i;j--)
  { cout<<" ";
  }
  for(k=i;k>=0;k--)
  { cout<<k;
  }
  for(l=1;l<=i;l++)
   cout<<l;
  cout<<endl;
 }

 getch();
 }