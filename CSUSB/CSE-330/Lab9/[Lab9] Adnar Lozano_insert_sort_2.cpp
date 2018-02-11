/*input
6
1 4 3 5 6 2
*/
#include <iostream>
using namespace std;

void insertionSort(int ar_size, int *  ar) {
	for (int i = 1; i < ar_size; i++) {
		int value = ar[i];
		int temp = i;
		while (temp > 0 && ar[temp-1] > value) {
			ar[temp] = ar[temp-1];
			temp = temp-1;
		}
		ar[temp] = value;
		for (int k = 0; k < ar_size; ++k)
			printf("%d ", ar[k]);
		printf("\n");
	}
}
int main(void) {
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	printf("Insert Sort 2\n");
    printf("Sample Input:\n");
    printf("6\n");
    printf("1 4 3 5 6 2\n");
    printf("Output:\n");
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)
		scanf("%d", &_ar[_ar_i]); 
	insertionSort(_ar_size, _ar);
	return 0;
}
