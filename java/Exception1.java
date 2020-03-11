class Exception1
{
	public static void main(String args[])
 	 {   int i,j,k=0;
        int a[]=new int[4]; 
         i=6;
        j=0;
       try
     {
        k=i/j;
       System.out.println("Result = "+k);   
 }
 catch(ArithmeticException d)
  {  System.out.println(d);  }

try{      for(int c=0;c<=4;c++) 
       {  a[c]=c;   }       
       
     }

    catch(ArrayIndexOutOfBoundsException b)
  {  System.out.println("Size of array exceeded ");  }
  finally   
 { System.out.println("bye");            }
   
     
}}


