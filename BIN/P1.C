void main()
{
int c,r;
clrscr();
for(c=1;c<=9;c++)
{
for(r=1;r<25;r++)
{
gotoxy(c,r);
printf("%d",c);
delay(10);
gotoxy(c,r);
printf(" ");
}
gotoxy(c,r);
printf("%d",c);
}
getch();
}