// Adnar Lozano
// CIS-17A: C++ Programming
// October 2, 2014

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double CALORIES = 3.6;
	const int START = 5;
	const int END = 30;
	const int STEP = 5;

	cout << setprecision(1)
		 << fixed << showpoint;

	for(int time = START; time <= END; time += STEP)
	{
		cout << setw(5) << time * CALORIES
			 << " calories were burned after "
			 << setw(2) << time << " minutes.\n";
	}

	system("PAUSE");
}