class Emp
{ int eid;
  int salary;
static  String ceo;

static {
ceo="saurabh";
}

Emp()
{ eid=0;
   salary=0;
}
public void show()
{ System.out.println(eid+" : "+(salary)+" : "+(ceo));
}

}

class StaticTest
{ public static void main(String args[])
   {Emp mohan=new Emp();
       mohan.show();
 Emp sks=new Emp();
      sks.eid=4;
      sks.salary=300;
      sks.show();
    Emp shyam=new Emp();
     shyam.eid=5;
     shyam.salary=400;
     shyam.show();
}
}  