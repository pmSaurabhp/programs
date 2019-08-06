#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void draw();
void setup();
void move();
void direct();

int height=24,width=60,gameover=0;
int x,y,fruitx,fruity,flag=0;
int tailx[100],taily[100];
int counttail=0;
void main()
{ clrscr();
 int i,j;
 setup();

while(gameover!=1)
{ system("cls");
  draw();
  move();
  direct();
  for(i=0;i<1000;i++)
   {for(j=0;j<1000;j++)
     {}
     }
 }
 clrscr();
 if(gameover==1)
{
  cout<<" G A M E O V E R ";    }
  getch();

}
void draw()
{ int i,j,k;
 for(i=0;i<24;i++)
  { for(j=0;j<60;j++)
    { if(i==0||i==height-1||j==0||j==width-1)
       {  cout<<"*";   }
       else
       {   if(i==y&&j==x)
	  {  cout<<'*';  }
	else
	{ if(i==fruity&&j==fruitx)
	     { cout<<'F'; }
	  else
	  {  int c=0;
	   for(k=0;k<counttail;k++)
		{ if(i==taily[k]&&j==tailx[k])
		  {   cout<<'o';
		     c=1;
		   }
		}
		if(c==0)
		{ cout<<" "; }
	  }
	}
     }
    }
    cout<<endl;
  }
  if(x==fruitx&&y==fruity)
  {  if(flag==1)
      cout<<"great!!";

     if(flag==2)
       cout<<"good!!";
     if(flag==3)
       cout<<"Keep Going!!";
     if(flag==4)
       cout<<"superb!!";
       getch();
  }
}
void setup()
{ x=(width)/2;
  y=(height)/2;
  label1:
  fruitx=rand()%60;
  if(fruitx==0)
   goto label1;
   label2:
   fruity=rand()%24;
   if(fruity==0)
   goto label2;

}
void move()
{ while(kbhit())
 { switch(getch())
   { case 'a':
     if(flag!=2)
     {  flag=1;
     }
     break;
     case 'd':
     if(flag!=1)
     {
       flag=2;

      }
     break;
      case 'w':
      if(flag!=4)
     {
       flag=3;

      }
      break;
      case 's':
      if(flag!=3)
      {
       flag=4;
       }
       break;
       case 'q':
	gameover=1;
	break;

       default :
	break;
    }
   }
}
void direct()
{   int i;
int prevx,prevy,prev2x,prev2y;
 prevx=tailx[0];
 prevy=taily[0];
tailx[0]=x;
taily[0]=y;

 cout<<"Score = "<<counttail;
 for(i=1;i<counttail;i++)
{prev2x=tailx[i];
 prev2y=taily[i];
 tailx[i]=prevx;
 taily[i]=prevy;
 prevx=prev2x;
 prevy=prev2y;
 }

 if(x==0||x==width-1||y==0||y==height-1)
{ gameover=1; }
  if(x==fruitx&&y==fruity)
  { label3:
    fruitx=rand()%60;
    if(fruitx==0)
    goto label3;
    label4:
    fruity=rand()%24;
    if(fruity==0)
    goto label4;

    counttail++;
  }
  switch(flag)
   { case 1:
       x--;
      break;
     case 2:
       x++;
       break;
      case 3:
       y--;
       break;
      case 4:
       y++;
       break;
    }

}
