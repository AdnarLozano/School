// Adnar Lozano
// October 16, 2014
// CIS-17A: C++ Programming
// Chapter 6, Programming Challenge 2: Rectangle Area

#include <iostream>
using namespace std;

// Function prototypes
double getLength();
double getWidth();
double getArea(double, double);
void displayData(double, double, double);

int main()
{
	double length;  
	double width;	
	double area;	
	
	cout << "This program will display the area of a rectangle based on functions" << endl;

	length = getLength();

	width = getWidth();
   
	area = getArea(length, width);
   
	displayData(length, width, area);
          
	system("PAUSE");
}

// getLength function
double getLength()
{
	double length;  
   
	cout << "Enter the length: ";
	cin >> length;

	return length;
}

// getWidth function
double getWidth()
{
	double width; 
   
	cout << "Enter the width: ";
	cin >> width;
   
	return width;
}

// getArea function 
double getArea(double length, double width)
{
	return length * width;
}

// displayData function
void displayData(double length, double width, double area)
{
	cout << "\nRectangle Data\n"
		 << "--------------\n"
	     << "Length: " << length << endl
	     << "Width:  " << width << endl
	     << "Area:   " << area << endl << endl;
}