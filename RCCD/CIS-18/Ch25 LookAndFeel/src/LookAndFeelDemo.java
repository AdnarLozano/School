// Adnar Lozano
// CIS-18B: Java
// R.Casolaro
// 04/03/2014

// Fig. 25.10: LookAndFeelDemo.java
// Changing the look-and-feel.
import javax.swing.JFrame;

public class LookAndFeelDemo 
{
   public static void main( String[] args )
   { 
      LookAndFeelFrame lookAndFeelFrame = new LookAndFeelFrame();  
      lookAndFeelFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      lookAndFeelFrame.setSize( 400, 220 ); // set frame size
      lookAndFeelFrame.setVisible( true ); // display frame
   } // end main
} // end class LookAndFeelDemo
