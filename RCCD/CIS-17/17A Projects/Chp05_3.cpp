// Adnar Lozano
// CIS-17A: C++ Programming
// October 2, 2014

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double RISE_PER_YEAR = 1.5;
	const int YEARS = 25;
	double oceanRise = 0.0;

	cout << setprecision(2) << fixed << showpoint;
	cout << "Year\t" << "Rise\n"
		 << "================\n";

	for (int year = 1; year <= YEARS; year++)
	{
		oceanRise = RISE_PER_YEAR * year;
		cout << year << "\t" << setw(5)
			 << oceanRise << " mm"
			 << "\n----------------\n";
	}

	cout << endl;

	system("PAUSE");
}