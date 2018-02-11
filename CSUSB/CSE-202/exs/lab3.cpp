#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// /* wc.cpp
int main() {
    ifstream fs;
    string filename, line, word;
    int line_Count = 0, word_Count = 0, char_Count = 0;
    
    getline(cin, filename);
    fs.open(filename);
    while (getline(fs, line)) {
        ++line_Count;
        stringstream ss(line);
        while (ss >> word) {
            word_Count++;
            if (word == "\n") continue;
            char_Count += word.length();
        }
    }
    cout<<line_Count<<"\t"<<word_Count<<"\t"<<char_Count<<endl;
// */

/* sort.cpp
int main() {
    ifstream fs;
    string fn, line;
    vector<string> v;
    
    getline(cin, fn);
    fs.open(fn);
    while(getline(fs, line)){
        v.push_back(line);
    }
    fs.close();
    sort(v.begin(), v.end());
    for (string s : v) cout <<s<<endl;
*/

/* cmp.cpp
int main() {
    string l1, l2, fn1, fn2;
    // cout << "1st filename: ";
    // cin>>fn1;
    // cout << "2nd filename: ";
    // cin>>fn2;
    //fstream fs1, fs2;
    fstream fs1("data1.txt"), fs2("data2.txt");
    int byte = 1, line = 1;
    char c1, c2;
    while ( true ) {
        if (not fs1.get(c1)) { fs1.clear(); break; }
        if (not fs2.get(c2)) { fs2.clear(); break; }
        if ( c1 != c2 ) break; 
        if (c1 == '\n' || c2 == '\n') line++;
        byte++;
    }
    if (c1 != c2 or fs1.tellg() != fs2.tellg() ) {
        cout << "Files differ at byte: "<<byte<<", line: "<<line<<endl;
    }
    fs1.clear(), fs2.clear();
    getline(fs1, l1), getline(fs2, l2);
    if (l1.compare(l2) ==0) cout<<"Files are the same"<<endl;
*/
    return 0;
}
