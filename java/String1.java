class String1
{ public static void main(String args[])
  {  String s1=new String("Hello");
      System.out.println(s1);
System.out.println(s1.charAt(1));/* s1[1] error not array */
s1=s1.concat("World");

System.out.println(s1);
s1="sks";
System.out.print(s1);
}
}