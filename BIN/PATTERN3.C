void main()
{
int c,r,n=4,s=n;
clrscr();
for(r=1;r<=n;r++)
{
for(c=1;c<=s;c++)
{
gotoxy(c,r);
printf("$");
delay(100);

}
s--;
}
getch();
}