// Adnar Lozano
// CIS-17A: C++ Programming
// September 25, 2014

#include <iostream>
using namespace std;

void main()
{
	int num1;
	int num2;

	cout << "Enter 1st Number: ";
	cin >> num1;

	cout << "Enter 2nd Number: ";
	cin >> num2;

	if (num1 > num2)
	{
		cout << num1 << " is larger than " << num2 << endl;
	}
	
	else if (num2 > num1)
	{
		cout << num2 << " is larger than " << num1 << endl;
	}
	else
	{
		cout << num1 << " is equal to " << num2 << endl;
	}

	// conditional operator

	cout << num1 << " is " << (num1 > num2 ? "larger than " : " smaller than ") << num2 << endl;

	system("PAUSE");
}