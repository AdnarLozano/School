// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: ShapePanel.java
// This class allows the user to choose a shape and fill setting.

import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JCheckBox;

@SuppressWarnings("serial")
public class ShapePanel extends JPanel 
{
   // one of these objects will be used to draw the shape
   private static final String[] shapeList = 
      { "Rectangle", "Line", "Oval" };
   @SuppressWarnings("rawtypes")
   private JComboBox chooseJComboBox;
   private JCheckBox filledJCheckBox;
   
   // no-argument constructor
   @SuppressWarnings({ "rawtypes", "unchecked" })
   public ShapePanel() 
   {
      chooseJComboBox = new JComboBox( shapeList );
      filledJCheckBox = new JCheckBox( "Filled", false );
      add( chooseJComboBox );
      add( filledJCheckBox );
   } // end no-argument ShapePanel constructor
   
   public JCheckBox getFill() 
   {
      return filledJCheckBox;
   } // end method getFill
   
   @SuppressWarnings("rawtypes")
   public JComboBox getChooser()
   {
      return chooseJComboBox;
   } // end method getChooser
} // end class ShapePanel
