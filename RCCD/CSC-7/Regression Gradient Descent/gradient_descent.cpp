#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

double STEP				= 0.0001;
const double THRESHOLD	= 0.01;
const unsigned int MAXITERATIONS = 25000;


//take in filename, populate x, y
void LoadFile(string file, vector<float>& x, vector<float>& y)
{
	ifstream in;
	in.open(file);
	if (in.fail())
		exit(404);

	float tx, ty;

	while (in >> tx >> ty)
	{
		x.push_back(tx);
		y.push_back(ty);
	}

	in.close();
}


//take in x, y, determine m, b
double CurveFit(float &m, float& b, const vector<float>& x, const vector<float>& y)
{


	double Err;		//total error^2
	double Err_m;	// dErr / dm
	double Err_b;	// dErr / db
	double temp;

	double Err_m_prev = 1e20;
	double Err_b_prev = 1e20;

	unsigned int n = x.size();	//holding 

	unsigned int iteration = 0;
	do {
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "Iteration: " << ++iteration;

		Err = 0;
		Err_m = 0;
		Err_b = 0;

		for (unsigned int i = 0; i < n; i++)
		{
			temp = (y[i] - m * x[i] - b) / n;

			Err   += temp * temp * n;
			Err_m += (-2 * temp * x[i]);
			Err_b += (-2 * temp);
		}

		
		//resize step size
		/*if (Err_m_prev <= Err_m || Err_b_prev <= Err_b)
			STEP *= .1;
		Err_m_prev = Err_m;
		Err_b_prev = Err_b;
		*/
		//update estimate
		m -= STEP * Err_m;
		b -= STEP * Err_b;

	} while (Err > THRESHOLD && iteration < MAXITERATIONS && STEP > 0);
	cout << endl;

	return sqrt(Err);
}


int main()
{
	string filename;
	float m, b, err;
	vector<float> x, y;

	cout << "Enter filename: ";
	cin >> filename;

	cout << "Enter initial m, b guess: ";
	cin >> m >> b;

	LoadFile(filename, x, y);
	err = CurveFit(m, b, x, y);

	cout << "Estimated m, b: " << m << ", " << b << endl;
	cout << "Error: " << err << endl;

	system("pause");
	return 0;
}