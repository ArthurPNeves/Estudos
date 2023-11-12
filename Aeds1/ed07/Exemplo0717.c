#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


void method00 ( )
{

} 

int somaex4(int x){
  int y = 0;
  double soma = 0;
  int k = 0;
  FILE *arquivo = fopen ("..\\RESULTADO07.TXT", "wt" );
  k = IO_readint("Insira K:\n");
    while (x>y && k>y)
    {
        printf("\n%lf", 1/pow(3,y));
        fprintf(arquivo, "\n%lf", 1/pow(3,y));
        soma = soma + 1/pow(3,y);
          printf("\nsoma =%lf", soma);
        fprintf(arquivo, "\nsoma = %lf", soma);
        y = y +1;
    }
  while (x>y)
    {
        printf("\n%lf", 1/pow(3,y));
        fprintf(arquivo, "\n%lf", 1/pow(3,y));
        y = y +1;
    }

    fclose (arquivo);
    IO_pause ("Apertar ENTER para terminar");
}
void method01 ( )
{
  int x = 0 ;
  x = IO_readint("insira o numero x:\n");
  somaex4(x);
} 


int main ( )
{

 int x = 0; 

 do
 {
 IO_printf ( "\nOpcoes \n" );
 IO_printf ( " 0 - parar   " );
 IO_printf ( " 1 -  valores multiplos de 7 em ordem crescente \n" );

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