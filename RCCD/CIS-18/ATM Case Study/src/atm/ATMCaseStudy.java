//Adnar Lozano
//CIS-18B: Java
//R.Casolaro
//03/06/2014

//ATMCaseStudy.java
//Driver program for the ATM case study
package atm; //needed for eclipse to connect all the classes

public class ATMCaseStudy
{
	// main method creates and runs the ATM
	public static void main( String[] args )
	{   
	boolean error;
		do{
			error = false;
			try {
	   		ATM theATM = new ATM();
	   		theATM.run();
				} // close the try
			catch (Exception e) {
				System.out.println("\nInvalid input...\nPlease enter the correct information.\n" 
				+ "For your protection, this session has ended.\nPlease log in again." );
				error = true;
				} // close the try catch statement
			} // Close do loop
		while (error);
		// close the while loop
	} // end main
} // end class ATMCaseStudy
