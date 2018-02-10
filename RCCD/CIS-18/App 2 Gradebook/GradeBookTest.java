
import javax.swing.JOptionPane; // import class JOptionPane
import java.util.Scanner;

public class GradeBookTest

{

   public static void main( String[] args )
   {

	  JOptionPane.showMessageDialog(null, "Welcome to MVC!!!\n"
	  	
	  								+ "---------------------------");
	  JOptionPane.showMessageDialog(null, "You will be entering 2 course names:");
	  
	  Scanner input = new Scanner( System.in );

      GradeBook myGradeBook1 = new GradeBook(null);
      
      JOptionPane.showMessageDialog(null,"The initial course name is " + myGradeBook1.getCourseName() );
     
      String course1 =  JOptionPane.showInputDialog(null,"Please enter the course name #1: ");
      myGradeBook1.setCourseName(course1) ;
      myGradeBook1.displayMessage();

      GradeBook myGradeBook2 = new GradeBook(null);
      
      String course2 = JOptionPane.showInputDialog(null,"Please enter the course name #2: ");
      myGradeBook2.setCourseName(course2);
      System.out.println();
      myGradeBook2.displayMessage();


   }
}

