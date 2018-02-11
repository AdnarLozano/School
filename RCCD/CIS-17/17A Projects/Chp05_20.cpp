// Adnar Lozano
// CIS-17A: C++ Programming
// October 2, 2014

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int guess;

	unsigned seed = time(0);

	srand(seed);

	int number = 1 + rand() % 100;

	cout << "Guess my number: ";
	cin >> guess;

	while (guess != number)
	{
		if(guess < number)
		{
			cout << "Too low... Try again!\n";
		}
		else if(guess > number)
		{
			cout << "Too high... Try again!\n";
		}

		cout << "Guess again: ";
		cin >> guess;
	}

	cout << "Congratulations, you got it!" << endl;
	cout << "My number was: " << number << endl;

	system("PAUSE");
}

