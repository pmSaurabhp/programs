#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
void frame();
void jump();
void jumpl();
void move();
void direct();
void gravity();
			 // i=row=y
int i=0,j=0,q=0,flag=0,flagp=0,x=4,y=14,t=1,g=1,v1=1,v2=1;
int xb=20,yb=10,xt=60,yt=14,xt2=100,yt2=14;
void main()
{ clrscr();
  while(q==0)
 {
  system("cls");

  frame();
  move();
  direct();
  gravity();

   }

 getch();
}
void frame()
{
 if(x<31)
{ for(i=0;i<24;i++)
  {for(j=0;j<70;j++)
   {

     if(i==y&&j==x)
     {cout<<"A"; }
      else if(i==y-1&&j==x)
      { cout<<"|"; }
      else if(i==y-2&&j==x)
      {cout<<"o"; }
      else if(i==y-1&&j==x-1)
      { cout<<"/"; }
      else if(i==y-1&&j==x+1)
      {cout<<"\\" ; }
      else if(i==yb&&j==xb)
      {cout<<"-"; }
      else if(i==yb&&j==xb+1)
      {cout<<"-"; }
      else if(i==yb&&j==xb+2)
      {cout<<"-"; }
      else if(i==yb&&j==xb+3)
      {cout<<"-"; }
      else if(i==yb&&j==xb+4)
      {cout<<"-"; }
      else if(i==yb&&j==xb+5)
      {cout<<"-"; }
      else if(i==yb&&j==xb+6)
      {cout<<"-"; }
      else if(i==yb&&j==xb+7)
      {cout<<"-"; }
      else if(i==yt&&j==xt)
      {   cout<<"|"; }

     else if(i==yt&&j==xt-1)
	{   cout<<" "; }
      else if(i==yt&&j==xt-2)
	{   cout<<"|"; }
	else if(i==yt-2&&j==xt-2)
	{ cout<<"_";}

      else if(i==yt-2&&j==xt-1)
	{ cout<<"_";}
       else if(i==yt-2&&j==xt)
	{ cout<<"_";}

	else if(i==yt-1&&j==xt-3)
	{ cout<<"[";}
	else if(i==yt-1&&j==xt+1)
	{ cout<<"]";}




     else if(i==15)
      { cout<<"*";   }
     else
     {cout<<" "; }

    }
    cout<<endl;
   }
 if(x==30)
  {xb=xb-1;
  xt=xt-1;
  xt2=xt2-1;
    x=x-1;
  }
  if(xt==0)
  { xt=70; }

}
else
{x=30; }
}
void move()
{
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
	  // collide with block and come down
	  if(x==xb||x==xb+1||x==xb+2||x==xb+3||x==xb+4||x==xb+5||x==xb+6)
	  { flag=5;
	  goto down;
	   }
	  else if(flagp==2)
	  { jump(); }
	  else
	  {jumpl(); }

	  cout<<y;
      }
    else
    { flag=4; }

     break;

     case 4:
     down:
      // stand on block
      if(y==yb-1&&(x==xb||x==xb+1||x==xb+2||x==xb+3||x==xb+4||x==xb+5||x==xb+6))
	{ flag=0;
	  goto label;
	 }

      if(y<14)
      { g=-g;
	t=0;
	if(flagp==2)
	{ jump();
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

void gravity()
{ // come down from block

  if((x<=xb-1||x>=xb+8)&&flag!=3&&flag!=4&&y!=14)
      { flag=5;}
}

