import java.io.*;
class FileWrite2
{public static void main(String args[]) throws IOException
 { FileWriter fw=new FileWriter("./FileIO.txt",true);
   BufferedWriter bw=new BufferedWriter(fw);
  bw.write("BufferedWriter writes a many characters as size of Buffer at once");
    bw.close();     
 }
}