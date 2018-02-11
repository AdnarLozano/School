/*input
7
5 8 1 3 7 9 2
*/
#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector <int>  &ar) {
	int size = ar.size();
	if (size < 2) return;
	vector <int> left;
	vector <int> right;
	int pivot = ar[0];

	for (int i = 1; i < ar.size(); i++) {
		if (ar[i] <= pivot) 
			left.push_back(ar[i]);
		else right.push_back(ar[i]);
	}
	quickSort(left);
	quickSort(right);
	for (int i=0;i<left.size();i++) 
		cout << left[i] << " ";
	cout << pivot << " ";
	for (int i=0;i<right.size();i++) 
		cout << right[i] << " ";
}
int main(void) {
    int n;
    scanf("%d", &n);
    vector <int> ar(n);
    printf("Quick Sort:\n");
    printf("Sample Input:\n");
    printf("7\n");
    printf("5 8 1 3 7 9 2\n");
    printf("Output:\n");
    printf("2 3 \n");
	printf("1 2 3 \n");
	printf("7 8 9 \n");
	printf("1 2 3 5 7 8 9 \n");
    for(int i = 0; i < ar.size(); i++)
        scanf("%d", &ar[i]);
	quickSort(ar);
	cout << endl;
    return 0;
}