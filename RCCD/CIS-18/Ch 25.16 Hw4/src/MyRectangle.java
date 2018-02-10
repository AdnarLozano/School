// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: MyRectangle.java
// MyRectangle class.

import java.awt.Graphics;
import java.awt.Color;

@SuppressWarnings("serial")
public class MyRectangle extends MyBounded 
{
   // no-argument constructor
   public MyRectangle()
   {
      super();
   } // end no-argument MyRectangle constructor

   // five-argument constructor
   public MyRectangle( int x1, int y1, int x2, int y2, boolean f )
   {
      super( x1, y1, x2, y2, f );
   } // end five-argument MyRectangle constructor
   
   // six-argument constructor
   public MyRectangle( int x1, int y1, int x2, int y2, Color c, 
      boolean f )
   {
      super( x1, y1, x2, y2, c, f );
   } // end six-argument MyRectangle constructor

   // draw rectangle
   public void draw( Graphics g )
   {
      g.setColor( getColor() );

      if ( getFilled() )
         g.fillRect( getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight() );
      else
         g.drawRect( getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight() );
   } // end method draw
   
   public String toString() 
   { 
      return "Rectangle"; 
   } // end method toString
} // end class MyRectangle
