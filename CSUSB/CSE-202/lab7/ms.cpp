#include <iostream>
#include <vector>
#include <tuple>
#include <random>
#include <iomanip>
using namespace std;

class Board {
friend ostream& operator<<(ostream& os, const Board& board);
private:
	vector< vector<char> > data;
public:
	Board() = delete;
	Board(const Board& other) = default;
	explicit Board(int r, int c) { resize(r,c); }
	tuple<int, int> size() const { 
		return tuple<int, int>(data.size(), data[0].size()); }
	void resize(int r, int c) { 
		data.resize(r); for (auto& r : data) r.resize(c, '.'); }
	virtual void clear() { for (auto&r : data) { for (auto&c : r ) c = '.'; } }
	char& operator()(int row, int col) { return data[row][col]; }
	const char& operator()(int row, int col) const { return data[row][col]; }
	bool operator==(const Board& other) const { return data==other.data; }
	bool operator!=(const Board& other) const { return data!=other.data; }
};

ostream& operator<<(ostream& os, const Board& board) {
	tuple<int, int> s = board.size();
	os<<setw(3)<<" ";
	for (int c=0; c<get<1>(s); ++c)  os<<setw(3)<<c;
    os<<endl;
	for (int r=0;r<get<0>(s);++r) {
		os<<setw(3)<<r;
		for (int c=0;c<get<1>(s);++c) os<<setw(3)<<board(r,c);
		os<<endl; 
	}
	return os;
}

class Minesweeper : public Board {
private:
	vector< tuple<int, int> > mytuple;
public:
	Minesweeper() : Board(5,5) {
		auto s = size();
		cout <<"4 Random Mines at:\n";
		for (int i=0; i<4;i++) {
		    default_random_engine prng(random_device{}());
		    uniform_int_distribution<int> dist(0, get<0>(s)-1);
		    int r = dist(prng);
		    int c = dist(prng);
			tuple<int, int> v = make_tuple (r,c);
		    mytuple.push_back(v);
			cout<<i+1<<" = ("<<get<0>(v)<<", "<<get<1>(v)<<")"<<endl;
		}
	}
	
	void reveal(int row, int col) {
		auto m = make_tuple(row, col);
			if ( get<0>(m) ==  get<0>(mytuple[0]) && 
				get<1>(m) ==  get<1>(mytuple[0])) {
				operator()(row,col) = 'M';
			}
			else if ( get<0>(m) ==  get<0>(mytuple[1]) 
				&& get<1>(m) ==  get<1>(mytuple[1])) { 
				operator()(row,col) = 'M'; 
			}
			else if ( get<0>(m) ==  get<0>(mytuple[2]) && 
				get<1>(m) ==  get<1>(mytuple[2])) { 
				operator()(row,col) = 'M'; 
			}
			else if ( get<0>(m) ==  get<0>(mytuple[3]) && 
				get<1>(m) ==  get<1>(mytuple[3])) { 
				operator()(row,col) = 'M'; 
			}
			else { operator()(row,col) = 'C'; }
	}
};

int main () {
	Minesweeper ms;
	int row, col;
	int guesses = 0;
	
	while (guesses < 21) {
		cout << ms << endl;
		cout << "Enter row and column: ";
		cin >> row >> col;
		ms.reveal(row, col);
		if (ms(row, col) == 'M') break;
		++guesses;
	}
	cout << ms << endl;
	return 0;
}