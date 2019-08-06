#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node             // reverse
{int data;
struct node *next;
};
void main()
{ int i,p;
 struct node *n,*start,*temp,*prev,*current,*newnode,*first,*second,*third;
  clrscr();

  printf("Enter no. in first,second,third");
  scanf("%d %d %d",&first->data,&second->data,&third->data);
  start=first;
  first->next=second;
  second->next=third;
  third->next=NULL;
  prev=NULL;
  n=start;
  while(n!=NULL)
  {  printf("%d",n->data);
    n=n->next;
  }



     current=start;
     temp=start;
    while(temp!=NULL)
    { temp=temp->next;
      current->next=prev;
      prev=current;
      current=temp;
    }
    start=prev;
    printf("\n");

    n=start;
   while(n!=NULL)
   {printf("%d",n->data);
    n=n->next;
   }
  getch();
  }
