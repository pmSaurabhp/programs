import java.util.Scanner;
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
int a;
a=s1*s2*s3;
System.out.print("Area of Triangle ="+a);
}
}
class Quadrilateral
{ public static void main(String args[])
 { Box o1=new Box();
    Box o2=new Box();
 o1.input(10,20);
o2.input(3,4,5)
}
}  