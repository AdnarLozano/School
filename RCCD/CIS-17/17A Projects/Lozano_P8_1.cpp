// Adnar Lozano
// November 13, 2014
// CIS-17A: C++ Programming
// Chapter 8, Programming Challenge 1: Charge Account Validation

#include <iostream>
using namespace std;

// Function prototype
bool searchList(long [], int, long);

// Constant for the array size
const int SIZE = 18;

int main()
{
	// Array of account numbers
	long accounts[SIZE] = { 5658845,  4520125,  7895122,
						    8777541,  8451277,  1302850,
							8080152,  4562555,  5552012,
							5050552,  7825877,  1250255,
							1005231,  6545231,  3852085,
							7576651,  7881200,  4581002 };
        
	long accountNumber;  // To hold an account number

	// Get an account number from the user.
	cout << "Welcome to Charge Account Verification\n";
	cout << "--------------------------------------\n";
	cout << "\nPlease enter a 7-digit account number:  ";
	cin  >> accountNumber;

	// Search the array for the number and indicate whether it is valid or not.
	if (searchList(accounts, SIZE, accountNumber))   
		cout << "\nCongrats! The number you entered is valid.\n\n";
	else
		cout << "\nSorry, the number you entered is invalid.\n" << endl;

	system("PAUSE");
}


bool searchList(long list[], int size, long value)
{
	bool found = false; // Flag
	int count = 0;      // Loop counter

	// Step through the array as long as the value
	// is not found.
	while (!found && count < size)
	{
		if (list[count] == value)
			found = true;  // The value is found.
		count++;
	}
   
	return found;
}