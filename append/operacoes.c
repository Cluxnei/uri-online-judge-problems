#include "operacoes.h"

#define fori(start, end) for (int i = start, maxi = end; i < maxi; i++)
#define forj(start, end) for (int j = start, maxj = end; j < maxj; j++)
#define fork(start, end) for (int k = start, maxk = end; k < maxk; k++)

void soma(int a[MAX_LINHAS][MAX_COLUNAS], int b[MAX_LINHAS][MAX_COLUNAS], int n_linhas, int n_colunas, int resp[MAX_LINHAS][MAX_COLUNAS])
{
    fori(0, n_linhas)
        forj(0, n_colunas)
            resp[i][j] = a[i][j] + b[i][j];
}

void transposta(int m[MAX_LINHAS][MAX_COLUNAS], int n_linhas, int n_colunas, int resp[MAX_LINHAS][MAX_COLUNAS])
{
    fori(0, n_colunas)
        forj(0, n_linhas)
            resp[i][j] = m[j][i];
}

void concatena_horizontal(int a[MAX_LINHAS][MAX_COLUNAS], int b[MAX_LINHAS][MAX_COLUNAS], int n_linhas, int n_colunas, int resp[MAX_LINHAS][MAX_COLUNAS])
{
    fori(0, n_linhas)
        forj(0, n_colunas)
            resp[i][j] = a[i][j];
    fori(0, n_linhas)
        forj(n_colunas, n_colunas * 2)
            resp[i][j] = b[i][j - n_colunas];
}

void concatena_vertical(int a[MAX_LINHAS][MAX_COLUNAS], int b[MAX_LINHAS][MAX_COLUNAS], int n_linhas, int n_colunas, int resp[MAX_LINHAS][MAX_COLUNAS])
{
    fori(0, n_linhas)
        forj(0, n_colunas)
            resp[i][j] = a[i][j];
    fori(n_linhas, n_linhas * 2)
        forj(0, n_colunas)
            resp[i][j] = b[i - n_linhas][j];
}

void multiplicacao(int a[MAX_LINHAS][MAX_COLUNAS], int b[MAX_LINHAS][MAX_COLUNAS], int n_linhas, int n_colunas, int resp[MAX_LINHAS][MAX_COLUNAS])
{
    fori(0, n_linhas) 
        forj(0, n_colunas) {
            resp[i][j] = 0;
            fork(0, n_linhas) {
                resp[i][j] += a[i][k] * b[k][j];
            }
        }
}