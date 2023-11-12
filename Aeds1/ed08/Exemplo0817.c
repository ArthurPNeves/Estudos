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

bool decrecente(int lenght, int array[]){
int k = 1;
bool x = false;
while (lenght>k)
{
  if (array[k] < array[k-1])
  {
    x = true;
  }
  else{
    x = false;
  }
  k = k + 1;
}
return(x);
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
    printf("nao e um valor valido ensira novamente");
    x = IO_readint("inisira valor do array positivo :\n");
  }
  
  method01a(x, arranjo);
  if ( decrecente(x,arranjo) == true )
  {
    printf("e decrencente");
  }
  else{
    printf("nao e decrencente");
  }
} 


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