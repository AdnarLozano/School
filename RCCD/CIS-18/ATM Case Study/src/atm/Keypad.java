// Adnar Lozano
// CIS-18B: Java
// R.Casolaro
// 03/06/2014

// Keypad.java
// Represents the keypad of the ATM
package atm; //needed for eclipse to connect all the classes
import java.util.Scanner; // program uses Scanner to obtain user input

public class Keypad
{
   private Scanner input; // reads data from the command line
                         
   // no-argument constructor initializes the Scanner
   public Keypad()
   {
      input = new Scanner( System.in );    
   } // end no-argument Keypad constructor

   // return an integer value entered by user 
   public int getInput()
   {
      return input.nextInt(); // we assume that user enters an integer  
   } // end method getInput
} // end class Keypad 
