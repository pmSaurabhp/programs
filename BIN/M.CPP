#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
void frame();
void jump();

void move();
void direct();
			 // i=row=y
int i=0,j=0,q=0,flag=0,x=4,y=14;
float t=0,g=1,vx=1,vy=1;
void main()
{ clrscr();
  while(q==0)
 { t=t+1;
  system("cls");
  frame();

  move();
  direct();
  cout<<x<<y;
  }

 getch();
}
void frame()
{ for(i=0;i<24;i++)
  {for(j=0;j<75;j++)
   { if(i==15)
      {cout<<"*";
      }
      else
      {cout<<" ";  }
     if(i==y&&j==x)
     {cout<<"#"; }
    }
    cout<<endl;
   }

}
void move()
{ while(kbhit())
 { switch(getch())
   {
     case 'a':
       x--;
       flag=1;
      break;
     case 'd':
       x++;
       flag=2;
       break;
      case 'w':
       flag=3;
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
{     switch(flag)
  {
    case 3:
    if(y!=10)
      { y--;
       cout<<y;
       }
      else
      { flag=4; }
     break;

     case 4:
      if(y!=14)
      { y++; }
     break;

     default :
     break;
  }
}
