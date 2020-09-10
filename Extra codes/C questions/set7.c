int main()
{
char str[]= "geeks\nforgeeks";
char *ptr1, *ptr2;

ptr1 = &str[3];
ptr2 = str + 5;

printf("%c", ++*str - --*ptr1 + *ptr2 + 1);// ++*str means *str=*str+1;
printf("%s", str);

                //  for answer go below













//First print statement becomes
//printf(“%c”, ‘h’ – ‘j’ + ‘\n’ + 2)
          //          -2 + ‘\n’ + 2 = ‘\n’
//
//First print statements newline character. and next print statement prints “heejs\nforgeeks”.
return 0;
}
