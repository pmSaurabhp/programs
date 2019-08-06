#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{int data;
struct node *next;
};
void main()
{ int i,p,d;
 struct node *n,*start,*temp,*temp2,*newnode,*first,*second,*third;
  clrscr();

  printf("Enter no. in first,second,third");
  scanf("%d %d %d",&first->data,&second->data,&third->data);
  start=first;
  first->next=second;
  second->next=third;
  third->next=NULL;
  n=start;
  while(n!=NULL)
  {  printf("%d",n->data);
    n=n->next;
  }
       printf("Enter position and data of newnode");
    scanf("%d %d",&p,&newnode->data);

     temp=start;
     if(p==1)                         // inserion at first
      {newnode->next=start;
       start=newnode;
       }
    else                               // insertion at other position
    {
     for(i=1;i<=p-2;i++)            // reach at particular position
       { temp=temp->next;
       }
	newnode->next=temp->next;
	 temp->next=newnode;
   }

    n=start;
   while(n!=NULL)
   {printf("%d",n->data);
    n=n->next;
   }

   printf("Enter position to be deleted :");
   scanf("%d",&d);

   temp=start;
   if(d==1)                          //deletion of first
   { temp2=temp->next;
   temp->next=NULL;
     start=temp2;
     free(temp);
   }
   else                               //deletion of other position
   {
       for(i=1;i<=d-2;i++)
	{ temp=temp->next;
	 }

       temp2=temp->next;
       temp->next=temp2->next;
       temp2->next=NULL;
       free(temp2);
   }
  n=start;
  while(n!=NULL)
  { printf("%d",n->data);
    n=n->next;
  }

  getch();
  }
