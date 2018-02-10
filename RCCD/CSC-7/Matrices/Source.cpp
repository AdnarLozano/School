#include <iostream>

using namespace std;

struct Matrix
{
	float m[4][4];
};

Matrix Add(const Matrix& A, const Matrix& B)
{
}

Matrix Multiply(const Matrix& A, const Matrix& B)
{
}

void print(const Matrix& A)
{
	for (int i = 0; i < 4; i++)
	{
		//j = col#
		for (int j = 0; j < 4; j++)
		{
			cout << A.m[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void input(Matrix& A)
{
	//i = row #
	for (int i = 0; i < 4; i++)
	{
		//j = col#
		for (int j = 0; j < 4; j++)
		{
			cin >> A.m[i][j];
		}
	}
}

int main()
{
	Matrix A, B, C;

	cout << "Input values for matrix A:\n";
	input(A);

	cout << "Input values for matrix B:\n";
	input(B);

	C = Add(A, B);
	cout << "A + B = \n";
	print(C);

	C = Multiply(A, B);
	cout << "A * B = \n";
	print(C);

	return 0;
}