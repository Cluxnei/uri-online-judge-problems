#include "matriz.h"
#include <stdlib.h>

double **cria_matriz(int n_linhas, int n_colunas) {
    double **matriz = (double **)malloc(n_colunas * sizeof(double *));
    for (int i = 0; i < n_linhas; i++) {
        matriz[i] = (double *)malloc(n_colunas * sizeof(double));
        int fill = i % 2 == 0 ? 0 : 1;
        for (int j = 0; j < n_colunas; j++) {
            matriz[i][j] = fill;
            fill = fill == 1 ? 0 : 1;
        }
    }
    return matriz;
}

void liberar_matriz(double **matriz, int n_linhas) {
    for (int i = 0; i < n_linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
