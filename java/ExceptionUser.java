

class MyException extends Exception
{     MyException(String msg)
      {   super(msg);
      }
}
class ExceptionUser
{ public static void main(String args[])
  {     int i=5;
        try
        {  if(i<10)
            {    throw new MyException("5 is less than 10");      }
         }
        catch(MyException e)
       { System.out.println(e);        }
 }
}      