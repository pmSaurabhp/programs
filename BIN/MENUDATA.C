#include<stdio.h>
#include<conio.h>
int size(int TOS);
int peek(int TOS,int A[]);
int isEmpty(int TOS);
int isFull(int TOS,int MAXSIZE);
int push(int TOS, int MAXSIZE,int A[]);
void pop(int TOS, int A[]);
void main()
{
int ch,i,TOS,MAXSIZE,A[50],s;
clrscr();
printf("Enter maxsize : ");
scanf("%d",&MAXSIZE);
printf("Enter number of elements : ");
scanf("%d",&TOS);
printf("Enter %d elements :\n",TOS);
for(i=0;i<TOS;i++)
scanf("%d",&A[i]);
printf("Enter any one choice :\n1.size()\n2.peek()\n3.isEmpty()\n4.isFull()\n5.push()\n6.pop()\n7.exit\n\n");
while(1)
{printf("enter a choice");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	s=size(TOS);
	printf("The size of stack is %d",s);
	break ;

	case 2:
	s=peek(TOS,A);
	printf("The required element is %d",s);
	break;

	case 3:
	s=isEmpty(TOS);
	if(s==1)
	printf("The stack is empty");
	else if(s==0)
	printf("The stack is not empty");
	break;

	case 4:
	s=isFull(TOS,MAXSIZE);
	if(s==1)
	printf("The stack is Full");
	else if(s==0)
	printf("The stack is not Full");
	break;

	case 5:
	TOS=push(TOS,MAXSIZE,A);
	printf("The final data is :\n");
	for(i=0;i<TOS;i++)
	printf("%d\n",A[i]);
	break;

	case 6:
	pop(TOS,A);
	printf("The final data is:\n");
	for(i=0;i<TOS-1;i++)
	printf("%d\n",A[i]);
	break;

	case 7:
	exit(0);

	default:
	printf("\nYou entered a wrong choice\n");
	break;
}
}
getch();
}

int size(int TOS)
{
    return TOS;
}

int peek(int TOS,int A[])
{
    return A[TOS-1];
}

int isEmpty(int TOS)
{
    if(TOS==0)
    return 1;
    else
    return 0;
}

int isFull(int TOS,int MAXSIZE)
{
    if(TOS==MAXSIZE)
    return 1;
    else
    return 0;
}

int push(int TOS,int MAXSIZE,int A[])
{
    int data;
    if(TOS==MAXSIZE)
    printf("Sorry!! The Stack is Full");
    else
    {
    printf("\n\nEnter new data : ");
    scanf("%d",&data);
    A[TOS]=data;
    ++TOS;
    }
    return TOS;
}

void pop(int TOS,int A[])
{
    int data;
    if(TOS==-1)
     printf("Sorry!! Stack is empty");
    else
    {
    data=A[TOS-1];
    printf("\n\nData to delete is %d\n\n",data);
    }
}