class A implements Runnable
{ public void run()
  {  for(int i=0;i<10;i++)
       {  System.out.println("hi");  
           try{ Thread.sleep(100);} catch(Exception e){}
       }
  }
}
class B implements Runnable
{ public void run()
  {  for(int i=0;i<10;i++)
       {  System.out.println("hello");  
            try{ Thread.sleep(100);} catch(Exception e){}     
       }
  }
}
class Threading1
{ public static void main(String args[]) throws Exception
   {  A o1=new A();
      B o2=new B();
 
Thread t1=new Thread(o1);     
Thread t2=new Thread(o2); 
System.out.println("Priority : "+t1.getPriority());
System.out.println("Priority : "+t2.getPriority());  
/*  setPriority()  */
    
   t1.start();     /* Runnable does not have start function  it only has run()*/    t1.join();       /* waits for t1 to complete */
  
System.out.println("control comes to main thread");
t2.start();
t2.join();
System.out.println("Is t1 alive : "+t1.isAlive()); 
System.out.println("waits till t2 is not completed");
System.out.println(" sleep(1000) - for 1000 milli sec = 1 sec");
   }
}