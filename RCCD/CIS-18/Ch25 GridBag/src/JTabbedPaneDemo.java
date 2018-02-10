// Adnar Lozano
// CIS-18B: Java
// R.Casolaro
// 04/03/2014

// Fig. 25.22: JTabbedPaneDemo.java
// Demonstrating JTabbedPane.
import javax.swing.JFrame;

public class JTabbedPaneDemo
{
   public static void main( String[] args )
   { 
      JTabbedPaneFrame tabbedPaneFrame = new JTabbedPaneFrame();  
      tabbedPaneFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      tabbedPaneFrame.setSize( 250, 200 ); // set frame size
      tabbedPaneFrame.setVisible( true ); // display frame
   } // end main
} // end class JTabbedPaneDemo
