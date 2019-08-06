// doubly linklist
#include<stdio.h>
#include<conio.h>

struct node
{int data;
struct node *next;
struct node *prev;
};
void disp( struct node *start)
{  struct node *n;
n=start;
  while(n!=NULL)
  {  printf("%d",n->data);
    n=n->next;
  }
}
void main()
{ int i,p,d;
 struct node *n,*start,*temp,*newnode,*first,*second,*third;
  clrscr();

  printf("Enter no. in first,second,third");
  scanf("%d %d %d",&first->data,&second->data,&third->data);
  start=first;
  start->prev=NULL;
  first->next=second;
  second->prev=first;
  second->next=third;
  third->prev=second;
  third->next=NULL;

  disp(start);
    printf("Enter position and data of newnode");
    scanf("%d %d",&p,&newnode->data);
     temp=start;
     if(p==1)                         // insertion at first
      {newnode->next=start;
      newnode->prev=NULL;
      start->prev=newnode;
       start=newnode;
       }
    else
    { for(i=1;i<=p-1;i++)
       { temp=temp->next;
       }
	 newnode->next=temp;
	 newnode->prev=temp->prev;
	 temp->prev->next=newnode;
	 temp->prev=newnode;
    }

   disp(start);
   printf("Enter position to be deleted");
   scanf("%d",&d);
   temp=start;
   if(d==1)                               // delete 1st position
   { start=temp->next;
     temp->next->prev=NULL;
     temp->next=NULL;
   }
   else                                  // delete any position
   {   for(i=1;i<=d-1;i++)
     { temp=temp->next;
     }

     temp->prev->next=temp->next;
     temp->next->prev=temp->prev;
     temp->prev=NULL;
     temp->next=NULL;

   }

    disp(start);

    printf("\n print in reverse order \n");
    n=start;
    while(n->next!=NULL)
    { n=n->next;
    }
   while(n!=NULL)
   {printf("%d",n->data);
    n=n->prev;
   }
   printf("\n reverse a doubly linklist \n");
   n=start;
   while(n->next!=NULL)
   { n=n->next;
    }
    start=n;
    while(n!=NULL)
   {printf("%d",n->data);
    n=n->prev;
   }
  getch();
  }