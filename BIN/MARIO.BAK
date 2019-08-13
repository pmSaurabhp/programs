#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>

int i=0,j=0,q=0,flag=0,flagp=0,x=4,y=14,t=1,g=1,v1=1,v2=1;
int xb=20,yb=10,xt=60,yt=14,xt2=110,yt2=14;
int xe=100,ye=14,a=1;

class Magic
{ public:
  int p,xp,yp;
  Magic()
{  p=0;xp=0;yp=0; }


 void power()
{     if(xp==0&&yp==0)
      {xp=x+2; yp=y;  }
      if(xp==xe)
      { p=0; xp=0; yp=0;
	xe=85;
      }
    else if(xp==79)
     {  p=0; xp=0; yp=0; }
     else
     { xp=xp+1; }


}

};
void frame(Magic &o1,Magic &o2,Magic &o3,Magic &o4);
void jump();
void jumpl();
void move(Magic &o1,Magic &o2,Magic &o3,Magic &o4);
void direct();
void gravity();
void bgmove();
void e1();
void enemy();

			 // i=row=y
void main()
{ clrscr();
  Magic o1,o2,o3,o4;

  while(q==0)
 {
  system("cls");

  frame(o1,o2,o3,o4);
  move(o1,o2,o3,o4);
  direct();
  gravity();
  enemy();
  if(flag!=3&&flag!=4)
  {  e1();   }
    bgmove();
    if(o1.p==1)
    { o1.power();  }
    if(o2.p==1)
    { o2.power();  }
    if(o3.p==1)
    { o3.power();  }
    if(o4.p==1)
    { o4.power();  }

  }
  if(q==1)
  {cout<<"++++++++++++++  GAMEOVER  +++++++++++++++";   }


 getch();
}
void frame(Magic &o1,Magic &o2,Magic &o3,Magic &o4)
{
 if(x<31)
{ for(i=0;i<24;i++)
  {for(j=0;j<79;j++)
   {

     if(i==y&&j==x)
     {cout<<"M";  }
      else if(i==y-1&&j==x)
      { cout<<"X"; }
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
      else if(i==yt&&j==xt||i==yt2&&j==xt2)
      {   cout<<"|"; }

     else if(i==yt&&j==xt-1||i==yt2&&j==xt2-1)
	{   cout<<" "; }
      else if(i==yt&&j==xt-2||i==yt2&&j==xt2-2)
	{   cout<<"|"; }
	else if(i==yt-2&&j==xt-2||i==yt2-2&&j==xt2-2)
	{ cout<<"_";}

      else if(i==yt-2&&j==xt-1||i==yt2-2&&j==xt2-1)
	{ cout<<"_";}
       else if(i==yt-2&&j==xt||i==yt2-2&&j==xt2)
	{ cout<<"_";}

	else if(i==yt-1&&j==xt-3||i==yt2-1&&j==xt2-3)
	{ cout<<"[";}
	else if(i==yt-1&&j==xt+1||i==yt2-1&&j==xt2+1)
	{ cout<<"]";}
     else if(i==15)
      { cout<<"*";   }
     else if(i==ye&&j==xe)
     {cout<<"@";  }
     else if(i==ye-1&&j==xe-1)
     {cout<<",";  }
     else if(i==ye-1&&j==xe+1)
     {cout<<",";  }
     else if(j==o1.xp&&i==o1.yp)
     {cout<<">"; }
      else if(j==o2.xp&&i==o2.yp)
     {cout<<"-"; }
      else if(j==o3.xp&&i==o3.yp)
     {cout<<"*"; }
      else if(j==o4.xp&&i==o4.yp)
     { if(o4.xp<0)
       { o4.xp=2; }
     cout<<"{"; }
     else
     {cout<<" "; }

    }
    cout<<endl;
   }

  if(xt==-20)
  { xt=85; }
  if(xt2==-20)
  { xt2=85; }

 }
else
 { x=30; }
}
void move(Magic &o1,Magic &o2,Magic &o3,Magic &o4)
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

      case 'p':
       cout<<" o1 "<<o1.xp<<" o2 "<<o2.xp<<" o3 "<<o3.xp<<" o4 "<<o4.xp;
       getch();
       break;
      case 'f':
	 if(o3.p==1)
       {
	  o4.p=1;
	}
	if(o2.p==1)
       {o3.p=1;
	}
       if(o1.p==1)
       {
	  o2.p=1;
	}
	  o1.p=1;
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
    { flag=4;
      t=1;
     }

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

	if(flagp==2)
	{ jump();

	}
	else
	{ jumpl(); }

       g=-g;
       if(y>=14)
       { y=14;
       t=1;
       flag=0; }

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
void jump()                          // x=4 y=14 t=1 g=1 v1=1 v2=1
{ t=t+1;
  x=x+v1*t;

 y=y+v2*t-g*pow(t,2)/2;
e1();
bgmove();
cout<<"x"<<x<<" y"<<y;


}
void jumpl()
{ t=t+1;
  x=x-v1*t;

 y=y+v2*t-g*pow(t,2)/2;
  e1();
  bgmove();
  cout<<"x"<<x<<" y"<<y;


}

void gravity()
{ // come down from block

  if((x<=xb-1||x>=xb+8)&&flag!=3&&flag!=4&&y!=14)
      { flag=5;}
}
void bgmove()
{ if(x==30)
  {xb=xb-1;
  xt=xt-1;
  xt2=xt2-1;
    x=x-1;
    if(a<0)
    {xe=xe+2*a;   }
  }
}
void e1()
{
    xe=xe-a;
    if(xe==-25)
    { xe=80;}
    if(xe==100)
    { a=-a;
    xe=80; }


}
void enemy()
{ if(x==xe&&y==ye)      // player touches enemy
   { q=1;}


  if(xe==xt||xe==xt2)
  { a=-a;
   }
 else if(xe==xt-1||xe==xt-2||xe==xt2-2||xe==xt2-1)
  {
    if(a>0)
    { xe=xe+2; }
    if(a<0)
    { xe=xe-2;}

    a=-a;
   }

}
