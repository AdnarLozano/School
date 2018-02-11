// Adnar Lozano
// November 13, 2014
// CIS-17A: C++ Programming
// Chapter 8, Programming Challenge 2: Lottery Winners

#include <iostream>
using namespace std;

// Function prototype
bool searchList(const long [], int, long);

// Constant for array size
const int SIZE = 10;

int main()
{
	// Array of numbers that are always played
	long ticket[SIZE] = { 13579,  26791,  
						  26792,  33445,  
						  55555,  62483,  
						  77777,  79422,  
						  85647,  93121 };
                          
	// This variable will hold the winning number.
	long winningNum;

	// Get this week's winning number.
	cout << "Welcome to Lottery Winners\n";
	cout << "--------------------------\n";
	cout << "\nPlease enter this week's 5-digit "
		 << "winning lottery number: ";
	cin  >> winningNum;

	// Search for the winning number.
	if (searchList(ticket, SIZE, winningNum))
	{
		// If searchList returned true, then
		// the player has a winning ticket.
		cout << "\nYou have a winning ticket.\n\n";
	}
	else
	{
		cout << "\nYou did not win this week.\n" << endl;
	}

	system("PAUSE");
}


bool searchList(const long list[], int numElems, long value)
{
	bool found = false;

	for (int count = 0; count < numElems && !found; count++)
	{
		if (list[count] == value)
			found = true;
	}

	return found;
}
