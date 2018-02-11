// Adnar Lozano
// CIS-17A C++ Programing
// September 11, 2014


#include <iostream>
using namespace std;

int main()
{
	// variables
	double pay, hours, salary;

	// input statements
	cout <<"Hourly pay: ";
	cin >> pay;

	cout <<"Hours worked: ";
	cin >> hours;

	// calculations
	salary = pay * hours;

	// display calculations
	cout <<"Salary: " << salary << endl;

	// Pausing the system
	system("PAUSE");

	return 0;
}