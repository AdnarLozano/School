// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: DrawPanel3.java
// This panel draws the shapes.

import java.awt.Graphics;
import java.awt.Color;

import javax.swing.JPanel;

@SuppressWarnings("serial")
public class DrawPanel3 extends JPanel
{
   private MyShape[] shape; // array of MyShapes
   private int count; // number of shapes
   private boolean done; // whether reached maximum number of shapes
   private boolean fill; // whether to create filled or unfilled shapes
   private int red; // amount of red in color
   private int green; // amount of green in color
   private int blue; // amount of blue in color
   private String type; // type of shape to draw

   // constructor initializes the drawing panel
   public DrawPanel3()
   {
      fill = false; // initialize with unfilled shapes
      shape = new MyShape[ 20 ]; // create array to hold shapes
      count = 0; // initialize count to 0
      red = blue = green = 0; // initialize color to black
      type = "Rectangle"; // set type to rectangle
      done = false; // not done drawing yet
   } // end DrawPanel3 constructor

   // draw colored shapes
   public void paintComponent( Graphics g )
   {
      super.paintComponent( g );

      for( int i = 0; i < count; i++ )
         shape[ i ].draw( g ); // draw shape from array
   } // end method paintComponent

   // create a shape at the specified coordinates
   public void createShape( int x, int y )
   {
      if ( !isDone() )
      {
         Color color = new Color( red, green, blue ); // create new color

         // determine which shape needs to be created
         if ( type.equals( "Rectangle" ) )
            shape[ count ] = new MyRectangle( x, y, x, y, color, fill );
         else if ( type.equals( "Line" ) )
            shape[ count ] = new MyLine( x, y, x, y, color );
         else
            shape[ count ] = new MyOval( x, y, x, y, color, fill );

         count++; // increment the count
         repaint(); // repaint panel
      } // end if
   } // end method createShape

   public void finishShape()
   {
      if ( count == shape.length )
         done = true; // reached maximum number of shapes
   } // end method finishShape

   private boolean isDone()
   {
      return done; // return whether done drawing
   } // end method isDone

   // resize the current shape
   public void resizeShape( int x, int y )
   {
      if ( !isDone() )
      {
         shape[ count - 1 ].setX2( x ); // change the X2 value
         shape[ count - 1 ].setY2( y ); // change the Y2 value
         repaint(); // repaint panel
      } // end if
   } // end method resizeShape

   // set the fill property of the shape
   public void setFill( boolean f )
   {
      fill = f; // set fill value
   } // end method setFill

   // change the shape that is drawn
   public void setShape( String shapeType )
   {
      type = shapeType; // set shape type
   } // end method setShape

   // set red
   public void setRed( int r )
   {
      red = r; // set red value
   } // end method setRed

   // set green
   public void setGreen( int g )
   {
      green = g; // set green value
   } // end method setGreen

   // set blue
   public void setBlue( int b )
   {
      blue = b; // set blue value
   } // end method setBlue
} // end class DrawPanel3
