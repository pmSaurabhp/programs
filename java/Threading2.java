class Account
{  int bal;
 public Account(int bal)
 { this.bal=bal;   } 
 public void withdraw(int w) 
 {  
       bal=bal-w;    
 }
}
class Customer implements Runnable 
{ int amt;
private Account o1;
private String s;
public Customer(Account o1,String s,int amt)
{  this.o1=o1;
    this.s=s;
  this.amt=amt;
  }

public void run()
   {   synchronized(this)       /* object as argument  */ 
       {  if(o1.bal>amt)           /*  critical section    */  
           {  o1.withdraw(amt);          
           System.out.println(s+" Balance is "+o1.bal);         
           }
          else
             System.out.println("Insuficient funds");     
      }   
   }
}
class Threading2
{ public static void main(String args[])
   {  Account a1=new Account(1000);
       Customer c1=new Customer(a1,"sss",600),c2=new Customer(a1,"mmm",700);
      
  Thread t1=new Thread(c1);     
  Thread t2=new Thread(c2);      
      t1.start();
      t2.start();
System.out.println("Remove Synchronized and run again again");
  }
}