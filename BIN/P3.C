void main()
{
int i=0,n,sum=0;
clrscr();
while(i<5)
{
A:printf("Enter a positive no. : ");
scanf("%d",&n);
if(n<0)
{
printf("invalid\n");
goto A;
}
else
sum=sum+n;
i++;
}
printf("\nsum is %d",sum);
getch();
}