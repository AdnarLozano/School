// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: MyColorChooser4.java
// JPanel subclass

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

@SuppressWarnings("serial")
public class MyColorChooser4 extends JPanel 
{
   private JSlider redJSlider; // chooses red value
   private JSlider blueJSlider; // chooses blue value
   private JSlider greenJSlider; // chooses green value
   private JTextField redJTextField; // displays red value
   private JTextField blueJTextField; // displays blue value
   private JTextField greenJTextField; // displays green value
   private JLabel redJLabel; // prompts user for red input
   private JLabel blueJLabel; // prompts user for blue input
   private JLabel greenJLabel; // prompts user for green input
   private Color color; // color created from user's input to sliders

   // set up GUI
   public MyColorChooser4()
   {
      redJLabel = new JLabel( "Red:" ); // create red label
      redJSlider = new JSlider( SwingConstants.HORIZONTAL, 0, 255, 0 );
      redJTextField = new JTextField( "0", 4 ); // create textfield

      greenJLabel = new JLabel( "Green:" ); // create green label
      greenJSlider = new JSlider( SwingConstants.HORIZONTAL, 0, 255, 0 );
      greenJTextField = new JTextField( "0", 4 ); // create textfield

      blueJLabel = new JLabel( "Blue:" ); // create blue label
      blueJSlider = new JSlider( SwingConstants.HORIZONTAL, 0, 255, 0 );
      blueJTextField = new JTextField( "0", 4 ); // create textfield

      setLayout( new GridLayout( 3, 3 ) ); // set layout of frame

      add( redJLabel ); // add red label
      add( redJSlider ); // add red slider
      add( redJTextField ); // add red textfield
      add( greenJLabel ); // add green label
      add( greenJSlider ); // add green slider
      add( greenJTextField ); // add green textfield
      add( blueJLabel ); // add blue label
      add( blueJSlider ); // add blue slider
      add( blueJTextField ); // add blue textfield

      // add listeners to sliders
      redJSlider.addChangeListener( new ChangeHandler() );
      greenJSlider.addChangeListener( new ChangeHandler() );
      blueJSlider.addChangeListener( new ChangeHandler() );

      // add listeners to textfields
      redJTextField.addActionListener( new ActionHandler() );
      greenJTextField.addActionListener( new ActionHandler() );
      blueJTextField.addActionListener( new ActionHandler() );

      color = Color.BLACK; // initialize color to black (0, 0, 0)
   } // end MyColorChooser4 constructor

   // set slider and textfield values
   public void setColor( Color inputColor )
   {
      color = inputColor; // set color to input color

      redJSlider.setValue( inputColor.getRed() ); // set red value
      redJTextField.setText( String.valueOf( inputColor.getRed() ) );

      greenJSlider.setValue( inputColor.getGreen() ); // set green value
      greenJTextField.setText( String.valueOf( inputColor.getGreen() ) );

      blueJSlider.setValue( inputColor.getBlue() ); // set blue value
      blueJTextField.setText( String.valueOf( inputColor.getBlue() ) );
   } // end method setColor

   // get color
   public Color getColor()
   {
      return color; // return color
   } // end method getColor

   // get red slider
   public JSlider getRedJSlider()
   {
      return redJSlider; // return red slider
   } // end method getRedJSlider

   // get green slider
   public JSlider getGreenJSlider()
   {
      return greenJSlider; // return green slider
   } // end method getGreenJSlider

   // get blue slider
   public JSlider getBlueJSlider()
   {
      return blueJSlider; // return blue slider
   } // end method getBlueJSlider

   // get red textfield
   public JTextField getRedDisplay()
   {
      return redJTextField; // return red textfield
   } // end method getRedDisplay

   // get green textfield
   public JTextField getGreenDisplay()
   {
      return greenJTextField; // return green textfield
   } // end method getGreenDisplay

   // get blue textfield
   public JTextField getBlueDisplay()
   {
      return blueJTextField; // return blue textfield
   } // end method getBlueDisplay

   // inner class to handle slider events
   private class ChangeHandler implements ChangeListener 
   {
      // handle change in slider value
      public void stateChanged( ChangeEvent e )
      {
         int red = redJSlider.getValue(); // amount of red in color
         int green = greenJSlider.getValue(); // amount of green in color
         int blue = blueJSlider.getValue(); // amount of blue in color

         setColor( new Color( red, green, blue ) ); // create new Color
      } // end method stateChanged
   } // end private inner class ChangeHandler

   // inner class to handle action events
   private class ActionHandler implements ActionListener
   {
      // handle text field input
      public void actionPerformed( ActionEvent event )
      {
         int red = Integer.parseInt( redJTextField.getText() );
         int green = Integer.parseInt( greenJTextField.getText() );
         int blue = Integer.parseInt( blueJTextField.getText() );

         setColor( new Color( red, green, blue ) ); // create new Color
      } // end method actionPerformed
   } // end private inner class ActionHandler
} // end class MyColorChooser4
