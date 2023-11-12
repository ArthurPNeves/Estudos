#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
const int MAX_SIZE = 100;
int method01a (int lenght, int array []){
int k = 0;
int x = 0;
printf("inisira valor do array:\n");
while (lenght>k)
{
        printf("\n%3d: ", k);
        scanf("%d", &x );
        array[k] = x;
k = k + 1;
}
getchar();
}

void acharmenor(int lenght, int array[]){
int k = 0;
int menor = 0;
menor = array[k];
while (lenght>k)
{
  if (array[k] <= menor)
  {
    menor = array[k];
  }
  k = k + 1;
}
printf ("Menor = %d", menor);
}

int method01b (int lenght, int array []){
    int k = 0;
    while (lenght>k)
    {
        printf("%d: %d\n", k, array[k]);
        k = k + 1;
    }
}


void method00 ( )
{

} 

void method01 ( )
{
  int arranjo [MAX_SIZE];
  int x = 0;
  x = IO_readint("insira o tamanho do array:\n");
  while (x<=0)
  {
    printf("nao é um valor valido ensira novamente");
    x = IO_readint("inisira valor do array positivo :\n");
  }
  
  method01a(x, arranjo);
  method01b(x, arranjo);
  acharmenor(x, arranjo);
} 
// professor eu nao estou conseguindo usar os aquivos


int main ( )
{

 int x = 0; 

 do
 {
 IO_printf ( "\nOpcoes \n" );
 IO_printf ( " 0 - parar   " );
 IO_printf ( " 1 -  \n" );

x = IO_readint ( "Entrar com uma opcao: \n" );

 switch ( x )
 {
 case 0:
 method00 ( );
 break;
 case 1:
 method01 ( );
 break;
 default:
 IO_printf ( "ERRO: Valor invalido." );
 } 

 }
 while ( x != 0 );

 IO_pause ("Apertar ENTER para terminar");
 return (0);
} 