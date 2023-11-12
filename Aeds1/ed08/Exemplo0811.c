#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
const int MAX_SIZE = 100;
int method01a (int lenght, int array []){
int k = 0;
int x = 0;
printf("inisira valor do array positivo e par:\n");
while (lenght>k)
{
 do
 {
        printf("\n%3d: ", k);
        scanf("%d", &x );
        array[k] = x;
 } while (x % 2 != 0 || x <= 0);
 
k = k + 1;
}
getchar();
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