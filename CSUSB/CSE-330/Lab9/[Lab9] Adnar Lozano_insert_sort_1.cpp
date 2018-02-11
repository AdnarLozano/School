/*input
2
3 1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int ar_size, int * ar) {
    for (int i = 1; i < ar_size; i++) {
        int value = ar[i];
        int temp = i - 1;

        printf("ar[i=%d]: %d  ", i, ar[i]);
        printf("temp: %d  ", temp);
        printf("ar[temp]: %d  \n", ar[temp]);

        while (temp >= 0 && value < ar[temp]) {
            ar[temp+1] = ar[temp];
            printf("\nar[tmp=%d]: %d  \n", temp, ar[temp]);
            temp--;
            for (int k=0; k < ar_size; k++)
                printf("%d ", ar[k]);
            printf("\n");
        }
        ar[temp+1] = value;
    }
    for(int j = 0; j < ar_size; j++)
        printf("%d ", ar[j]);
    printf("\n\n");
}
int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;

        // printf("Insert Sort 1\n");
        // printf("Sample Input:\n");
        // printf("5\n");
        // printf("2 4 6 8 3\n");
        // printf("Output:\n");

    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)
        scanf("%d", &_ar[_ar_i]);

    insertionSort(_ar_size, _ar);
    return 0;
}