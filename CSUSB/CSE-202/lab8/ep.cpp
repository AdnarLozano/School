#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Board {
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
	for (int r = 0; r < s; ++r) {
		for (int c = 0; c < s; ++c) {
			os << board(r, c) << ' ';
		}
		os << std::endl;
	}
	return os;
}

class EightPuzzle : public Board {
public:
	EightPuzzle() : Board(3)
	{
		this->reset();
	}
	void reset()
	{
		char t = '1';
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				(*this)(r, c) = t++;
			}
		}
		(*this)(2, 2) = ' ';
	}
	void shuffle()
	{
		std::default_random_engine prng(std::random_device{}());
		std::array<char, 9> a;
		char t = '1';
		std::generate_n(a.begin(), 8, [&](){ return t++; });
		a[8] = ' ';
		std::shuffle(a.begin(), a.end(), prng);
		auto it = a.begin();
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				(*this)(r, c) = *it++;
			}
		}
	}
	bool move(char dir)
	{
		bool foo = false;
		tuple<int, int> space;
		tuple<int, int> temp;
		char num; 
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				if ( (*this)(r, c) == ' ' ) {
					space = make_tuple (r,c);
					break;
				}
			}
		}
		char spc = (*this)(get<0>(space),get<1>(space));
		
		switch (dir) 
	    {
	        case 'w' :
	        	get<0>(temp) = get<0>(space)-1;
	        	get<1>(temp) = get<1>(space);
	        	if (get<0>(temp)>=0&&get<0>(temp)<=2) {
		        	num = (*this)(get<0>(temp),get<1>(temp));
		        	(*this)(get<0>(temp),get<1>(temp)) = spc;
		        	(*this)(get<0>(space),get<1>(space)) = num;
		        	foo = true;
	        	}
	            else foo = false; 
	            break;
	        case 'a' :
	        	get<0>(temp) = get<0>(space);
	        	get<1>(temp) = get<1>(space)-1;
	        	if (get<1>(temp)>=0&&get<1>(temp)<=2) {
		        	num = (*this)(get<0>(temp),get<1>(temp));
		        	(*this)(get<0>(temp),get<1>(temp)) = spc;
		        	(*this)(get<0>(space),get<1>(space)) = num;
        			foo = true;
	        	}
	            else foo = false; 
	            break;
	        case 's' :
	        	get<0>(temp) = get<0>(space)+1;
	        	get<1>(temp) = get<1>(space);
	        	if (get<0>(temp)>=0&&get<0>(temp)<=2) {
		        	num = (*this)(get<0>(temp),get<1>(temp));
		        	(*this)(get<0>(temp),get<1>(temp)) = spc;
		        	(*this)(get<0>(space),get<1>(space)) = num;
        			foo = true;
	        	}
	            else foo = false; 
	            break;
	        case 'd' :
	        	get<0>(temp) = get<0>(space);
	        	get<1>(temp) = get<1>(space)+1;
	        	if (get<1>(temp)>=0&&get<1>(temp)<=2) {
		        	num = (*this)(get<0>(temp),get<1>(temp));
		        	(*this)(get<0>(temp),get<1>(temp)) = spc;
		        	(*this)(get<0>(space),get<1>(space)) = num;
        			foo = true;
	        	}
	            else foo = false; 
	            break;
			default:
	            foo = false;
	            break;
	    }
	    return foo;
	}
	bool completed() const
	{
		EightPuzzle n;
		int num_same=0;
		bool foo = false;
		int r = 0, c = 0;
		for (r=0; r < 3; ++r) {
			for (c=0; c < 3; ++c) {
				if ( (*this)(r, c) == n(r,c) ) {
					foo = true;
					cout<<"same, ";
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
		if (num_same==9) {
			for (int r = 0; r < 3; ++r) {
				for (int c = 0; c < 3; ++c) {
					cout<<(*this)(r, c)<<" ";
			}
			cout<<endl;
		}
			cout<<"You win!\n";
		}
		return foo;
	}
};

int main()
{
	EightPuzzle ep;
	char dir;
	int moves = 0;
	ep.shuffle();
	do {
		cout << ep << endl;
		if (not (cin >> dir)) break;
		if (not ep.move(dir)) {
			cout << "Invalid move." << endl;
		}
		moves++;
		cout<<"moves: "<<moves<<endl;
	} while (not ep.completed());
	return 0;
}
