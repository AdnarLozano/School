// Adnar Lozano
// October 7, 2014
// CIS-17A: C++ Programming

#include <iostream>
#include <iomanip>
using namespace std;

double calcRetail (double, double);
int main()
{
	double wholesale;
	double markup;

	cout << "Enter Wholesale Cost: " ;
	cin >> wholesale;

	while(wholesale <= 0)
	{
		cout << "INVALID DATA!" << endl;
		cout << "Enter Wholesale Cost: ";
		cin >> wholesale;
	}

	cout << "Enter Markup Percentage: ";
	cin >> markup;

	while(markup <= 0)
	{
		cout << "INVALID DATA!" << endl;
		cout << "Enter Markup Cost: ";
		cin >> markup;
	}

	cout << "The items retail price is $" << setprecision(2) << fixed << showpoint
		<< calcRetail(wholesale, markup) << ",\n";

	system("PAUSE");
	return 0;
}

double calcRetail(double w, double m)
{
	return w + (w * m * 0.01);
}