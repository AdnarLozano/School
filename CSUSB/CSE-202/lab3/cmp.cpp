#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
    string l1, l2, fn1, fn2;
    // cout << "1st filename: ";
    // cin>>fn1;
    // cout << "2nd filename: ";
    // cin>>fn2;
    // fstream fs1(fn1), fs2(fn2);
    fstream fs1("data1.txt"), fs2("data2.txt");
    int byte = 1, line = 1;
    char newline = '\n';
    char c1, c2;
    while ( fs1.get(c1) && fs2.get(c2) ) {
        fs1.clear(), fs2.clear();
        if ( c1 != c2 ) break;
        if (c1 == newline || c2 == newline) line++;
        byte++;
    }
    if (c1!=c2 or fs1.tellg() != fs2.tellg()) {
        cout << "\nDiffer at byte: "<<byte<<", line: "<<line<<endl;
    }
    fs1.clear(), fs2.clear();
    getline(fs1, l1), getline(fs2, l2);
    if (l1.compare(l2) ==0) cout<<"Files are the same"<<endl;
    return 0;
}
