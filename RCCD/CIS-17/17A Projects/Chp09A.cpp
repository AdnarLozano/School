// Adnar Lozano
// November 13, 2014
// CIS-17A: C++ Programming

#include <iostream>

using namespace std;

void main()
{
	int number1 = 1000000;
	int number2 = 5;
	int number3 = -1000000;

	cout << "Address: " << &number1 << endl;
	cout << "   Size: " << sizeof(number1) << " bytes" << endl;
	cout << "  Value: "	<< number1 << endl;

	cout << endl;

	cout << "Address: " << &number2 << endl;
	cout << "   Size: " << sizeof(number2) << " bytes" << endl;
	cout << "  Value: "	<< number2 << endl;

	cout << endl;

	cout << "Address: " << &number3 << endl;
	cout << "   Size: " << sizeof(number3) << " bytes" << endl;
	cout << "  Value: "	<< number3 << endl;

	cout << endl;

	system("PAUSE");

}
