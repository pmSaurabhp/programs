#include<conio.h>
#include<iostream.h>

#include<stdlib.h>
			// rand()
#include<stdio.h>
#include<string.h>
void draw();
void setup();
void move();
void direct();
void direct2();

int height=23,width=60,gameover=0;
int x,y,fruitx,fruity,flag=0;
int tailx[100],taily[100];
int counttail=0;
int x2,y2,fruitx2,fruity2,flag2=0;
int tailx2[100],taily2[100];
int counttail2=0;

void main()
{ clrscr();
 int i,j;
 setup();

while(gameover==0)
{ system("cls");
  draw();
  move();
  direct();
  direct2();
  for(i=0;i<800;i++)
   {for(j=0;j<1000;j++)
     {}
   }
 }

 getch();
 clrscr();
 if(gameover>0)
{
  cout<<" G A M E O V E R   ";

   if(gameover==2)
     cout<<"Player 1 Wins ";
   if(gameover==1)
     cout<<"Player 2 Wins ";


      }
   getch();

}
void draw()
{ int i,j,k;
 for(i=0;i<23;i++)
  { for(j=0;j<60;j++)
    { if(i==0||i==height-1||j==0||j==width-1)
       {  cout<<"*";   }                    // boundry
       else
       {
	if(i==y&&j==x||i==y2&&j==x2)
	{
	if(i==y&&j==x)
	  {  cout<<'*';  }                // snake 1
	if(i==y2&&j==x2)
	  { cout<<'+'; }                  // snake 2
	}
	else
	{
	if(i==fruity&&j==fruitx)
	{ if((counttail2+counttail)%4==0)
	  { cout<<'O';  }
	  else
	  { cout<<'F';  }

	}
	  else
	  {   int c=0;
	   for(k=0;k<counttail;k++)
		{ if(i==taily[k]&&j==tailx[k])
		  {   cout<<'o';
		     c=1;
		   }
		}
	  for(k=0;k<counttail2;k++)
	  { if(i==taily2[k]&&j==tailx2[k])
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
}

void setup()
{ x=(width)/2;
  y=(height)/2;
  label1:
  fruitx=rand()%60;
  if(fruitx==0||fruitx==59)
   goto label1;
   label2:
   fruity=rand()%23;
   if(fruity==0||fruity==22)
   goto label2;
  x2=(width+4)/2;
  y2=(height+4)/2;

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

    case 'j':
     if(flag2!=2)
     {  flag2=1;
     }
     break;

    case 'l':
     if(flag2!=1)
     {
       flag2=2;

      }
     break;

     case 'i':
      if(flag2!=4)
     {
       flag2=3;

      }
      break;

      case 'k':
      if(flag2!=3)
      {
       flag2=4;
       }
       break;

       case 'q':
	gameover=3;
	break;

       default :
	break;
    }
   }
}

void direct()
{   int i,k;
int prevx,prevy,prev2x,prev2y;
 prevx=tailx[0];
 prevy=taily[0];
tailx[0]=x;
taily[0]=y;

 cout<<"Player1 Score = "<<counttail<<"  ";
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
    if(fruitx==0||fruitx==59)
    goto label3;
    label4:
    fruity=rand()%23;
    if(fruity==0||fruity==22)
    goto label4;

    if((counttail+counttail2)%4==0)
    { counttail++; }

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
void direct2()
{   int i,k;
int prevx,prevy,prev2x,prev2y;
 prevx=tailx2[0];
 prevy=taily2[0];
tailx2[0]=x2;
taily2[0]=y2;

 cout<<"Player2 Score = "<<counttail2;
 for(i=1;i<counttail2;i++)
{prev2x=tailx2[i];
 prev2y=taily2[i];
 tailx2[i]=prevx;
 taily2[i]=prevy;
 prevx=prev2x;
 prevy=prev2y;
 }

 if(x2==0||x2==width-1||y2==0||y2==height-1)
{ gameover=2; }
  if(x2==fruitx&&y2==fruity)
  { label32:
    fruitx=rand()%60;
    if(fruitx==0||fruitx==59)
    goto label32;
    label42:
    fruity=rand()%23;
    if(fruity==0||fruity==22)
    goto label42;

    if((counttail2+counttail)%4==0)
    { counttail2++; }
    counttail2++;
  }
  switch(flag2)
   { case 1:
       x2--;
      break;
     case 2:
       x2++;
       break;
      case 3:
       y2--;
       break;
      case 4:
       y2++;
       break;
    }
}
