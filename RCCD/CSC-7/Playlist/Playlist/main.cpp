//  main.cpp
//  Playlist
//  Created by Adnar Lozano on 5/13/15.
//  Copyright (c) 2015 Adnar Lozano. All rights reserved.

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
using namespace std;
const int size = 10;
string line[size];
void randomGenerator(string arr[], int n)
{
    //shuffle p
    for (int i=size-1; i>0; --i)
    {
        //get swap index
        int j = rand()%i;
        //swap p[i] with p[j]
        string temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
    //copy first n elements from p to arr
    for (int i=0; i<n; ++i)
        arr[i] = line[i];
}
int main()
{
	cout << "--------------------------" << endl;
    cout << "Playlist Shuffle Generator" << endl;
    cout << "--------------------------\n" << endl;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    cout << endl;
    srand(time(NULL));
    ifstream file(filename);
	int i=0;
    if(file.is_open()) {
        while(file.good() && i < size){
            getline(file,line[i]);
            i++;}
        cout << "Your Playlist:\n";
        cout << "--------------\n" << endl;
        for (i = 0; i < size-1; ++i)
            cout << i + 1 << " . " << line[i] << "\n";
		cout << size << ". " << line[size-1] <<'\n';
        cout << endl;
        
        cout << "Playlist with Repeats:\n";
        cout << "----------------------\n" << endl;
		for (i = 0; i < size-1; ++i)
            cout << i + 1 << " . " << line[rand() % 10] << "\n";
		cout << size << ". " << line[rand() % 10] <<'\n';
		cout << endl;
        
		cout << "Playlist with No Repeats:\n";
		cout << "-------------------------\n" << endl;
		randomGenerator(line, 10);
		for (i = 0; i < size-1; i++)
			cout << i + 1 << " . " << line[i] << "\n";
		cout << size << ". " << line[size-1] <<'\n';
		cout << endl << endl;
		file.close();}
    return 0;
}