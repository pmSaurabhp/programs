import java.util.Scanner;
import java.lang.Math;
class Box
{private int s1,s2,s3;
void input(int x,int y)
{ 
s1=x;s2=y;
int a;
a=s1*s2;
System.out.print("Area of Rectangle ="+a);
}
void input(int x,int y,int z)
{ 
s1=x;s2=y;s3=z;
double a,s;
s=(s1+s2+s3)/2;
a=Math.sqrt((s-s1)*(s-s2)*(s-s3));
System.out.print("Area of Triangle ="+a);
}
}
class Quadrilateral
{ public static void main(String args[])
 { Box o1=new Box();
    Box o2=new Box();
int x,y,z;
Scanner sc=new Scanner(System.in);
x=sc.nextInt();
y=sc.nextInt();
o1.input(x,y);

x=sc.nextInt();
y=sc.nextInt();
z=sc.nextInt();
o2.input(x,y,z);

}
}  