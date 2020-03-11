import java.util.Scanner;
class Interest
{public static void main(String a[])
  { float p,r,t,s;
    Scanner sc=new Scanner(System.in);
  System.out.print("Enter p = ");
    p=sc.nextFloat();
  System.out.print("Enter r = ");
    r=sc.nextFloat();
  System.out.print("Enter t = ");
    t=sc.nextFloat();
     s=p*r*t/100;

System.out.print("Hello world");
System.out.print("\n s= "+s);
  }
}