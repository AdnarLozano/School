// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: DrawInternalFrame.java
// This class creates a frame that allows the user to draw shapes.

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JInternalFrame;
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.InternalFrameAdapter;
import javax.swing.event.InternalFrameEvent;

@SuppressWarnings("serial")
public class DrawInternalFrame extends JInternalFrame
{
   private DrawPanel3 drawPanel; // drawing panel to create shapes
   @SuppressWarnings("rawtypes")
   private JComboBox chooseJComboBox; // selects which shape to draw
   private DrawFrame parent; // parent window; controls application
   private String name; // name of this window

   // set up GUI
   public DrawInternalFrame( String title, DrawFrame caller ) 
   {
      super( title, true, true, true, true ); // create internal frame
      parent = caller; // set parent
      name = title; // set name of window
      
      MyColorChooser4 colorChooser = new MyColorChooser4();

      // when the red slider is altered, update the shape
      final JSlider redJSlider = colorChooser.getRedJSlider();
      redJSlider.addChangeListener(
         new ChangeListener() // anonymous inner class
         { 
            // handle slider event
            public void stateChanged( ChangeEvent event )
            {
               drawPanel.setRed( redJSlider.getValue() );
            } // end method stateChanged
         } // end anonymous inner class
      ); // end call to addChangeListener

      // when the red textfield is altered, update the shape
      final JTextField redJTextField = colorChooser.getRedDisplay();
      redJTextField.addActionListener(
         new ActionListener() // anonymous inner class
         { 
            // handle textfield event
            public void actionPerformed( ActionEvent event )
            {
               drawPanel.setRed(
                  Integer.parseInt( redJTextField.getText() ) );
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener

      // when the green slider is altered, update the shape
      final JSlider greenJSlider = colorChooser.getGreenJSlider();
      greenJSlider.addChangeListener(
         new ChangeListener() // anonymous inner class
         { 
            // handle slider event
            public void stateChanged( ChangeEvent event )
            {
               drawPanel.setGreen( greenJSlider.getValue() );
            } // end method stateChanged
         } // end anonymous inner class
      ); // end call to addChangeListener

      // when the green textfield is altered, update the shape
      final JTextField greenJTextField = colorChooser.getGreenDisplay();
      greenJTextField.addActionListener(
         new ActionListener() // anonymous inner class
         { 
            // handle textfield event
            public void actionPerformed( ActionEvent event )
            {
               drawPanel.setGreen(
                  Integer.parseInt( greenJTextField.getText() ) );
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener

      // when the blue slider is altered, update the shape
      final JSlider blueJSlider = colorChooser.getBlueJSlider();
      blueJSlider.addChangeListener(
         new ChangeListener() // anonymous inner class
         { 
            // handle slider event
            public void stateChanged( ChangeEvent event )
            {
               drawPanel.setBlue( blueJSlider.getValue() );
            } // end method stateChanged
         } // end anonymous inner class
      ); // end call to addChangeListener

      // when the blue textfield is altered, update the shape
      final JTextField blueJTextField = colorChooser.getBlueDisplay();
      blueJTextField.addActionListener(
         new ActionListener() // anonymous inner class
         { 
            // handle textfield event
            public void actionPerformed( ActionEvent event )
            {
               drawPanel.setBlue(
                  Integer.parseInt( blueJTextField.getText() ) );
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener

      drawPanel = new DrawPanel3(); // create drawing panel
      drawPanel.addMouseListener(
         new MouseAdapter() // anonymous inner class
         { 
            // create the chosen shape
            public void mousePressed( MouseEvent event ) 
            {
                  drawPanel.createShape( event.getX(), event.getY() );
            } // end method mousePressed
            
            // finish creating the shape
            public void mouseReleased( MouseEvent event ) 
            {
                  drawPanel.finishShape();
            } // end method mouseReleased
         } // end anonymous inner class
      ); // end call to addMouseListener
      
      drawPanel.addMouseMotionListener(
         new MouseMotionAdapter() // anonymous inner class
         { 
            // resize the shape
            public void mouseDragged( MouseEvent event )
            {
                  drawPanel.resizeShape( event.getX(), event.getY() );
            } // end method mouseDragged
         } // end anonymous inner class
      ); // end call to addMouseMotionListener
      
      ShapePanel shapePanel = new ShapePanel(); // chooses fill, shape
      JCheckBox fill = shapePanel.getFill(); // get fill value
      fill.addItemListener(
         new ItemListener() // anonymous inner class
         { 
            // toggle the fill field in the drawing panel
            public void itemStateChanged( ItemEvent event )
            {
               if ( event.getStateChange() == ItemEvent.SELECTED )
                  drawPanel.setFill( true ); // set fill to true
               else
                  drawPanel.setFill( false ); // set fill to false
            } // end method itemStateChanged
         } // end anonymous inner class
      ); // end call to addItemListener
      
      chooseJComboBox = shapePanel.getChooser(); // get shape chooser
      chooseJComboBox.addItemListener(
         new ItemListener() // anonymous inner class
         { 
            // change the shape that is displayed
            public void itemStateChanged( ItemEvent event )
            {
               drawPanel.setShape( 
                  ( String )chooseJComboBox.getSelectedItem() );
            } // end method itemStateChanged
         } // end anonymous inner class
      ); // end call to addItemListener
      
      setLayout( new BorderLayout() ); // set layout
      add( shapePanel, BorderLayout.NORTH ); // add shape panel
      add( drawPanel, BorderLayout.CENTER ); // add drawing panel
      add( colorChooser, BorderLayout.SOUTH ); // add colorchooser
      
      addInternalFrameListener(
         new InternalFrameAdapter() // anonymous inner class
         { 
            // when the frame is closed, alert the DrawFrame
            public void internalFrameClosed( InternalFrameEvent e ) 
            {
               parent.frameClosed( name ); // alert parent
            } // end method internalFrameClosed
         } // end anonymous inner class
      ); // end call to addInternalFrameListener

      setSize( 300, 300 ); // set size of internal frame
   } // end DrawInternalFrame constructor
} // end class DrawInternalFrame
