class A extends Thread
{  int s;   
  A(int s)
    { this.s=s;   }
  public void run()
  {  
    for(int i=0;i<5;i++) 
     {    
       try{ sleep(s); }  catch(Exception e){}
       System.out.println(getName());   
    } 
   
  }
}

class Threading4
{ public static void main(String args[])
   {  A o1=new A(1000);
      A o2=new A(2000);
      A o3=new A(3000);
o1.setName("Good Morning");
o2.setName("Hello");
o3.setName("Welcome");    

o1.setPriority(3); 
o2.setPriority(4); 
o3.setPriority(5); 
       o1.start();
       o2.start();
       o3.start();     
}
}