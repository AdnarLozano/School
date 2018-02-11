#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
class Board {
//friend ostream& operator<<(ostream& os, const Board& board);
private:
	vector< vector<char> > data;
public:
	Board() = delete;
	Board(const Board& other) = default;
	explicit Board(int r, int c) { resize(r, c); }
	tuple<int, int> size() const { return tuple<int, int>(data.size(), data[0].size()); }
	void resize(int r, int c) { data.resize(r); for (auto& r : data) r.resize(c, '.'); }
	
	virtual void clear() { for (auto&r : data) { for (auto&c : r ) c = '.'; } }
	
	char& operator()(int row, int col) { return data[row][col]; }
	const char& operator()(int row, int col) const { return data[row][col]; }
	bool operator==(const Board& other) const { return data==other.data; }
	bool operator!=(const Board& other) const { return data!=other.data; }
};

ostream& operator<<(ostream& os, const Board& board) {
	tuple<int, int> s = board.size();
	for (int r=0;r<get<0>(s);++r) 
	{	for (int c=0;c<get<1>(s);++c) os<<board(r,c)<<' ';
		os<<endl; 
	}
	return os;
}

class TTTBoard : public Board {
public:
	TTTBoard() : Board(3,3) { clear(); }
	void clear() 
	{	auto s = size(); 
		for (int r=0;r<get<0>(s);++r) {
			for (int c=0;c<get<1>(s);++c) operator()(r,c) = '_'; 
		}
	}
};

int main() {
	Board b(4,3);
	cout<<b<<endl;
	b(3,1)= 'X';
	cout<<b<<endl;
	
	b.resize(3,3);
	cout<<b<<endl;
	
	TTTBoard a;
	Board* c = &a;
	cout<<a<<endl;
	c->Board::clear();
	cout<<*c<<endl;
	if ( a==(b) ) cout<<"Same\n";
	else cout<<"Not same\n";
	return 0;
}
	



/*
//		CODE FOR 1 DIMENTIONAL GRID
#include <iostream>
#include <vector>
using namespace std;
class Board {
friend ostream& operator<<(ostream& os, const Board& board);
private:
	vector< vector<char> > data;
public:
	explicit Board(int n) { resize(n); }
	int size() const { return data.size(); }
	void resize(int n) { data.resize(n); for (auto& r : data) r.resize(n, '.'); }
	void clear() { for (auto&r : data) { for (auto&c : r ) c = '.'; } }
	
	
	//	OTHER WAYS TO CLEAR A VECTOR OF VECTOR
	void clear() {
	#1	for (auto&r : data) 
		{	for (auto&c : r ) c = '.'; 
		}
	#2	for (int r = 0; r<size(); ++r) 
		{	for (int c = 0; c< size(); ++c {
				operator()(r,c) = '.';
			}
		}
	#3	for (int r = 0; r<size(); ++r) 
		{	for (int c = 0; c< size(); ++c {
				(*this)(r,c) = '.';
			}
		}
	}
	/// ENDOF OTHE WAYS
	
	char& operator()(int row, int col) { return data[row][col]; }
	const char& operator()(int row, int col) const { return data[row][col]; }
	bool operator==(const Board& other) const { return data==other.data; }
	bool operator!=(const Board& other) const { return data!=other.data; }
};

ostream& operator<<(ostream& os, const Board& board) {
	int n = board.size();
	for (int r=0;r<n;++r) 
	{	for (int c=0;c<n;++c) os<< board(r, c) <<' ';
		os<<endl; 
	}
	return os;
}
int main() {
	Board b(5);
	cout<<b<<endl;
	b(3,1) = 'X';
	cout<<b<<endl;
	b.clear();
	b.resize(7);
	b(5,5) = 'O';
	cout<<b<<endl;
	b.clear();
	cout<<b<<endl;
	return 0;
}
*/

