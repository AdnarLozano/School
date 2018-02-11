//
//  playlist_byAdnar.cpp
//  Created by Adnar Lozano on 5/5/15.
//
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <time.h> 
#include <ctime>

using namespace std;
int p[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

void randomGenerator(int arr[], int n)
{
	//shuffle p
	for (int i = 9; i>0; --i)
	{
		//get swap index
		int j = rand() % i ;
		//swap p[i] with p[j]
		int temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}
	//copy first n elements from p to arr
	for (int i = 0; i < n; ++i)
		arr[i] = p[i];
}
int main(int argc, const char * argv[])
{
	srand(time(NULL));
	cout << "Playlist Shuffle Generator" << endl;
	cout << "--------------------------\n" << endl;
	cout << "Your Playlist: ";
	for (int i = 0; i<9; i++)
	{
		cout << p[i]  << ", ";
	}
	cout << p[9] << ".";
	cout << endl << endl;
	cout << "With Repeats: ";
	// Randomize the array
	for (int i = 0; i < 9; i++)
	{
		p[i] = rand() % 10 + 1;
		cout << p[i] << ", ";
	}
	p[9] = rand() % 10 + 1;
	cout << p[9] << ".";
	cout << endl << endl;

	// Reset the array back to 1-10
	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}

	cout << "With No Repeats: ";
	randomGenerator(p, 10);
	for (int i = 0; i < 9; i++)
	{
		cout << p[i] << ", ";
	}
	cout << p[9] << ".";
	cout << endl << endl;
	return 0;
}