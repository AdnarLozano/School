// Adnar Lozano
// CIS-17A: C++ Programming
// September 25, 2014

#include <iostream>
using namespace std;

void main()
{
	int score;
	char grade;

	cout << "Enter score: ";
	cin >> score;

	if(score < 60)
	{
		grade = 'F';
	}
	else if(score < 70)
	{
		grade = 'D';
	}
	else if(score < 80)
	{
		grade = 'C';
	}
	else if(score < 90)
	{
		grade = 'B';
	}
	else
	{
		grade = 'A';
	}

	cout << "Grade: " << grade << endl;
		 
	system("PAUSE");
}
