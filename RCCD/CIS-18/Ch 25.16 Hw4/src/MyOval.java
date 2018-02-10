// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: MyOval.java
// MyOval class.

import java.awt.Graphics;
import java.awt.Color;

@SuppressWarnings("serial")
public class MyOval extends MyBounded 
{
   // no-argument constructor
   public MyOval()
   {
      super();
   } // end no-argument MyOval constructor

   // five-argument constructor
   public MyOval( int x1, int y1, int x2, int y2, boolean f )
   {
      super( x1, y1, x2, y2, f );
   } // end five-argument MyOval constructor

   // six-argument constructor
   public MyOval( int x1, int y1, int x2, int y2, Color c, boolean f )
   {
      super( x1, y1, x2, y2, c, f );
   } // end six-argument MyOval constructor

   // draw oval
   public void draw( Graphics g )
   {
      g.setColor( getColor() );

      if ( getFilled() )
         g.fillOval( getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight() );
      else
         g.drawOval( getUpperLeftX(), getUpperLeftY(),
            getWidth(), getHeight() );
   } // end method draw
   
   public String toString() 
   { 
      return "Oval"; 
   } // end method toString
} // end class MyOval
