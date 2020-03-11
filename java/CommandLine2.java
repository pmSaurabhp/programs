 
import java.lang.Integer;         /* java.lang.*; does not works */
public class CommandLine2
{ public static void main(String []arg)
   {  int i=0,s=0;   
      for(i=0;i<arg.length;i++)
        s=s+Integer.parseInt(arg[i]);   
System.out.println("Sum = "+s);    
 }
} 