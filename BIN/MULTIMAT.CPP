#include<conio.h>
#include<iostream.h>
void main()
{ clrscr();
int a[2][2],b[2][2],c[2][2],i,j,k;
cout<<"\n matrix 1:\n";
for(i=0;i<2;i++)
 {for(j=0;j<2;j++)
  { cin>>a[i][j];
  }
 }
 cout<<"\n Matrix 2 :\n";
  for(i=0;i<2;i++)
  {for(j=0;j<2;j++)
   {cin>>b[i][j];
    }
  }
    cout<<"\n matrix 1:\n";
for(i=0;i<2;i++)
 {for(j=0;j<2;j++)
  { cout<<" "<<a[i][j];
  }
  cout<<endl;
 }
 cout<<"\n Matrix 2 :\n";
  for(i=0;i<2;i++)
  {for(j=0;j<2;j++)
   {cout<<" "<<b[i][j];
    }
    cout<<endl;
  }

  for(i=0;i<2;i++)
  {for(j=0;j<2;j++)
   { c[i][j]=0;
    for(k=0;k<2;k++)
    {c[i][j]=a[i][k]*b[k][j]+c[i][j];
    }
   }
  }
  cout<<"Product of Matrix 1 and Matrix 2 : \n";
for(i=0;i<2;i++)
 {for(j=0;j<2;j++)
 {cout<<" "<<c[i][j];
 }
 cout<<endl;
 }
getch();
}