#include <stdio.h>
#include <string.h>

int *podniz(int *niz, int start, int stop) {
    int *new_array = malloc(stop - start);

    for (int i = 0; start < stop; start++, i++) {
        new_array[i] = niz[start];
    }

    return new_array;
}

int* filtriraj(int *niz, int n, int th, int *nth) {
    nth = malloc(n);

    for (int i = 0, j = 0; i < n; i++) {
        if (niz[i] < th) {
            nth[j] = niz[i];
            j++;
        }
    }

    return nth;
}

int** podijeli(int *niz, int n) {

}

void main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int start = 2;
    int stop = 6;

    //int *new_array = podniz(array, start, stop);

    //for (int i = 0; i < stop - start; i++) {
    //    printf("%d\n", new_array[i]);
    //}

    //int *nth = filtriraj(array, 10, 5, nth);

    //for (int i = 0; i < 4; i++) {
    //    printf("%d\n", nth[i]);
    /7}
}
