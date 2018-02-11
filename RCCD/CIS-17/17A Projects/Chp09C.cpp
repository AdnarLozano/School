// Adnar Lozano
// November 13, 2014
// CIS-17A: C++ Programming

#include <iostream>

using namespace std;

void main()
{
	int apples;
	int *ptr = nullptr;

	cout << "How many apples: ";
	cin >> apples;
	
	cout << endl;

	ptr = &apples;

	cout << "Print value of apples and *ptr..." << endl;
	cout << apples << endl;
	cout << *ptr << endl; 
	cout << endl;

	cout << "How many apples? ";
	cin >> *ptr;

	cout << endl;

	cout << "Print value of apples and *ptr..." << endl;
	cout << apples << endl;
	cout << *ptr << endl; 
	cout << endl;

	system("PAUSE");
}