#include<iostream>
using namespace std;
int cstr_len(const char cstr[]);
void cstr_append(char a[], const char b[]);
int main() {
    char cs[128] = "The quick brown ";
    cstr_append(cs, "fox");
	return 0;
}
int cstr_len(const char cstr[]) {
	int len = 0;
	while(cstr[len] != '\0')
    len ++;
	return len;
}
void cstr_append(char a[], const char b[]) {
    int lenA = cstr_len(a);
    int lenB = cstr_len(b);
	int size = lenA + lenB;
    char cs[size];
    int i =0,j=0;
    while(a[i]!='\0') {
        cs[i] = a[i];
        cout<<cs[i];
        i++;
    }
    while(b[j]!='\0') {
        cs[i] = b[j];
        cout<<cs[i];
        j++;
    }
}