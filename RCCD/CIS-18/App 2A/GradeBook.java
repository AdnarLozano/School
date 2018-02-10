
import java.text.DecimalFormat;

import javax.swing.JOptionPane;

public class GradeBook {
	private String courseName;

	// Constructor
	public GradeBook(String name) 
	{
		courseName = name;
	}

	// get & set method
	public String getGradeBook() 
	{
		return courseName;
	}

	public void setGradeBook(String course) 
	{
		courseName = course;
	}

	// displayMessage() METHOD
	public void displayMessage() 
	{
		System.out.printf("Course taken from a contructor: \n%s!\n",
				getGradeBook());
	}

	// determineClassAverage() METHOD
	public void determineClassAverage() 
		{
		// VARIABLES
		double total;
		double average;

		int testSize;
		int gradeCounter;
		int x;

		String testInput;
		String gradeInput;

		// ASSIGNEMENT
		total = 0;
		gradeCounter = 1;
		testInput = JOptionPane.showInputDialog(null,
				"How many Test are you grading?", "Grading: " + courseName
						+ " Course", JOptionPane.PLAIN_MESSAGE);
		testSize = Integer.parseInt(testInput);
		double[] grade = new double[testSize];
		DecimalFormat df = new DecimalFormat("#0.00");
		while (gradeCounter < testSize) {
			for (x = 0; x < testSize; x++) {
				gradeInput = JOptionPane.showInputDialog(null, "Enter grade "
						+ (x + 1) + " >> ", "Grading: " + courseName
						+ " Course", JOptionPane.PLAIN_MESSAGE);

				if (Double.parseDouble(gradeInput) > 100) {
					JOptionPane.showMessageDialog(null,
							"Grades cannot be higher than 100");
					break;
				} else if (Double.parseDouble(gradeInput) < 0) {
					JOptionPane.showMessageDialog(null,
							"Grades cannot be lower than 0");
					break;
				} else {
					grade[x] = Double.parseDouble(gradeInput);
					total += grade[x];
					gradeCounter += 1;
				}
			}
		}

		// PROCESSING
		average = (total / testSize);
		System.out.println();

		// LOOP to display grade
		for (x = 0; x < testSize; x++) {
			System.out.println("Grade for Test " + (x + 1) + ": " + grade[x]);
		}

		System.out.println("\nThe total is: \t" + df.format(total));
		System.out.println("Class Average: \t" + df.format(average));

		JOptionPane.showMessageDialog(null, "Class Total: " + df.format(total),
				courseName + " Course Total", JOptionPane.PLAIN_MESSAGE);
		JOptionPane.showMessageDialog(null,
				"Class Average: " + df.format(average), courseName
						+ " Course Average", JOptionPane.PLAIN_MESSAGE);

	}
}
