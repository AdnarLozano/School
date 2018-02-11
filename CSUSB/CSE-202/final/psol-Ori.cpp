#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <algorithm>
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
	os<<setw(2)<<" ";
	for (int c=0; c<s; ++c)  os<<setw(2)<<c;
    os<<endl;
	for (int r=0;r<s;++r) {
		os<<setw(2)<<r;
		for (int c=0;c<s;++c) os<<setw(2)<<board(r,c);
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
	bool move(tuple<int, int> p, tuple<int, int> h)
	{
		bool foo=true;
		char peg = '.';
		char hole = 'o';
		if( p == h ) { foo = false; }
		else if( (get<0>(p)>=0&&get<0>(p)<2) && (get<0>(p)>4&&get<0>(p)<7) ) { foo = false; }
		else if( (get<0>(h)>=0&&get<0>(h)<2) && (get<0>(h)>4&&get<0>(h)<7) ) { foo = false; }
		while(foo) {
			if( (*this)(get<0>(p),get<1>(p)) == hole) { foo = false; break;}
			if( (*this)(get<0>(h),get<1>(h)) == peg) { foo = false; break;}
			(*this)(get<0>(p), get<1>(p)) = hole;
			(*this)(get<0>(h), get<1>(h)) = peg;
			if ( (get<0>(p)==get<0>(h)) && (get<1>(p)<get<1>(h)) )
				{	(*this)(get<0>(p), get<1>(p)+1) = hole;	}
			else if ( (get<0>(p)==get<0>(h)) && (get<1>(p)>get<1>(h)) )
				{	(*this)(get<0>(p), get<1>(p)-1) = hole;	}
			else if ( (get<0>(p)<get<0>(h)) && (get<1>(p)==get<1>(h)) )
				{	(*this)(get<0>(p)+1, get<1>(p)) = hole;	}
			else if ( (get<0>(p)>get<0>(h)) && (get<1>(p)==get<1>(h)) )
				{	(*this)(get<0>(p)-1, get<1>(p)) = hole;	}
			break;
		} 
	    return foo;
	}
	// void display_Completed() 
	// {
	// 	for (int r = 0; r < Board::size(); ++r) {
	// 		for (int c = 0; c < Board::size(); ++c) {
	// 			if (r<2&&c<2) { (*this)(r, c) = ' '; }
	// 			else if (r<2&&c>4) { (*this)(r, c) = ' '; }
	// 			else if (r>4&&c<2) { (*this)(r, c) = ' '; }
	// 			else if (r>4&&c>4) { (*this)(r, c) = ' '; }
	// 			else (*this)(r, c) = 'o';
	// 		}
	// 	}
	// }
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
		
		int num_same=0;
		int r = 0, c = 0;
		for (r=0; r < Board::size(); ++r) {
			for (c=0; c < Board::size(); ++c) {
				if ( (*this)(r, c) == n(r,c) ) {
					foo = true;
					num_same++;
				}
				else { 
					foo = false;
					break;
				}
			}
			if(foo==false) break;
		}
		cout<<endl;
		if (num_same==49) {
			cout<<"You win!\n";
		}
		return foo;
	}
};

int main()
{
	PegSolitaire psol;
	tuple<int, int> peg, hole;
	int x1,x2,y1,y2;
	int moves = 32;
	do {
		cout << psol << endl;
		if (not (cin >>x1>>x2>>y1>>y2) ) break;
		peg = make_tuple(x1,x2);
		hole = make_tuple(y1,y2);
		if (not psol.move(peg,hole)) {
			cout << "Invalid move." << endl;
		}
	} while (not psol.completed());
	return 0;
}
