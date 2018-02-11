// Adnar Lozano
// November 6, 2014
// CIS-17A: C++ Programming

#include <iostream>
#include <string>

using namespace std;

void selectionSort(string [], int);
void displayArray(string [], int);

int main()
{
	const int NUM_NAMES = 20;

	string names[NUM_NAMES] = { "Mouse, Mickey", "Duck, Donald", "Duck, Daisy", 
		"Duck, Daffy", "Squarepants, Spongebob", "Panther, Pink", "TheSailorMan, Popeye",
		"Coyote, Wyll-e", "Minece, Dennis", "Fox, Sly", "Bunny, Buggs", "Sam, Yosemite",
		"Bunny, Babbs", "Pig, Porky", "Oil, Olive", "Pea, Sweet", "Bird, Tweety", "Mouse, Minnie",
		"Mouse, Mighty", "Gonzalez, Speedy"};

	// Display the unsorted array
	displayArray(names, NUM_NAMES);

	// Sort Array
	selectionSort(names, NUM_NAMES);

	// Display sorted Array
	cout << "\n" << endl;
	cout << "Sorted Names..." << endl;
	cout << "---------------" << endl;
	displayArray(names, NUM_NAMES);
	cout << "\n" << endl;

	system("PAUSE");

	return 0;
}


void selectionSort(string values[], int size)
{
	int startScan;
	int minIndex;
	string minValue;

	for(startScan = 0; startScan < (size-1); startScan++)
	{
		minIndex = startScan;
		minValue = values[minIndex];

		for(int index = startScan +1; index < size; index++)
		{
			if(values[index] < minValue)
			{
				minValue = values[index];
				minIndex = index;
			}
		}
		values[minIndex] = values[startScan];
		values[startScan] = minValue;
	}
}

void displayArray(string values[], int size)
{
	for(int i =0; i < size; i++)
	{
		if(i < 10 - 1)
		{
		cout << " " << (i+1) << ". " <<values[i] << endl;
		}
		else
		{
			cout << (i+1) << ". " << values[i] << endl;
		}
	}
}