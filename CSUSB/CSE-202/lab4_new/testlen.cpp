#include<iostream>
using namespace std;
int cstr_len(const char cstr[]);
int main() {
	char cs[128] = "The quick brown fox";
	cout << cstr_len(cs) << endl;
	return 0;
}
int cstr_len(const char cstr[]) {
	int len = 0;
	while(cstr[len] != '\0')
    len ++;
	return len;
}