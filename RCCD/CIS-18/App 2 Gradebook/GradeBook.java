
import javax.swing.JOptionPane; // import class JOptionPane

public class GradeBook
{
   private String courseName;
  
   public GradeBook(String initialGradebook)
   {
   		courseName = initialGradebook;
   }

   public void setCourseName( String name )
   {
      courseName = name;
   }

   public String getCourseName()
   {
      return courseName;
      
   }

   public void displayMessage()
   {
   	 String message =
      String.format("Welcome to the grade book for:\n" +
       getCourseName() );
      
      JOptionPane.showMessageDialog(null, message );
     
   }
}

