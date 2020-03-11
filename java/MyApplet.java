import java.applet.*;
import java.awt.*;

/*<applet code = "MyApplet" width = 200 height = 200>
</applet>*/

public class MyApplet extends Applet
{
	public void init()
	{
		setBackground(Color.red);
	}

	public void start(){}

	public void paint(Graphics g)
	{
		g.drawString("WelCome",10,20);
	}
}