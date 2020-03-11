import java.io.*;
class FileRead
{public static void main(String args[]) throws IOException
 { FileInputStream fin;
    fin=new FileInputStream("./FileIO.txt");
    int i=0;
    while(i!=-1)
    { i=fin.read();
      if(i!=-1)
     System.out.print((char)i);
    }
    fin.close();   /* saves the file */
 }
}