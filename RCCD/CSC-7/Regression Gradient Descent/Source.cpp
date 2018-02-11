#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GenerateFile(string savefile, float x0, float x1, float dx, float m, float b)
{
	if (x0 > x1)
		swap(x0, x1);
	if (dx < 0)
		dx = -dx;
	if (dx == 0)
		dx = 0.1;


	ofstream out;
	out.open(savefile);

	float y;


	for (float t = x0; t <= x1; t += dx)
	{
		y = m*t + b;

		out << t << "\t" << y << endl;
	}


	out.close();




}

int main()
{
	string savefile;
	float m, b;
	float x0, x1;
	float dx;

	cout << "y=mx + b; enter m and b: ";
	cin >> m >> b;

	cout << "Enter start x and end x: ";
	cin >> x0 >> x1;

	cout << "Enter stepsize: ";
	cin >> dx;

	cout << "Enter save file: ";
	cin >> savefile;

	GenerateFile(savefile, x0, x1, dx, m, b);

	return 0;
}
