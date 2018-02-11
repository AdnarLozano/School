// Adnar Lozano
// November 20, 2014
// CIS-17A: C++ Programming
// Chapter 9, Programming Challenge 2: Test Scores #1

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void sort(double*, int);  
double average(double*, int); 

int main()
{
	int numTestScores = 0;			// The number of test scores
	double *testScorePtr = nullptr;	// To point to an array
	double testAverage = 0;			// The test score average

	cout <<"Welcome!" << endl;
	cout << "\nHow many test scores will you enter? ";
	cin >> numTestScores;
   
	// Validate the input.
	while (numTestScores < 0)
	{
		cout << "The number cannot be negative.\n";
		cout << "Please enter another number: ";
		cin >> numTestScores;
	}

	// Allocate an array to hold the test scores.
	testScorePtr = new double[numTestScores];

	// Fill the array with test scores.
	for (int i = 0; i < numTestScores; i++)
	{
		// Get a test score.
		cout << "Enter test score "
		     << (i + 1) << ": ";
		cin >> testScorePtr[i];
      
		// Validate the input.
		while (testScorePtr[i] < 0)  
		{
			cout << "Negative scores are not allowed.\n";
			cout << "Please enter another score for this test: ";
			cin >> testScorePtr[i];
		}
	}

	// Sort the test scores.
	sort(testScorePtr, numTestScores);

	// Get the average of the test scores.
	testAverage = average(testScorePtr, numTestScores);

	cout << "\nThe test scores in ascending "
	     << "order and their average are:\n\n";
	cout << " Score" << endl;
	cout << " -----" << endl;
   
	for (int j = 0; j < numTestScores; j++)
	{
		cout << "\n" << fixed << setprecision(2) 
		     << setw(6) << testScorePtr[j];
	}

	cout << "\n\nAverage score:  " << setprecision(2)
	     << fixed << testAverage << endl << endl;

	// Free the dynamically-allocated memory.
	delete [] testScorePtr;
	testScorePtr = nullptr;
   
	system("PAUSE");
}

void sort(double* score, int size)
{
	int startScan, minIndex; 
	double minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];

		for(int index = startScan + 1; index < size; index++)
		{
			if (score[index] < minValue)
			{
				minValue = score[index];
				minIndex = index;
			}
		}

		score[minIndex] = score[startScan];
		score[startScan] = minValue;
	}
}


double average(double* score, int numScores)
{
	double total = 0; // Accumulator

	// Calculate the total of the scores.
	for (int k = 0; k < numScores; k++)
		total += score[k];
   
	// Return the average score.
	return (total / numScores);
}