// Adnar Lozano
// November 20, 2014
// CIS-17A: C++ Programming
// Chapter 9, Programming Challenge 4: Test Scores #2

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void sort(string*, double*, int);  
double average(double*, int); 

int main()
{
	int numTestScores = 0;			// The number of test scores
	double testAverage = 0;			// To hold the average score
	double *testScorePtr = nullptr; // To point to an array
	string *namesPtr = nullptr;     // To point to the names

	cout <<"Welcome!" << endl;
	cout << "\nHow many test scores will you enter? ";
	cin >> numTestScores;
   
	// Validate the input.
	while (numTestScores < 0)
	{
		cout << "The umber cannot be negative.\n";
		cout << "Enter another number: ";
		cin >> numTestScores;
	}

	// Allocate an array to hold the test scores.
	testScorePtr = new double[numTestScores];
   
	// Allocate an array to hold the names.
	namesPtr = new string[numTestScores];

	// Populate the arrays.
	for (int i = 0; i < numTestScores; i++)
	{
		// Get a name.
		cout << "\nEnter student " << (i + 1)
		     << "'s last name: ";
		cin >> namesPtr[i];
      
		// Get a test score.
		cout << "Enter that student's test score: ";
		cin >> testScorePtr[i];
      
		// Validate the input.
		while (testScorePtr[i] < 0)
		{
			cout << "Negative scores are not allowed.\n";
			cout << "Enter another score for this test: ";
			cin >> testScorePtr[i];
		}
	}

	// Sort the test scores.
	sort(namesPtr, testScorePtr, numTestScores);

	// Get the average of the test scores.
	testAverage = average(testScorePtr, numTestScores);

	// Display the resulting data.
	cout << "\nThe test scores in ascending "
	     << "order, and their average, are:\n\n";
	cout << setw(12) << left << "Name" << setw(6) 
	     << " Score" << endl;
	cout << "----------------------------------------" << endl;
	cout << setprecision(2) << fixed << showpoint;
   
	for (int j = 0; j < numTestScores; j++)
	{
		cout << endl;
		cout << setw(12) << left << namesPtr[j];
		cout << setw(6) << testScorePtr[j];
	}

	cout << "\n\nAverage score:  " << setprecision(2)
	     << fixed << testAverage << endl << endl;

	// Free the dynamically-allocated memory.
	delete [] namesPtr;
	delete [] testScorePtr;
	namesPtr = nullptr;
	testScorePtr = nullptr;
   
	system("PAUSE");
}

void sort(string *names, double *score, int size)
{
	int startScan, minIndex;
	string minName;
	double minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];
		minName = names[startScan];
      
		for(int index = startScan + 1; index < size; index++)
		{
			if (score[index] < minValue)
			{
				minValue = score[index];
				minName = names[index];
				minIndex = index;
			}
		}
      
		score[minIndex] = score[startScan];
		names[minIndex] = names[startScan];
      
		score[startScan] = minValue;
		names[startScan] = minName;
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