// Adnar Lozano
// CSC-7: Discrete Structures
// April 1, 2015
// I . A
// A . I
// A . B  <--- workout by hand & program


#include <iostream>


using namespace std;

class Matrix
{
	public:	float m[4][4];

	Matrix friend operator + (const Matrix&A, const Matrix& B);

	Matrix friend operator * (const Matrix&A, const Matrix& B);
};




Matrix operator + (Matrix&A, Matrix&B)
{

	Matrix C;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{	
				C.m[i][j] = (A.m[i][j] * B.m[i][j]);
		}
	}
	return C;
}

Matrix operator * (Matrix&A, Matrix&B)
{

	Matrix C;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			C.m[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				C.m[i][j] = C.m[i][j] + (A.m[i][j] * B.m[i][j]);
			}
		}
	}
	return C;
}

Matrix Add(const Matrix& A, const Matrix& B)
{
	Matrix C;

	// i = row #
	for (int i = 0; i < 4; i++)
	{
		// j = co #
		for (int j = 0; j < 4; j++)
		{
			C.m[i][j] = (A.m[i][j] + B.m[i][j]);
		}

	}
	 return C;
}


Matrix Multiply(const Matrix& A, const Matrix& B)
{
	Matrix C;
		// i = row #
		for (int i = 0; i < 4; i++)
		{
			// j = co #
			for (int j = 0; j < 4; j++)
			{
				C.m[i][j] = 0;
				for (int k = 0; k < 4; k++)
				{
					C.m[i][j] = (A.m[i][j] * B.m[i][j]);
				}
			}

		}

		return C;

}

void print(const Matrix& A)
{
	// i = row #
	for (int i = 0; i < 4; i++)
	{
		// j = co #
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
	// i = row #

	for (int i = 0; i < 4; i++)
	{
		// j = co #
		for (int j = 0; j < 4; j++)
		{
			cin >> A.m[i][j];
		}

		cout << "\n";
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