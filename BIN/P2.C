void main()
{
int n=1235,x,r=0;
while(n!=0)
{
x=n%10;
r=x*10+r;
n=n/10;
}
printf("%d",r);
getch();
}