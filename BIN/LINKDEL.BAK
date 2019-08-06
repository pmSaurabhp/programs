#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{int data;
struct node *next;
};
void main()
{ int i,p,d;
 struct node *n,*start,*temp,*temp2,*t,*newnode,*first,*second,*third,*fourth;
  clrscr();

  printf("Enter no. in first,second,third");
  scanf("%d %d %d %d",&first->data,&second->data,&third->data,&fourth->data);
  start=first;
  first->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=NULL;
  n=start;
  while(n!=NULL)
  {  printf("%d",n->data);
    n=n->next;
  }



   printf("Enter position to be deleted :");
   scanf("%d",&d);
   temp=start;


     if(d==1)
      { temp2=temp->next;
       temp->next=NULL;
       start=temp2;
       free(temp);
      }
   else
   {
     for(i=1;i<=d-2;i++)
     {  temp=temp->next;
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
