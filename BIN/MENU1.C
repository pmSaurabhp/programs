#include<stdio.h>
#include<conio.h>
#define maxsize 5
void size();
void peek();
void isEmpty();
void isFull();
void push();
void pull();
int s[5],TOS=-1;
void main()
{ int i,choice;
clrscr();

printf("Maxsize is 5");
printf("\n 1)size\n2)peek\n3)isEmpty\n4)isFull\n5)push\n6)pop\n7)exit\n \n ");
while(1)
{ printf("select a operation");
scanf("%d",&choice);
 switch(choice)
 {case 1:
   size();
   break;
  case 2:
  peek();
  break;
  case 3:
   isEmpty();
  break;
  case 4:
   isFull();
  break;
  case 5:
   push();

   break;
  case 6:
   pull();
   break;
   case 7:
    exit(0);
   default :
    printf("you are mad");
    break;
   }
getch();
}
}

void size()
{ printf(" size of stack is %d ",TOS+1);
    }
void peek()
{printf("top most element is %d",s[TOS]);
}
void isEmpty()
{ if(TOS==-1)
   printf("true");
 else
 printf("false");
 }
 void isFull()
 { if(TOS==maxsize-1 )
    {printf("true");}
    else
     {printf("false");}
  }
  void push()
{int b,i;
  if(TOS==maxsize-1)
   {printf("sorry stack is full");
    }
  else
 {printf("enter the element to be inserted");
  scanf("%d",&b);
  TOS=TOS+1;
  s[TOS]=b;
  }
  for(i=0;i<=TOS;i++)
   { printf("%d",s[i]);
   }
}
 void pull()
 {  int d,i;
 if(TOS==-1)
    { printf("sorry stack is empty");
    }
   else
    {   d=s[TOS];
      TOS=TOS-1;
    }
   for(i=0;i<=TOS;i++)
   { printf("%d",s[i]);
   }
 }