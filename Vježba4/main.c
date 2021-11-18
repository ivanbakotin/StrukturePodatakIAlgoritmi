#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int *niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

void print(int *niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}   
	printf("\n");
} 

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int checkArrayContains(int *niz, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (niz[i] == element) {
            return 1;
        }
    }

    return 0;
}

int *presjek(int *niz_1, int *niz_2, int n, int *counter){

    int *dupli = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (niz_1[i] == niz_2[j]) {

                int element = niz_1[i];
                int isInside = checkArrayContains(dupli, *counter, element);

                if (!isInside) {
                    dupli[*counter] = niz_1[i];
                    (*counter)++;
                    break;
                }
            }
        }
    }
 
    dupli = (int*)realloc(dupli, *counter);

    return dupli;
}

int *presjek_jedan_sortiran(int *niz_1, int *niz_2, int n, int *counter) {

    int *dupli = (int*)malloc(sizeof(int) * n);

    qsort(niz_2, n, sizeof(int), cmpfunc);

    for (int i = 0; i < n; i++) {

        int *item = (int*) bsearch (&niz_1[i], niz_2, n, sizeof (int), cmpfunc);
       
        if (item) {

            int element = niz_1[i];
            int isInside = checkArrayContains(dupli, *counter, element);

            if (!isInside) {
                dupli[*counter] = niz_1[i];
                (*counter)++;
            }
        }
    }
 
    dupli = (int*)realloc(dupli, *counter);

    return dupli;
}

int *presjek_oba_sortirana(int *niz_1, int *niz_2, int n, int *counter) {

    int *dupli = (int*)malloc(sizeof(int) * n);

    qsort(niz_1, n, sizeof(int), cmpfunc);
    qsort(niz_2, n, sizeof(int), cmpfunc);

    int counter_1 = 0;
    int counter_2 = 0;

    while (counter_1 < n  || counter_2 < n) {

        if (niz_1[counter_1] == niz_2[counter_2]) {

            int element = niz_1[counter_1];
            int isInside = checkArrayContains(dupli, *counter, element);

            if (!isInside) {
                dupli[*counter] = niz_1[counter_1];
                (*counter)++;
            }

            counter_1++;
            counter_2++;
        } else {
            if (niz_1[counter_1] > niz_2[counter_2]) {
                counter_2++;
            } else {
                counter_1++;
            }
        }
    }
 
    dupli = (int*)realloc(dupli, *counter);

    return dupli;
}

void main() {

    int counter = 0;
    int array_size = 10000;

    srand(time(NULL));

	int *niz_1 = generiraj(array_size);
    int *niz_2 = generiraj(array_size);

    shuffle(niz_1, array_size);
    shuffle(niz_2, array_size);

    //int *presjek_1 = presjek(niz_1, niz_2, array_size, &counter);

    //int *presjek_2 = presjek_jedan_sortiran(niz_1, niz_2, array_size, &counter);

    int *presjek_3 = presjek_oba_sortirana(niz_1, niz_2, array_size, &counter);

    print(presjek_3, counter);
}
