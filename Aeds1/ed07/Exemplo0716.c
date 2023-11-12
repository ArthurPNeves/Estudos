#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


void method00 ( )
{

} 

int somaelevadosa5(int x){
  int y = 0;
  double soma = 0;
  double n = 0;
  int k = 0;
  FILE *arquivo = fopen ("..\\RESULTADO06.TXT", "wt" );
  n = IO_readdouble("insira o numero n:\n");
  k = IO_readint("Insira K:\n");
    while (x>y && k>y)
    {
        printf("\n%lf", 1/pow(n,y));
        fprintf(arquivo, "\n%lf", 1/pow(n,y));
        soma = soma + 1/pow(n,y);
          printf("\nsoma =%lf", soma);
        fprintf(arquivo, "\nsoma = %lf", soma);
        y = y +1;
    }
  while (x>y)
    {
        printf("\n%lf", 1/pow(n,y));
        fprintf(arquivo, "\n%lf", 1/pow(n,y));
        y = y +1;
    }

    fclose (arquivo);
    IO_pause ("Apertar ENTER para terminar");
}
void method01 ( )
{
  int x = 0 ;
  x = IO_readint("insira o numero x:\n");
  somaelevadosa5(x);
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