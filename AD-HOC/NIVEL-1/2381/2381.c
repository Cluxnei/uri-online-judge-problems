#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char names[201][21];
    char aux[21];
    int l, j, n, k;

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    // This is bubble_sort
    for (l = 0; l < n - 1; l++) {
        for (j = 0; j < n - l - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(aux, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], aux);
            }
        }
    }
    
    printf("%s\n", names[k - 1]);
}