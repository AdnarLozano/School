// Adnar Lozano
// September 18, 2014
// CIS-17A: C++ Programming
// Chapter 2, Programming Challenge 13: Circuit Board

#include <iostream>
using namespace std;

int main()
{
	// Constants
	const double PROFIT = 0.40;

	// Store the cost of the circuit board.
	double cost = 12.67;

	// Calculate and store the markup.
	double markup = cost * PROFIT;

	// Calculate and store the retail price.
	double retail = cost + markup;

	cout << "The selling price of a circuit board \n"
         << "that costs $" << cost << " with a 40% profit is: $"
         << retail << endl;
	system("PAUSE");
}