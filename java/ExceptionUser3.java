import java.io.IOException;

class LessThan extends Exception
{    public  LessThan(String msg)
      {   super(msg);
      }
}
class ExceptionUser3
{ public static void main(String args[])
  {    int i=0;   
      for(i=0;i<args.length;i++)
       {  System.out.println(args[i]);    }
       
        try
        {  if(args.length<3)
            {    throw new LessThan("Arguments less than 3");      }
         }
        catch(LessThan e)
       { System.out.println(e);        }
  }
}      