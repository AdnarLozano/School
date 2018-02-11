// Adnar Lozano
// CIS-17A: C++ Programming
// October 2, 2014

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int value;
	int sum = 0;

	do
	{
		cout << "Enter a value: ";
		cin >> value;
	}while (value < 0);

	for (int i = 1; i <= value; i++)
	{
		sum += i;
	}

	cout << "Sum: " << sum << endl << endl;
	
	system("PAUSE");
}

