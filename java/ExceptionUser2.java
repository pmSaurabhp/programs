import java.io.IOException;
class NoMatchException extends Exception
{    public  NoMatchException(String msg)
      {   super(msg);
      }
}
class ExceptionUser2
{ public static void main(String args[])
  {     String s1=new String("India");
         String s2=new String("hello");
        try
        {  if(!s1.equals(s2))
            {    throw new NoMatchException("Not Equal");      }
         }
        catch(NoMatchException e)
       { System.out.println(e);        }
  }
}      