// Adnar Lozano
// CIS-18B: Java
// R.Casolaro
// 04/03/2014

// Fig. 25.14: MenuTest.java
// Testing MenuFrame.
import javax.swing.JFrame;

public class MenuTest
{
   public static void main( String[] args )
   { 
      MenuFrame menuFrame = new MenuFrame(); // create MenuFrame 
      menuFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      menuFrame.setSize( 500, 200 ); // set frame size
      menuFrame.setVisible( true ); // display frame
   } // end main
} // end class MenuTest
