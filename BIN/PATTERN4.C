void main()
{
int c,r,n=4;
clrscr();
for(r=1;r<=n;r++)
{
for(c=n;c>=r;c--)
{
gotoxy(c,r);
printf("$");
delay(100);
}
}
getch();
}