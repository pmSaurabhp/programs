import java.awt.*;

class MyFrame 
{ public static void main(String args[])
 {  Frame f=new Frame();
     f.setTitle("Sets Frame Title");
     f.setSize(300,300);
     f.setVisible(true);
 f.setLayout(null);
Button b=new Button("sum");
b.setBounds(30,50,80,30);
f.add(b);
 }
}