// Adnar Lozano
// CIS-17A: C++ Programming
// September 25, 2014

#include <iostream>
using namespace std;

void main()
{
	int number;

	cout << "Enter a number (1-10): ";
	cin >> number;
	
	switch(number)
	{
	case 1: cout << number << " = I" << endl; break;
	case 2: cout << number << " = II" << endl; break;
	case 3: cout << number << " = III" << endl; break;
	case 4: cout << number << " = IV" << endl; break;
	case 5: cout << number << " = V" << endl; break;
	case 6: cout << number << " = VI" << endl; break;
	case 7: cout << number << " = VII" << endl; break;
	case 8: cout << number << " = VIII" << endl; break;
	case 9: cout << number << " = IX" << endl; break;
	case 10: cout << number << " = X" << endl; break;
	}
	system("PAUSE");
}
