import java.util.Scanner;
class Rectangle
{ private  int l,b;
   void input()
  { Scanner sc=new Scanner(System.in);	
     System.out.print("Enter Length = ");
     l=sc.nextInt();
     System.out.print("Breadth = ");
     b=sc.nextInt();
   }
  void area()
  { int a;
    a=l*b;
    System.out.print("Area = "+a);
  }
}
class Area
{  static{System.out.print("Helelelle"); }
 public static void  main(String args[])
  {  Rectangle o1=new Rectangle();
      o1.input();
      o1.area();

  }
}