import java.awt.event.*;
import java.applet.*;
import java.awt.*;
/*<appletcode="MouseEvent1"width=500 height=500></applet>*/
public class MouseEvent1 extends Applet implements MouseListener
{  String msg=" ";
    int x=0,y=0,w=0,h=0;
    public void init()
    {  addMouseListener(this);
        }
  public void mouseClicked(MouseEvent1 me)
{ x=me.getX();
   y=me.getY();
repaint();
}

public void mouseExited(MouseEvent1 me)
{ System.out.print("fdhskjfh");
 x=me.getX();
   y=me.getY();
repaint();
}
public void mouseEntered(MouseEvent1 me){}
public void mousePressed(MouseEvent1 me){}
public void mouseReleased(MouseEvent1 me){}
 public void paint(Graphics g)
 { 
   g.fillRect(x,y,w,h);
  }
}
    
