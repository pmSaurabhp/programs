#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<iostream.h>
void main()
{ clrscr();
int gdrive=0,gmode;
initgraph(&gdrive,&gmode,"c:\\tc\\bgi");
float i,j,x,y;
for(i=0;i<20;i++)
{for(j=0;j<20;j++)
 {      x=25-pow(j,2);
	if(x<0)
	{x=0; }
	 y=25-pow(i,2);
	if(y<0)
	{y=0; }

     if(j==pow(y,1.0/2.0)+10&&i==pow(x,1.0/2.0)+10)
	{ putpixel(i,j,WHITE);
	cout<<i<<endl;
	cout<<j<<endl;
	}

 }
}
getch();
closegraph();
}