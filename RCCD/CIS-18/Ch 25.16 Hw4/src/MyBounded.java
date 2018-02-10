// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: MyBounded.java
// Abstract MyBounded class.

import java.awt.Color;

@SuppressWarnings("serial")
public abstract class MyBounded extends MyShape 
{
   private boolean filled; // controls whether shape is filled or not
   
   // no-argument constructor
   public MyBounded()
   {
      super();
      setFilled( false ); // set filled to false
   } // end no-argument MyBounded constructor

   // five-argument constructor
   public MyBounded( int x1, int y1, int x2, int y2, boolean f )
   {
      super( x1, y1, x2, y2 );
      setFilled( f ); // set filled field
   } // end five-argument MyBounded constructor
   
   // six-argument constructor
   public MyBounded( int x1, int y1, int x2, int y2, Color c, boolean f )
   {
      super( x1, y1, x2, y2, c );
      setFilled( f ); // set filled field
   } // end six-argument MyBounded constructor

   // set parameters
   public final void setAll( int x1, int y1, int x2, int y2, Color c, 
      boolean f )
   {
      super.setAll( x1, y1, x2, y2, c );
      setFilled( f ); // set filled field
   } // end method setAll
   
   // set filled
   public void setFilled( boolean f ) 
   {
      filled = f; // set filled
   } // end method setFilled
   
   // get filled
   public boolean getFilled() 
   { 
      return filled; // return filled
   } // end method getFilled

   // get upper-left x
   public int getUpperLeftX()
   {
      return Math.min( getX1(), getX2() );
   } // end method getUpperLeftX

   // get upper-left y
   public int getUpperLeftY()
   {
      return Math.min( getY1(), getY2() );
   } // end method getUpperLeftY

   // get width
   public int getWidth()
   {
      return Math.abs( getX1() - getX2() );
   } // end method getWidth

   // get height
   public int getHeight()
   {
      return Math.abs( getY1() - getY2() );
   } // end method getHeight
} // end class MyBounded
