#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
void frame();
void jump();
void jumpl();
void move();
void direct();
			 // i=row=y
int i=0,j=0,q=0,flag=0,flagp=0,x=4,y=14,t=1,g=1,v1=1,v2=1;
int xb=20,yb=10;
void main()
{ clrscr();
  while(q==0)
 {
  system("cls");

  frame();
  move();
  direct();
  }

 getch();
}
void frame()
{ for(i=0;i<24;i++)
  {for(j=0;j<75;j++)
   { if(i==15)
      { cout<<"*";   }
      else
      {cout<<" ";  }

     if(i==y&&j==x)
     {cout<<"A"; }
      if(i==y-1&&j==x-1)
      { cout<<"|"; }
      if(i==y-2&&j==x)
      {cout<<"o"; }
      if(i==y-1&&j==x-2)
      { cout<<"/"; }
      if(i==y-1&&j==x)
      {cout<<"\\" ; }
 if(i==yb&&j==xb)
      {cout<<"-------"; }
    }
    cout<<endl;
   }

}
void move()
{
  if((x<=xb-1||x>=xb+8)&&y==yb-1)
      { flag=5;}
 while(kbhit())
 { switch(getch())
   {
     case 'a':
       if(flag!=3&&flag!=4&&flag!=5)
      { x--;
       flag=1;
       flagp=flag;
       }
      break;
     case 'd':
       if(flag!=3&&flag!=4&&flag!=5)
      { x++;
       flag=2;
       flagp=flag;
       }
       break;
      case 'w':
       if(flag!=3&&flag!=4&&flag!=5)
      { flag=3; }
       break;
      case 's':
       if(y<14)
      { y++; }
       break;

      case 'q':
       q=1;
       break;

       default :
       break;
    }
}
}
void direct()
{
   switch(flag)
  {
    case 3:

    if(y>10)
      {

      if(x==xb||x==xb+1||x==xb+2||x==xb+3||x==xb+4||x==xb+5)
	{ flag=5;
	goto down; }
      else if(flagp==2)
      { jump();

      }
      else
      {jumpl();

      }

       cout<<y;
       }
      else
      { flag=4; }

     break;

     case 4:
     down:
      if(y==yb-1&&(x==xb||x==xb+1||x==xb+2||x==xb+3||x==xb+4||x==xb+5||x==xb+6))
	{ flag=0;
	  goto label;
	 }

      if(y<14)
      { g=-g;
	t=0;
      if(flagp==2)
      {jump();
      if(y==14)
     { flag=0; }
      }
      else
      { jumpl(); }
      g=-g;
      if(y==14)
     { flag=0; }

      }
     break;
     case 5:
     if(y<14)
      {y++; }
     if(y==14)
     { flag=0; }
     break;
     default :
     break;
  }
 label:
}
void jump()
{ t=t+1;
  x=x+v1*t;

 y=y+v2*t-g*pow(t,2)/2;
 cout<<"x"<<x<<"v1"<<v1<<"v2"<<v2<<"y"<<y<<"t"<<t;
}
void jumpl()
{ t=t+1;
  x=x-v1*t;

 y=y+v2*t-g*pow(t,2)/2;
 cout<<"x"<<x<<"v1"<<v1<<"v2"<<v2<<"y"<<y<<"t"<<t;
}
