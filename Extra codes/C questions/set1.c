# include <stdio.h>

int main()
{
  char str[10],string[10];
int a=scanf("%s",&str);  //  scanf returns number of inputs    ,  scanf stops after whitespace,next line , eof
                         //  printf("%d",scanf("%d %d",&a,&b))  returns 2
int b=gets(string);      // gets stops after next line , eof
int c=getchar();         // gets takes one character only
printf("%d \n",a);
printf("%d \n",b);
printf("%c",c);     // getchar returns input character
                    // getchar also removes next character from input buffer
return 0;
}
