#include "vetor.h"
#include <stdlib.h>

int sortAsc(const void *a, const void* b) {
    return (*(int *)a) - *((int*)b);
}

int intercala_vetores(int *v_a, int n_a, int *v_b, int n_b, int **v) {
    const int size = n_a + n_b;
    *v = (int *)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < n_a; i++) {
        (*v)[index++] = v_a[i];
    }
    for (int i = 0; i < n_b; i++) {
        (*v)[index++] = v_b[i];
    }
    qsort(*v, size, sizeof(int), sortAsc);
    return size;
}