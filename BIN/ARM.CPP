//to find armstrong numbers between 1 and 500
#include<iostream.h>
#include<math.h>
#include<conio.h>
void main()
{
int num,digit,temp,arm;
for(num=1;num<=500;num++)
{
temp=num; arm=0;
while(temp!=0)
{
 digit=temp%10;
 arm=arm+pow(digit,3);
 temp=temp/10;
}
if(arm==num)
cout<<num<<"\n";
}
getch();
}