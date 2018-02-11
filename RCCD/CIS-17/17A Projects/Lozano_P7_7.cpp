// Adnar Lozano
// November 06, 2014
// CIS-17A: C++ Programming
// Chapter 7, Programming Challenge 7: Number Analysis

#include <iostream>
#include <fstream>
using namespace std;

// Global constant for the array size
const int ARRAY_SIZE = 12;

// Function prototypes
void readNumbers(ifstream &, int [], int);
int getLowest(int [], int);
int getHighest(int [], int);
int getSum(int [], int);
double getAverage(int [], int);

int main()
{
	// File stream object
	ifstream inFile;
   
	// Array to hold the numbers
	int numbers[ARRAY_SIZE];

	// Open the file.
	inFile.open("numbers.txt");
   
	// Test for errors.
	if (!inFile)
	{
		cout << "Error opening the file.\n";
		return 0;
	}

	// Read the numbers into the array.
	readNumbers(inFile, numbers, ARRAY_SIZE);

	// Close the file.
	inFile.close();

	// Display data about the numbers.
	cout << "The highest value is " 
		 << getHighest(numbers, ARRAY_SIZE) 
		 << endl;

	cout << "The lowest value is " 
		 << getLowest(numbers, ARRAY_SIZE) 
		 << endl;

	cout << "The sum of the numbers is " 
		 << getSum(numbers, ARRAY_SIZE) 
		 << endl;

	cout << "The average of the numbers is " 
		 << getAverage(numbers, ARRAY_SIZE)
		 << endl;

	system("PAUSE");
}

// The readNumbers function reads numbers from inFile and
// stores them in the numbers array. 

void readNumbers(ifstream &inFile, int numbers[], int size)
{
   for (int i = 0; i < size; i++)
      inFile >> numbers[i];
}

// The getLowest function finds the lowest value in the
// array and returns that value. The size parameter is
// the number of elements in the array.

int getLowest(int values[], int size)
{
	int lowest = values[0];

	for (int i = 1; i < size; i++)
	{
		if (values[i] < lowest)
			lowest = values[i];
	}

	return lowest;
}

// The getHighest function finds the highest value in the
// array and returns that value. The size parameter is
// the number of elements in the array.

int getHighest(int values[], int size)
{
	int highest = values[0];

	for (int i = 1; i < size; i++)
	{
		if (values[i] > highest)
			highest = values[i];
	}

	return highest;
}

// The getSum function calculates and returns the sum of
// the values stored in the array.

int getSum(int values[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += values[i];

	return sum;
}

// The getAverage function calculates and returns the
// average of the values stored in the array.

double getAverage(int values[], int size)
{
   return getSum(values, size) / static_cast<double>(size);
}