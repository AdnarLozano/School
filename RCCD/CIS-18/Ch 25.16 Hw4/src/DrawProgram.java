// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: DrawProgram.java
// This class creates the desktop, manages menu items and creates frames.

import javax.swing.JFrame;

public class DrawProgram
{
   public static void main( String args[] )
   { 
      DrawFrame drawFrame = new DrawFrame(); 
      drawFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      drawFrame.setSize( 900, 900 ); // set frame size
      drawFrame.setVisible( true ); // display frame
   } // end main
} // end class DrawProgram
