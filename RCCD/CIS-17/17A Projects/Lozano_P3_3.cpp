// Adnar Lozano
// September 18, 2014
// CIS-17A: C++ Programming
// Chapter 3, Programming Challenge 3: Test Average

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Constants
	const double NUM_TESTS = 5;
   
	// Variables
	double testScore1,		// 1st test score
		   testScore2,		// 2nd test score
		   testScore3,		// 3rd test score
		   testScore4,		// 4th test score
		   testScore5,		// 5th test score
		   testScoreAvg;	// Test score average

	// Get test scores.
	cout << "Enter the first test score: ";
	cin >> testScore1;

	cout << "Enter the second test score: ";
	cin >> testScore2;

	cout << "Enter the third test score: ";
	cin >> testScore3;

	cout << "Enter the fourth test score: ";
	cin >> testScore4;

	cout << "Enter the fifth test score: ";
	cin >> testScore5;
   
	// Calculate the test score average.
	testScoreAvg = (testScore1 + testScore2 + testScore3 + 
			        testScore4 + testScore5) / NUM_TESTS ;

	// Display the result.
	cout << "\nThe test score average is "
		 << fixed << showpoint << setprecision(1) 
		 << testScoreAvg << endl;
	system("PAUSE");
}
