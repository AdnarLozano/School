// Adnar Lozano
// November 13, 2014
// CIS-17A: C++ Programming

#include <iostream>

using namespace std;

void main()
{
	const int SIZE = 5;
	int testScore[SIZE];
	int *numPtr = nullptr;

	cout << "Enter five test scores..." << endl;
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Test " << (i+1) << ": ";
		cin >> testScore[i];
	}

	numPtr = testScore;

	cout << "\nThe test scores are.." << endl;
	for(int i = 0; i < SIZE; i++)
	{
		cout << *numPtr << " ";
		numPtr++;
	}

	cout << endl << endl;

	cout << "Test scores in reverse order.." << endl;
	for(int i=0; i<SIZE; i++)
	{
		numPtr--;
		cout << *numPtr << " ";
	}

	cout << endl << endl;

	system("PAUSE");
}