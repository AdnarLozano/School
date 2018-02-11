#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
class Board 
{
private:
	vector< vector<char> > data;
public:
	Board(int n)
	{
		this->resize(n);
	}
	void resize(int n)
	{
		this->data.resize(n);
		for (auto& row : this->data) {
			row.resize(n, '.');
		}
	}
	void clear()
	{
		for (auto& row : this->data) {
			for (auto& col : row) {
				col = '.';
			}
		}
	}
	char& operator()(int r, int c)
	{
		return this->data[r][c];
	}
	const char& operator()(int r, int c) const
	{
		return this->data[r][c];
	}
	int size() const
	{
		return this->data.size();
	}
};
std::ostream& operator<<(std::ostream& os, const Board& board)
{
    int s = board.size();
	os<<"\t"<<setw(3)<<" ";
	for (int c=0; c<s; ++c)  os<<setw(3)<<c;
    os<<endl;
	for (int r=0;r<s;++r) {
		os<<"\t"<<setw(3)<<r;
		for (int c=0;c<s;++c) os<<setw(3)<<board(r,c);
		os<<endl; 
	}
	return os;
}
class PegSolitaire : public Board 
{
public:
	PegSolitaire() : Board(7)
	{
		this->reset();
	}
	void reset()
	{
		for (int r = 0; r < Board::size(); ++r) {
		    if (r>=2&&r<=4) continue;
			for (int c = 0; c < Board::size(); ++c) {
			    if (c>=2&&c<=4) continue;
				(*this)(r, c) = ' ';
			}
		}
		(*this)(3, 3) = 'o';
	}
	bool move(pair<int, int> p, pair<int, int> h)
	{
	//	This method has 6 checks for invalid moves from the user
		bool foo=true;
		char peg = '.';
		char hole = 'o';
		char spc = ' ';
		//	1.	Check if peg and hole coordinates are the same.
		if( (p.first==h.first)&&(p.second==h.second) ) { foo = false; }
		
		//	2.	Check if peg or hole coordinates lie outside the board.
		else if( (p.first<0||p.first>6) || (h.first<0||h.first>6)) { foo = false; }
		
		//	3.	Check if the move from peg to hole is exactly two jumps away.
		else if( (p.first==h.first) && (p.second>h.second+2) ) { foo = false; }
		else if( (p.first==h.first) && (p.second==h.second+1) ) { foo = false; }
		else if( (p.first==h.first) && (p.second<h.second-2) ) { foo = false; }
		else if( (p.first==h.first) && (p.second==h.second-1) ) { foo = false; }
		else if( (p.first>h.first+2) && (p.second==h.second) ) { foo = false; }
		else if( (p.first==h.first+1) && (p.second==h.second) ) { foo = false; }
		else if( (p.first<h.first-2) && (p.second==h.second) ) { foo = false; }
		else if( (p.first==h.first-1) && (p.second==h.second) ) { foo = false; }
		
		//	4.	Check if peg and hole coordinates move in a line, not diagonaly.
		else if( (p.first!=h.first) && (p.second!=h.second) ) { foo = false; }
		
		while(foo) {
		//	5.	Check if peg is an actual peg or hole is an actual hole.
			if( ((*this)(p.first,p.second) != peg) ||
				((*this)(h.first,h.second) != hole) ) { foo = false; break; }
		//	6.	Check if the element between the peg and hole is actually a peg.
			if ( (p.first==h.first) && (p.second==h.second+2) ) { 
				if ( (*this)(p.first,p.second-1) == peg ) { foo = true; }
				else { foo = false; break; } }
			if ( (p.first==h.first) && (p.second==h.second-2) ) { 
				if ( (*this)(p.first,p.second+1) == peg ) { foo = true; }
				else { foo = false; break; } }
			if ( (p.first==h.first+2) && (p.second==h.second) ) { 
				if ( (*this)(p.first-1,p.second) == peg ) { foo = true; }
				else { foo = false; break; } }
			if ( (p.first==h.first-2) && (p.second==h.second) ) { 
				if ( (*this)(p.first+1,p.second) == peg ) { foo = true; }
				else { foo = false; break; } }
		//	After all checks, moving the peg to a hole is a few if statements
			(*this)(p.first, p.second) = hole;
			(*this)(h.first, h.second) = peg;
			if ( (p.first==h.first) && (p.second<h.second) )
				{	(*this)(p.first, p.second+1) = hole;	}
			else if ( (p.first==h.first) && (p.second>h.second) )
				{	(*this)(p.first, p.second-1) = hole;	}
			else if ( (p.first<h.first) && (p.second==h.second) )
				{	(*this)(p.first+1, p.second) = hole;	}
			else if ( (p.first>h.first) && (p.second==h.second) )
				{	(*this)(p.first-1, p.second) = hole;	}
			break;
		}
	    return foo;
	}
	bool completed() const
	{
		bool foo = false;
		PegSolitaire n;
		for (int r = 0; r < Board::size(); ++r) {
			for (int c = 0; c < Board::size(); ++c) {
					 if (r<2&&c<2) { n(r, c) = ' '; }
				else if (r<2&&c>4) { n(r, c) = ' '; }
				else if (r>4&&c<2) { n(r, c) = ' '; }
				else if (r>4&&c>4) { n(r, c) = ' '; }
				else n(r, c) = 'o';
			}
		}
		n(3, 3) = '.';
		int r = 0, c = 0;
		for (r=0; r < Board::size(); ++r) {
			for (c=0; c < Board::size(); ++c) {
				if ( (*this)(r, c) == n(r,c) ) { foo = true; }
				else { foo = false; break; }
			}
			if(foo==false) break;
		}
		cout<<endl;
		return foo;
	}
};
int main()
{
	PegSolitaire psol;
	pair<int, int> peg, hole;
	int x1,y1,x2,y2;
	int pegsleft = 32;
	int flag = 0;
	int moves = 0;
	ifstream f;
	// Change f.open() to "win1.txt", "win2.txt", or "halt.txt" for different results
	// "win1.txt" and "win2.txt" are files with winning coordinates
	// "halt.txt" contains 6 coordinates which then causes the game to halt 
	f.open("win1.txt");
	do {
		cout<<"There are "<<pegsleft<<" pegs left on the board.\n";
		cout<<"------------------------------------\n";
		cout<<psol;
		// cout<<"\nEnter coordinates: ";
		// replace (f) with (cin) if you want user to input coordinates 
		if (not (f >>x1>>y1>>x2>>y2) ) break;
		cout<<"Coordinates: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
		peg = make_pair(x1,y1);
		hole = make_pair(x2,y2);
		if (not psol.move(peg,hole)) {
			cout << "\nInvalid move.";
			pegsleft++;
			moves--;
		}
		pegsleft--;
		moves++;
		cout<<"\nMoves: "<<moves;
		if (psol.completed()) {
			flag = 1;
			cout<<"\nCongratulations! You have solved the puzzle!\n";
			cout<<"--------------------------------------------\n";
			cout<<psol<<endl;
			cout<<"It only took you "<<moves<<" moves!";
		}
		else flag = 2;
	} while (not psol.completed());
	switch(flag) {
		case 0:
			cout<<"\nMoves: "<<moves;
			cout<<"\nInvalid input. Exiting the game...\n"<<endl;
			break;
		case 2:
			cout<<"\nNo more legal moves. "<<pegsleft<<" pegs left on the board.\n";
			break;
		default:
			break;
	}
	return 0;
}