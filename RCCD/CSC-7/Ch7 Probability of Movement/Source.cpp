#include <iostream>

using namespace std;

float temp[20];

void CalcP(float p[], float p_m, int size)
{

	for (int i = 0; i < size; i++)
	{
		// at loc i and didnt move or at loc i-1 and moved
		if (i > 0)
			temp[i] = p[i] * (1 - p_m) + p[i - 1] * p_m;
		else
			temp[i] = p[i] * (1 - p_m);
	}

	memcpy(p, temp, sizeof(float)*size);
}


int main()
{
	float p[20] = { 1, 0 };
	float p_m = .9f;

	for (int t = 0; t < 100; t++)
	{

		cout << "t = " << t << endl;

		for (int i = 0; i < 20; i++)
		{
			cout << p[i] << "\t | ";
		}

		CalcP(p, p_m, 20);
		system("pause");
	}




	return 0;
}