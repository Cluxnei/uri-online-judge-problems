//Bibliotecas

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <locale.h>

//Variáveis

int destino, origem, vertices = 0;

int custo, *custos = NULL;

//Prototipação

void dijkstra(int vertices, int origem, int destino, int *custos);

void menu_mostrar(void);

void grafo_procurar(void);

void grafo_criar(void);

//Função principal

int main(int argc, char **argv)
{

   int opt = -1;


}

void dijkstra(int vertices, int origem, int destino, int *custos)

{

   int i, v, cont = 0;

   int *ant, *tmp;

   int *z; /* vertices para os quais se conhece o caminho minimo */

   double min;

   double dist[vertices]; /* vetor com os custos dos caminhos */

   /* aloca as linhas da matriz */

   ant = (int *)calloc(vertices, sizeof(int *));

   if (ant == NULL)
   {

      system("color fc");

      printf("** Erro: Memória Insuficiente **");

      exit(-1);
   }

   tmp = (int *)calloc(vertices, sizeof(int *));

   if (tmp == NULL)
   {

      system("color fc");

      printf("** Erro: Memória Insuficiente **");

      exit(-1);
   }

   z = (int *)calloc(vertices, sizeof(int *));

   if (z == NULL)
   {

      system("color fc");

      printf("** Erro: Memória Insuficiente **");

      exit(-1);
   }

   for (i = 0; i < vertices; i++)
   {

      if (custos[(origem - 1) * vertices + i] != -1)
      {

         ant[i] = origem - 1;

         dist[i] = custos[(origem - 1) * vertices + i];
      }

      else
      {

         ant[i] = -1;

         dist[i] = HUGE_VAL;
      }

      z[i] = 0;
   }

   z[origem - 1] = 1;

   dist[origem - 1] = 0;

   /* Laco principal */

   do
   { /* Encontrando o vertice que deve entrar em z */

      min = HUGE_VAL;

      for (i = 0; i < vertices; i++)
      {

         if (!z[i])
         {

            if (dist[i] >= 0 && dist[i] < min)
            {

               min = dist[i];
               v = i;
            }
         }

      } /* Calculando as distancias dos novos vizinhos de z */

      if (min != HUGE_VAL && v != destino - 1)
      {

         z[v] = 1;

         for (i = 0; i < vertices; i++)
         {

            if (!z[i])
            {

               if (custos[v * vertices + i] != -1 && dist[v]

                                                             + custos[v * vertices + i] <
                                                         dist[i])
               {

                  dist[i] = dist[v] + custos[v * vertices + i];

                  ant[i] = v;
               }
            }
         }
      }

   } while (v != destino - 1 && min != HUGE_VAL);

   /* Mostra o Resultado da busca */

   printf("\tDe %d para %d: \t", origem, destino);

   if (min == HUGE_VAL)
   {

      printf("Não Existe\n");

      printf("\tCusto: \t- \n");
   }

   else
   {

      i = destino;

      i = ant[i - 1];

      while (i != -1)
      {

         tmp[cont] = i + 1;

         cont++;

         i = ant[i];
      }

      for (i = cont; i > 0; i--)
      {

         printf("%d -> ", tmp[i - 1]);
      }

      printf("%d", destino);

      printf("\n\tCusto:  %d\n", (int)dist[destino - 1]);
   }
}

void grafo_criar(void)
{

   do
   {

      printf("\nInforme o número de vértices (no minimo 3 ): ");

      scanf("%d", &vertices);

   } while (vertices < 3);

   if (!custos)
   {

      free(custos);
   }

   custos = (int *)malloc(sizeof(int) * vertices * vertices);

   //Se o compilador falhou em alocar espaÃ§o na memÃ³ria

   if (custos == NULL)
   {

      system("color fc");

      printf("** Erro: Memória Insuficiente **");

      exit(-1);

   } //Preenchendo a matriz com -1

   for (int i = 0; i <= vertices * vertices; i++)
   {

      custos[i] = -1;
   }

   do
   {

      system("cls");

      printf("Entre com as Arestas:\n");

      do
      {

         printf("digite a origem (entre 0 e %d ou 00 para sair): ", vertices); // aqui não aceita entrar com aresta inicial zero

         scanf("%d", &origem);

      } while (origem < 0 || origem > vertices);

      if (origem)
      {

         do
         {

            printf("Digite o destino (entre 1 e %d, menos %d): ", vertices, origem);

            scanf("%d", &destino);

         } while (destino < 1 || destino > vertices || destino == origem);

         do
         {

            printf("Digite o custo (positivo) do vértice %d para o vértice %d: ",

                   origem, destino);

            scanf("%d", &custo);

         } while (custo < 0);

         custos[(origem - 1) * vertices + destino - 1] = custo;
      }

   } while (origem);
}

//Busca os menores caminhos entre os vértices

void grafo_procurar(void)
{

   int i, j;

   system("cls");

   system("color 03");

   printf("Lista dos Menores Caminhos no Grafo Dado: \n");

   for (i = 1; i <= vertices; i++)
   {

      for (j = 1; j <= vertices; j++)
      {

         dijkstra(vertices, i, j, custos);
      }

      printf("\n");
   }

   system("pause");

   system("color 07");
}

//Desenha o menu na tela

void menu_mostrar(void)
{

   system("cls");

   printf("Implementação Mapa Estrutura de Dados II, solução com Algoritmo de Dijasktra\n");

   printf("Opcoes:\n");

   printf("\t 1 - Adicionar um Grafo\n");

   printf("\t 2 - Procura Os Menores Caminhos no Grafo\n");

   printf("\t 0 - Sair do programa\n");

   printf("? ");
}
