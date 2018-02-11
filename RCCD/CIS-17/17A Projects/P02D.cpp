// Adnar Lozano
// CIS-17A C++ Programing
// September 11, 2014


#include <iostream>
using namespace std;

void main()
{
	double amount;
	int penny, nickle, dime, quarter, half;
	int total, x = 5;
	int y = 5;

	cout << "Enter Amount: ";
	cin >> amount;

	total = amount * 100;

	half = total / 50;
	total = total - (half * 50);

	quarter = total / 25;
	total = total - (quarter * 25);

	dime = total / 10;
	total = total - (dime * 10);

	nickle = total / 5;
	total = total - (nickle * 5);

	penny = total / 1;

	cout << "Half Dollar: " << half << endl;
	cout << "Quarter: " << quarter << endl;
	cout << "Dime: " << dime << endl;
	cout << "Nickle: " << nickle << endl;
	cout << "Penny: " << penny << endl;

	if(x < 10)
	{
		int y = 5;
		cout << "y = " << y << endl;
	}
		cout << "y = " << y << endl;

	system("PAUSE");
}