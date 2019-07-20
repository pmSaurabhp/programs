#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void main(int argc,char*argv[])
{ clrscr();
   int per,i,sum=0;
    if(argc!=4)
   { printf("you have forgot to type no.");
   exit(1);
   }
   printf("the percentage is:");
   for(i=1;i<argc;i++)
   { sum=sum+atoi(argv[i]);
   }
   per=sum/3;
   printf("%d",per);

getch();
}