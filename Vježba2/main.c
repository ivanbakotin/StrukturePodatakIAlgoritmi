#include <stdio.h>
#include <stdlib.h>

int *podniz(int *niz, int start, int stop) {
  
    int *new_array = (int*)malloc(sizeof(int) * (stop - start));

    for (int i = 0; start < stop; start++, i++) {
        new_array[i] = niz[start];
    }

    return new_array;
}

int *filtriraj(int *niz, int n, int th, int *nth) {

    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] < th) counter++;
    }

    *nth = counter;

    int *new_array = (int*)malloc(sizeof(int) * (*nth));

    for (int i = 0, j = 0; i < n; i++) {
        if (niz[i] < th) {
            new_array[j] = niz[i];
            j++;
        }
    }

    return new_array;
}

int **podijeli(int *niz, int n) {

    int** two_arrays;
	int len1 = n / 2;
	int len2 = n - len1;

	int* array_1 = (int*)malloc(sizeof(int) * len1);
	int* array_2 = (int*)malloc(sizeof(int) * len2);
	two_arrays = (int**)malloc(sizeof(int*) * 2);

	for (int i = 0; i < len1; i++) {
		array_1[i] = niz[i];
	}

    for (int i = 0; len1 < n; len1++, i++) {
        array_2[i] = niz[len1];
    }

	two_arrays[0] = array_1;
	two_arrays[1] = array_2;

	return two_arrays;
}

void main() {

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int array_size = sizeof(array) / sizeof(array[0]);




    //int start = 2;
    //int stop = 6;

    //int *new_array = podniz(array, start, stop);

    //for (int i = 0; i < stop - start; i++) {
    //    printf("%d\n", new_array[i]);
    //}

    //free(new_array);




    //int nth, th;
    //th = 5;

    //int *new_array = filtriraj(array, array_size, th, &nth);

    //for (int i = 0; i < nth; i++) {
    //    printf("%d\n", new_array[i]);
    //}

    //free(new_array);





    int **new_array = podijeli(array, array_size);

    for (int i = 0; i < 2; i++) {
		free(new_array[i]);
	}

	free(new_array);
}
