// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16:  MyShape.java
// Abstract MyShape class.

import java.awt.Color;
import java.awt.Graphics;
import java.io.Serializable;

@SuppressWarnings("serial")
public abstract class MyShape implements Serializable 
{
   private int x1; // first x-coordinate
   private int y1; // first y-coordinate
   private int x2; // second x-coordinate
   private int y2; // second y-coordinate
   private Color color; // color

   // no-argument constructor
   public MyShape()
   {
      this( 0, 0, 0, 0 );
   } // end no-argument MyShape constructor

   // five-argument constructor
   public MyShape( int x1, int y1, int x2, int y2 )
   {
      this( x1 ,y1, x2, y2, Color.BLACK );
   } // end five-argument MyShape constructor
   
   // six-argument constructor
   public MyShape( int x1, int y1, int x2, int y2, Color c )
   {
      setAll( x1, y1, x2, y2, c );
   } // end six-argument MyShape constructor
   
   // change all the properties at once after the shape has been created
   public final void setAll( int x1, int y1, int x2, int y2, Color c )
   {
      setX1( x1 );
      setY1( y1 );
      setX2( x2 );
      setY2( y2 );
      setColor( c );
   } // end method setAll

   public final void setX1( int x ) 
   { 
      x1 = x; 
   } // end method setX1

   public final int getX1() 
   { 
      return x1; 
   } // end method getX1

   public final void setY1( int y ) 
   { 
      y1 = y; 
   } // end method setY1

   public final int getY1() 
   { 
      return y1; 
   } // end method getY1

   public final void setX2( int x ) 
   { 
      x2 = x; 
   } // end method setX2

   public final int getX2() 
   { 
      return x2; 
   } // end method getX2

   public final void setY2( int y ) 
   { 
      y2 = y; 
   } // end method setY2

   public final int getY2() 
   { 
      return y2; 
   } // end method getY2

   public void setColor( Color c ) 
   { 
      color = c; 
   } // end method setColor

   public Color getColor()
   { 
      return color; 
   } // end method getColor

   public abstract void draw( Graphics g );   
} // end class MyShape
