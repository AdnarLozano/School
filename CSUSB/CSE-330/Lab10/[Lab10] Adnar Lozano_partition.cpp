/*input
5
4 5 3 7 2
*/
#include <iostream>
#include <vector>
using namespace std;

void partition(int ar_size, int *  ar) {
	int pivot = ar[0];
	vector <int> left;
	vector <int> right;
	for (int i = 1; i < ar_size; i++) {
		if (pivot <= ar[i]) 
			right.push_back(ar[i]);
		else left.push_back(ar[i]);
	}
	for (int i=0;i<left.size();i++)
		cout << left[i] << " ";
	cout << pivot << " ";
	for (int i=0;i<right.size();i++)
		cout << right[i] << " ";
}
int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
	printf("Partition:\n");
    printf("Sample Input:\n");
    printf("5\n");
    printf("4 5 3 7 2\n");
    printf("Output:\n");
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)
        scanf("%d", &_ar[_ar_i]);
	partition(_ar_size, _ar);
	cout << endl;
    return 0;
}