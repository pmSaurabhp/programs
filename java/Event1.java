import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import java.lang.Integer;

/* <applet code="Event1" width="400" height="400"></applet>  */
public class Event1 extends Applet implements ActionListener
{      Label l1,l2,l3;
       TextField t1,t2;
        Button b1;
  
      public void init()
      { l1=new Label("a =");
         l2=new Label("b =");
         l3=new Label();
         TextField f1=new TextField();
         TextField f2=new TextField();
          Button b1=new Button("Add");
          add(l1);
          add(l2);   add(f1);   add(f2);   add(b1);
add(l3); 
          b1.addActionListener(this); 

        }
     
      public void actionPerformed(ActionEvent e)
        { int x,y,s;
           x=Integer.parseInt(t1.getText());
           y=Integer.parseInt(t2.getText());
          s=x+y;
           l3.setText("sum is"+s);
        }
    
}