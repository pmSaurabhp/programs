     #include<conio.h>
     #include<stdio.h>
     #include<string.h>
     void main()
     { clrscr();
     int n,b;
     char a[]={'g','o','o','d'};
     printf("enter position to be changed and element to be inserted");
     scanf("%d %c",&n,&b);
     if(n<4)
     {a[n]=b;
     printf("%s",a);
     }
     else
     {printf("n must be <4");
     }
     getch();
     }
