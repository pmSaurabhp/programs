import java.awt.event.*;
import java.applet.Applet;

/*<appletcode="MouseEvent1"width="500"height="500"></applet>*/
public class MouseEvent1 Extends Applet implements MouseListener
{  String msg=" ";
    int x=0,y=0,w=0,h=0;
    public void init()
    {  addMouseListener(this);
        }
  public void mouseClicked(MouseEvent me)
{ x=me.getX();
   y=me.gety();
repaint();
}
public void mouseEntered(){}

public void mouseExited(){}

public void mousePressed(){}

public void mouseReleased(){}
}
    
