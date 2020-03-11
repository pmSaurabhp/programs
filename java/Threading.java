class A extends Thread
{ public void run()
  {  for(int i=0;i<10;i++)
       {  System.out.println("hi");  
            try{Thread.sleep(100);} catch(Exception e){}  
       }             /* sleep() & join() throws InteruptedException */
  }                  /* when interupted by other Thread */
}
class B extends Thread
{ public void run()
  {  for(int i=0;i<10;i++)
       {  System.out.println("hello");  
            try{Thread.sleep(100);} catch(Exception e){}
       }
  }
}
class Threading
{ public static void main(String args[]) throws Exception
   {  A o1=new A();
      B o2=new B();
      
       o1.start();
       o2.start();
o1.join();
o2.join();
System.out.print("Main is also a thread so to complete other threads before printing this we use join");
   }
}