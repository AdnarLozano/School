
import javax.swing.JOptionPane;

public class GradeBookTest {

	public static void main(String[] args) {

		try {
			String courseInput = JOptionPane.showInputDialog(null,
					"Enter your course name >> ");

			System.out.println();

			GradeBook gb = new GradeBook(courseInput);

			// GradeBook gb1 = new GradeBook("The Night's Watch");
			// GradeBook gb2 = new GradeBook("King's Landing");

			gb.setGradeBook(courseInput);
			System.out.printf("The course you entered is %s\n",
					gb.getGradeBook());
			gb.determineClassAverage();

			// from constructor
			// gb1.displayMessage();
			// /gb2.displayMessage();
		} catch (Exception e) {
			JOptionPane.showMessageDialog(null, "Error: something went wrong!");
		}
	}
}