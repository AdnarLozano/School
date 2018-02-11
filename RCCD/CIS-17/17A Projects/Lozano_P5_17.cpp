// Adnar Lozano
// October 7, 2014
// CIS-17A: C++ Programming
// Chapter 5, Programming Challenge 17: Sales Bar Chart

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double store1;	// Sales for store 1
	double store2;	// Sales for store 2
	double store3;	// Sales for store 3
	double store4;	// Sales for store 4
	double store5;	// Sales for store 5
   
	int star;		// Control variable to print stars.

	// Get the sales figures for the five stores.
	cout << "Enter today's sales for store 1: ";
	cin  >> store1;
	cout << "Enter today's sales for store 2: ";
	cin  >> store2;
	cout << "Enter today's sales for store 3: ";
	cin  >> store3;
	cout << "Enter today's sales for store 4: ";
	cin  >> store4;
	cout << "Enter today's sales for store 5: ";
	cin  >> store5;

	// Print the bar chart heading.
	cout << "\n\nSALES BAR CHART\n";
	cout << "(each * = $100)\n";
   
	// Print the stars for store 1.
	cout << "Store 1: ";
	for (star = 1; star <= store1/100; star++)
		cout << '*';
	cout << endl;

	// Print the stars for store 2.
	cout << "Store 2: ";
	for (star = 1; star <= store2/100; star++)
		cout << '*';
	cout << endl;

	// Print the stars for store 3.
	cout << "Store 3: ";
	for (star = 1; star <= store3/100; star++)
		cout << '*';
	cout << endl;

	// Print the stars for store 4.
	cout << "Store 4: ";
	for (star = 1; star <= store4/100; star++)
		cout << '*';
	cout << endl;

	// Print the stars for store 5.
	cout << "Store 5: ";
	for (star = 1; star <= store5/100; star++)
		cout << '*';
	cout << endl << endl;

	system("PAUSE");
}