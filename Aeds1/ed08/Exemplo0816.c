#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
const int MAX_SIZE = 100;
int method01a(int lenght, int array[])
{
  int k = 0;
  int x = 0;
  printf("inisira valor do array:\n");
  while (lenght > k)
  {
    printf("\n%3d: ", k);
    scanf("%d", &x);
    array[k] = x;
    k = k + 1;
  }
  getchar();
}

int media(int lenght, int array[])
{
  int k = 0;
  double media = 0;
  while (lenght > k)
  {
    media = media + array[k];
    k = k + 1;
  }
  media = media / lenght;
  return(media);
}

void maioresEmenores(double media, int lenght, int array[]){
  int k = 0;
  int a =0;
  int b=0;
  int c=0;
  int d=0;
  int e=0;
  int f=0;
  int arraymaior[MAX_SIZE];
  int arraymenor[MAX_SIZE];
  int arrayigual[MAX_SIZE];
  while (lenght > k)
  {
    if (array[k] > media)
    {
      arraymaior[a] = array[k];
      a = a + 1;
    }
    else if(array[k] < media){
      arraymenor[b] = array[k];
      b = b + 1;
    }
    else if(array[k] == media){
      arrayigual[c] = array[k];
      c = c + 1;
    }
    k = k + 1;
  }

  while (a > d )
  {
    printf("maior que media %d: %d\n", d, arraymaior[d]);
    d = d + 1;
  }
  while (b > e)
  {
    printf("menor que media %d: %d\n", e, arraymenor[e]);
    e = e + 1;
  }
  while (c > f)
  {
    printf("igual que media %d: %d\n", f, arrayigual[f]);
    f = f + 1;
  }
}

int method01b(int lenght, int array[])
{
  int k = 0;
  while (lenght > k)
  {
    printf("%d: %d\n", k, array[k]);
    k = k + 1;
  }
}

void method00()
{
}

void method01()
{
  int arranjo[MAX_SIZE];
  int x = 0;
  x = IO_readint("insira o tamanho do array:\n");
  while (x <= 0)
  {
    printf("nao é um valor valido ensira novamente");
    x = IO_readint("inisira valor do array positivo :\n");
  }

  method01a(x, arranjo);
  maioresEmenores(media(x,arranjo), x, arranjo);
}

int main()
{

  int x = 0;

  do
  {
    IO_printf("\nOpcoes \n");
    IO_printf(" 0 - parar   ");
    IO_printf(" 1 - \n");

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