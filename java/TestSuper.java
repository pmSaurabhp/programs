class A
{ public 
      int z;
 A()           
  {  System.out.println("class A") ;   }
void fun1()
{ System.out.println("fun1 of A");
}
}
class B extends A
{ public 
  int z;  
B()
  { 
    // super(); is automatically written here
  System.out.println("class B");  
  }
void fun1()
{ 
 System.out.println("fun1 of B");
 super.fun1();  // calls method of parent class
 super.z=5;
z=100;
 System.out.println("super z = "+super.z);
 System.out.println("sub class  z = "+z);
}
}
class TestSuper
{ public static void main(String args[])
   { B obj=new B();  
       obj.fun1();
  }
}