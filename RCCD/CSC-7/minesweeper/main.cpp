/*
	minesweeper!!!!!!111
*/
#include <iostream>
#include <ctime>

using namespace std;

const int BOMB   = -1;

const int WIDTH  = 10;
const int HEIGHT = 10;

int numbombs = 15;

int minefield[WIDTH][HEIGHT] = {0};

void DisplayField()
{
	for (int row=0; row<HEIGHT; row++)
	{
		for (int col=0; col<WIDTH; col++)
		{
			if (minefield[col][row] == BOMB)
				cout << "_ ";
			else
				cout << minefield[col][row] << " ";
		}
		cout << endl;
	}
}

//increment surround cells 
void CountBomb(int col, int row)
{
	for (int r=row-1; r<=row+1; r++)
	{
		for (int c=col-1; c<=col+1; c++)
		{
			if (c < 0 || r < 0)
				continue;
			if (c >= HEIGHT || r >= WIDTH)
				continue;
			if (minefield[c][r] == BOMB)
				continue;

			minefield[c][r]++;
		}
	}
}

/*
2 _ 1 1 _ 1 0 0 1 1
_ 2 2 2 2 1 0 0 1 _
1 2 2 _ 1 0 0 0 1 1
0 1 _ 2 1 0 0 0 0 0
1 2 3 2 1 0 1 1 1 0
1 _ 3 _ 2 0 1 _ 1 0
3 3 5 _ 3 0 1 1 1 0
_ _ 4 _ 2 0 0 0 0 0
4 _ 3 1 1 0 0 0 0 0
_ 2 1 0 0 0 0 0 0 0
Press any key to continue . . .
*/

void SetupField()
{
	memset(minefield, 0, sizeof(int)*HEIGHT*WIDTH );

	int row, col;
	for (int b=0; b<numbombs; b++)
	{
		row = rand() % HEIGHT;
		col = rand() % WIDTH;

		// set us up the bomb
		if (minefield[col][row] != BOMB)
		{
			minefield[col][row] = BOMB;
			CountBomb(col, row);
		}
		else
		{
			b--;
		}
	}
}


int main()
{
	//choose random seed
	srand(time(NULL));

	SetupField();
	DisplayField();

	return 0;
}