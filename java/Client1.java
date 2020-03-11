import java.io.*;
import java.net.*;

class Server1
{ public static void main(String args[]) throws Exception
  { ServerSocket ss=new ServerSocket(6666);
       System.out.print("Waiting for any client");    
 Socket s=ss.accept();
System.out.print("Connection with client made");
DataInputStream dis=new DataInputStream(s.getInputStream); 
String str=(String)dis.readUTF();
 System.out.print(str);
}
}
     