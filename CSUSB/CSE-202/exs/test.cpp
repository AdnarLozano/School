#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Board {
	friend ostream& operator<<(ostream& os, const Board& board);
private:
	vector< vector<char> > data;
	int n;
	char c;
public:
	 Board(int k = 2, char c = '.') {
		n = k;
        for (int i=0;i<n;i++) {
            data.push_back( vector<char>() );
            for (int j=0;j<n;j++) data[i].push_back(c);
		}
	}
	char& operator()(int row, int col) { return data[row][col]; }
	
	const char& operator()(int row, int col) const { return data[row][col]; }
	
	void clear() { for (auto&r : data) r = vector<char>(data.size(),'.'); }
	
	bool operator==(const Board& other) const { return data==other.data; }
	
	bool operator!=(const Board& other) const { return data!=other.data; }
	
};
ostream& operator<<(ostream& os, const Board& board) {
	    os<<"\nGrid (n = "<<board.n<<")";
		for (int i=0; i<board.n; i++)  cout<<" \t"<<i+1;
	    os<<"\n\v";
		for (int i=0;i<board.n;i++) {
			os<<"  "<<i+1<<"  \t";
            for (int j=0;j<board.n;j++) os<<"\t"<<board.data[i][j];
            cout<<endl<<"\v";
		}
		return os;
	}
int main() {
	int row = 1, col=1;
	Board init, A(3,'*'), B(4,'+');
	// creating init
	cout<<"\nCreating and displaying Board init no parameters";
	cout<<init;
	cout<<"Value of element init["<<row<<"]["<<col<<"] = "<<init(row,col)<<"\n";
	// creating A
	cout<<"\nCreating and displaying Board A with parameters n = 3 and c = *";
	cout<<A;
	cout<<"Value of element A["<<row<<"]["<<col<<"] = "<<A(row,col)<<"\n";
	// creating B
	cout<<"\nCreating and displaying Board B with parameters n = 4 and c = +";
	cout<<B;
	cout<<"Value of element B["<<row<<"]["<<col<<"] = "<<B(row,col)<<"\n";
	// Check A==B
	cout<<"\nCheck to see if A == B\nTesting...\n";
	if ( A==(B) ) cout<<"A and B ARE the same\n";
	else cout<<"A and B are NOT the same\n";
	// Clear A
	cout<<"\nSetting all characters in A to '.' and keeping n the same";
	A.clear();
	cout<<A;
	cout<<"Value of element A["<<row<<"]["<<col<<"] = "<<A(row,col)<<"\n";
	// Clear B
	cout<<"\nSetting all characters in B to '.' and keeping n the same";
	B.clear();
	cout<<B;
	cout<<"Value of element B["<<row<<"]["<<col<<"] = "<<B(row,col)<<"\n";
	// Check A==B
	cout<<"\nCheck to see if A == B after been cleared\nTesting...\n";
	if ( A!=(B) ) cout<<"A and B are NOT the same\n";
	else cout<<"A and B ARE the same\n";
	cout<<"\nEven though A and B have the same character '.', "
		<<"they are not the same because they have different n's\n";
	// creating B with n = 3 (same as A)
	cout<<"\nChanging B to have same n as A and displaying B";
	 Board temp(3,'.');
	B = temp;
	cout<<B;
	cout<<"Now B should equal to A\nTesting...\n";
	// check A==B
	if ( A==(B) ) cout<<"A and B ARE the same\n";
	else cout<<"A and B are NOT the same\n";
	return 0;
}