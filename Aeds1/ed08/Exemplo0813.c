#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
const int MAX_SIZE = 200;
void intArray_init(int superior,int inferior, int lenght, int array[])
{
  int k = 0;
  while (lenght > k)
  {
    do
    {
      array[k] = rand() % 10;
      k = k + 1;
    } while (array[k]>inferior || array[k]<superior);
    
    break;
  }
  
}

void fprint(int lenght, int array[])
{
  int k = 0;
  FILE *arquivo = fopen ("..\\DADOS.TXT", "wt" );
  fprintf(arquivo, "%d\n", lenght);
  while (lenght > k)
  {
    
    fprintf(arquivo,"%d: %d\n", k, array[k]);
    printf ("%d: %d\n", k, array[k]);
    k = k + 1;
  }
  fclose (arquivo);
}

void method00()
{
}

void method01()
{
  int arranjo[MAX_SIZE];
  int x = 0;
  int superior = 0;
  int inferior = 0;
  x = IO_readint("insira o tamanho do array:\n");
  while (x <= 0)
  {
    printf("nao é um valor valido ensira novamente");
    x = IO_readint("inisira valor do array positivo :\n");
  }

  superior = IO_readint("insira o limite superior:\n");
  inferior = IO_readint("insira o limite inferior:\n");
  intArray_init(superior, inferior, x, arranjo);
  fprint(x, arranjo);
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