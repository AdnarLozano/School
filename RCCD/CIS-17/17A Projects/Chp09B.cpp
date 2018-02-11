// Adnar Lozano
// November 13, 2014
// CIS-17A: C++ Programming

#include <iostream>

using namespace std;

void main()
{
	int number = 100;
	int *ptr = nullptr;

	// store the address of number in ptr
	ptr = &number;

	// print value and adress of number
	cout << "  Value of number: " << number << endl;
	cout << "Address of number: " << ptr << endl;

	cout << endl;

	system("PAUSE");
}