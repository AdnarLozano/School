/*
	minesweeper!!!!!!

*/
#include <iostream>
#include <ctime>
using namespace std;

const int BOMB=-1;  // or enum { BOMB =-1 }

const int WIDTH = 10;
const int HEIGHT = 10;

int numbombs = 15;

int minefield[WIDTH][HEIGHT] = {0};
int revealed[4] = {0}; 

void DisplayField()
{
	for (int row=0; row<HEIGHT; row++)
	{
		for(int col=0; col<WIDTH; col++)
		{

			int i=(row*WIDTH+col) / (sizeof(int)*8); // index number
			int b=(row*WIDTH+col) % (sizeof(int)*8); // bit offset

			// bitmask to check if element if revealed
			if ( revealed[i] & (1<<b) )
			{

			if (minefield[col][row] == BOMB)
				cout << "_ ";
			else
				cout << minefield[col][row] << " ";
			} // hide with an 'X'
			else
			{
				cout << "X ";
			}
		}
		cout << endl;
	}
}

void Reveal(int x, int y)
{
	int i= (y * WIDTH + x) / (sizeof(int)*8); // index number
	int b= (y * WIDTH + x) % (sizeof(int)*8); // bit offset

	// bitmask to set if element if revealed
	revealed[i] |= (1<<b);
}

// increment surrounding cells
void CountBomb(int col, int row)
{
	for(int r = row-1; r<=row+1; r++)
	{
		for (int c=col-1; c<=col+1; c++)
		{	
			if(c < 0 || r < 0)
				continue;
			if (c >= HEIGHT || r >= WIDTH)
				continue;
			if (minefield[c][r] == BOMB)
				continue;

			minefield[c][r]++;
		}
	}
}
void SetupField()
{
	memset(minefield, 0, sizeof(int)*HEIGHT*WIDTH );

	int row, col;
	for(int b=0; b<numbombs; b++)
	{
		row = rand() % HEIGHT;
		col = rand() % WIDTH;


		// set us up the bomb
		
		if(minefield[col][row] !=BOMB)
		{
			minefield[col][row] = BOMB;
			CountBomb(col,row);
		}
		else
		{
			b--;
		}
	}

}

int main()
{
	// choose random seed
	srand(time(NULL));

	SetupField();
	DisplayField();

	int x,y;
	while( cin >> x >> y )
	{
		Reveal(x,y);
		DisplayField();
	}

	return 0;
}