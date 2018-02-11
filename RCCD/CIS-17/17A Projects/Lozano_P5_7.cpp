// Adnar Lozano
// October 7, 2014
// CIS-17A: C++ Programming
// Chapter 5, Programming Challenge 7: Pennies for Pay

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int maxDays = 0;        // Number of days
	double pay;         // The pay for any given day 
	double grandTotal;  // The total pay
   
	// The pay variable must start with 0.01.
	pay = 0.01;
   
	// The grandTotal variable is an accumulator, so it must start at zero.
	grandTotal = 0.0;

	// Get the number of days from the user.
	cout << "How many days did you work? ";
	cin  >> maxDays;
	
	// Validate the number of days, which must be at least one positive integer.
	
	while (maxDays < 1 || cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nThe number of days must be a positive integer number.\n";
		cout << "Re-enter the number of days: ";
		cin >> maxDays;		
	}
	
	// Display the table headings.
	cout << "\nDay\t\tTotal pay\n";
	cout << "---------------------------------\n";
   
	// Set the numeric output formatting.
	cout << fixed << showpoint << setprecision(2);

	// Display the table data
	for (int day = 1; day <= maxDays; day++)
	{
		// Display the day number and the amount of pay for the day.
		cout << day << "\t\t$"
			 << setw(10) << pay << endl;
      
		// Add the pay for the day to grandTotal.
		grandTotal += pay;
      
		// Double the pay for the next day.
		pay *= 2;
	}
   system("PAUSE");	
}