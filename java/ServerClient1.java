import java.io.*;
import java.net.*;

class ServerClient1
{ public static void main(String args[]) throws Exception
  {   
 Socket s=new Socket("localhost",6666);

DataOutputStream dos=new DataOutputStream(s.getOutputStream); 

dos.writeUTF("hello Server");
 
}
}
     