// Adnar Lozano
// CIS-18B: Java
// R.Casolaro
// 04/03/2014

// Fig. 25.17: BoxLayoutDemo.java
// Demonstrating BoxLayout.
import javax.swing.JFrame;

public class BoxLayoutDemo
{
   public static void main( String[] args )
   { 
      BoxLayoutFrame boxLayoutFrame = new BoxLayoutFrame();  
      boxLayoutFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      boxLayoutFrame.setSize( 400, 220 ); // set frame size
      boxLayoutFrame.setVisible( true ); // display frame
   } // end main
} // end class BoxLayoutDemo
