// Adnar Lozano
// September 18, 2014
// CIS-17A: C++ Programming
// Chapter 4, Programming Challenge 5: Body Mass Index

#include <iostream>
using namespace std;

int main()
{
    double weight;  // Weight, in pounds
    double height;  // Height, in inches
    double bmi;     // Body Mass Index

    // Get the user's weight.
    cout << "Enter your weight in pounds: ";
    cin >> weight;

    // Get the user's height.
    cout << "Enter your height in inches: ";
    cin >> height;

    // Calculate the BMI.
    bmi = weight * 703 / (height * height);

    // Display the BMI.
    cout << "Your BMI is " << bmi << endl;
    
    // Determine the user's weight status.
    if (bmi < 18.5)
        cout << "You are underwight.\n";
    else if (bmi > 25)
        cout << "You are overweight.\n";
    else
        cout << "Congratulations! Your weight is consider optimal.\n";
    
	system("PAUSE");
}