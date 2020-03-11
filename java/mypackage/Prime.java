package mypackage;
import java.util.Scanner;
public class Prime
{ public void check()
  {  int n,c=0;
 System.out.print("Enter a number = "); 
Scanner sc=new Scanner(System.in);
   n=sc.nextInt();
 for(int i=1;i<=n;i++)
  { if(n%i==0)
     {  c++;  }     
  }
  if(c==2)
  { System.out.println("Prime Number "); } 
else
 {System.out.println("Not Prime Number ");  }
}
}