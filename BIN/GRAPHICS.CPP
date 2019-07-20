#include<conio.h>
#include<graphics.h>
void main()
{ clrscr();
int gdrive=0,gmode;
initgraph(&gdrive,&gmode,"c:\\tc\\bgi");
circle(100,100,40);
circle(400,100,40);
rectangle(235,250,265,275);
line(150,400,350,400);
circle(250,250,200);
circle(150,170,20);
circle(350,170,20);
getch();
closegraph();
}