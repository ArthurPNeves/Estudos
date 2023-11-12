#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
const int MAX_SIZE = 100;
void intMatrix_scan(int *rows, int *columns,
                    int matrix[][MAX_SIZE])
{
  int x = 0;
  int y = 0;
  int k = 0;
  int m = 0;
  int n = 0;
  printf("\n");
  printf("\nLinhas  = ");
  scanf("%d", &m);
  getchar();
  while (m <= 0)
  {
    printf("\nLinhas  = ");
    scanf("%d", &m);
    getchar();
  }
  printf("\nColunas = ");
  scanf("%d", &n);
  getchar();
  while (n <= 0)
  {
    printf("\nColunas  = ");
    scanf("%d", &n);
    getchar();
  }
  printf("\n");
  for (x = 0; x < m; x = x + 1)
  {
    for (y = 0; y < n; y = y + 1)
    {
      printf("%d, %d: ", x, y);
      scanf("%d", &k);
      matrix[x][y] = k;
    }
    printf("\n");
  }
  printf("\n");
  getchar();
  *rows = m;
  *columns = n;
}

void intMatrix_print(int rows, int columns,
                     int matrix[][MAX_SIZE])
{
  int x = 0;
  int y = 0;

  printf("\n");
  for (x = 0; x < rows; x = x + 1)
  {
    for (y = 0; y < columns; y = y + 1)
    {
      if (columns == rows)
      {
        if (x == y)
        {
          printf("%d\t", matrix[x][y]);
        }
        else
        {
          printf("\t");
        }
      }
    }
    printf("\n");
  }
  printf("\n");
  getchar();
}

void method00()
{
}

void method01()
{
  int matriz[MAX_SIZE][MAX_SIZE];
  int linhas = 0;
  int colunas = 0;

  intMatrix_scan(&linhas, &colunas, matriz);
  printf("\nmatriz %dx%d\n", linhas, colunas);
  intMatrix_print(linhas, colunas, matriz);
  IO_pause("\nApertar ENTER para continuar.\n");
}

int main()
{

  int x = 0;

  do
  {
    IO_printf("\nOpcoes \n");
    IO_printf(" 0 - parar   ");
    IO_printf(" 1 -  \n");

    x = IO_readint("Entrar com uma opcao: \n");

    switch (x)
    {
    case 0:
      method00();
      break;
    case 1:
      method01();
      break;
    default:
      IO_printf("ERRO: Valor invalido.");
    }

  } while (x != 0);

  IO_pause("Apertar ENTER para terminar");
  return (0);
}