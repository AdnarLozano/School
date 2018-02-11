// Adnar Lozano
// October 16, 2014
// CIS-17A: C++ Programming
// Chapter 6, Programming Challenge 11: Lowest Score Drop

#include <iostream>
using namespace std;

// Function prototypes
void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main()
{	
	int score1;
	int score2; 
	int score3; 
	int score4; 
	int score5; 

	cout << "This program calculates the average of a group of test scores,\n"
		 << "where the lowest score in the group is dropped.\n" << endl;

	// Get the five test scores.
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	calcAverage(score1, score2, score3, score4, score5);

	system("PAUSE");
}

// getScore function
void getScore(int &score)
{
	// Ask the user for a test score.
	cout << "Enter a test score: ";
	cin >> score;

	// Validate the score.
	while (score < 0 || score > 100)
	{
		cout << "Invalid Input. Enter a test score between 0 and 100: ";
		cin >> score;
	}
}

// calcAverage function
void calcAverage(int score1, int score2, int score3, int score4, int score5)
{
	// Get the lowest score.
	int lowest = findLowest(score1, 
		                    score2, 
							score3, 
							score4, 
							score5);

	// Get the total of all the scores.
	int total = score1 + score2 + score3 + score4 + score5;

	// Drop the lowest score and calculate the average.
	int average = (total - lowest) / 4;

	// Display the average.
	cout << "After dropping the lowest score, " 
		 << "the test average is " 
		 << average << ".\n" << endl;
}

// findLowest function 
int findLowest(int score1, int score2, int score3, 
	           int score4, int score5)
{
	int lowest;	

	if (score1 < score2 && score1 < score3 && 
		score1 < score4 && score1 < score5)
		lowest = score1;
	else if (score2 < score1 && score2 < score3 && 
			 score2 < score4 && score2 < score5)
		lowest = score2;
	else if (score3 < score1 && score3 < score2 && 
			 score3 < score4 && score3 < score5)
		lowest = score3;
	else if (score4 < score1 && score4 < score2 && 
			 score4 < score3 && score4 < score5)
		lowest = score4;
	else
		lowest = score5;

	return lowest;
}