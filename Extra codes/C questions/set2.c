int getString()
{
int *str = "This strings address is stored in str";
return str;   // address of above string is returned
}

int getarray()
{
int *str = {9,2,3,4};
return str;   // address of above list is returned
}

int main()
{
printf("%s \n", getString());

int *ptr=getarray();
int i;
for(i=0;i<4;i++)
{ printf("%d ",ptr+i );
}
return 0;
}
