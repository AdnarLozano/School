// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: MyLine.java
// MyLine class.

import java.awt.Color;
import java.awt.Graphics;

@SuppressWarnings("serial")
public class MyLine extends MyShape 
{
   // no-argument constructor
   public MyLine()
   {
      super();
   } // end MyLine no-argument constructor

   // four-argument constructor
   public MyLine( int x1, int y1, int x2, int y2 )
   {
      super( x1, y1, x2, y2 );
   } // end MyLine four-argument constructor
   
   // five-argument constructor
   public MyLine( int x1, int y1, int x2, int y2, Color c )
   {
      super( x1, y1, x2, y2, c );
   } // end MyLine five-argument constructor

   // draw line
   public void draw( Graphics g )
   {
      g.setColor( getColor() );
      g.drawLine( getX1(), getY1(), getX2(), getY2() );
   } // end method draw
   
   public String toString() 
   { 
      return "Line"; 
   } // end method toString
} // end class MyLine
