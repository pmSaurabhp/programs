#include<dos.h>
void main()
{
int c,r,n=4;
clrscr();
for(r=1;r<=n;r++)
{
for(c=1;c<=2*r-1;c++)
{
gotoxy(n-r+c,r);
printf("$");

gotoxy(n-r+c,2*n-r);
printf("$");
delay(1000);
}
}
getch();
}