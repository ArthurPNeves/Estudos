#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


void method00 ( )
{

} 

void method01 ( )
{
  int x = 0 ;
  FILE *arquivo = fopen ("..\\ex0712.TXT", "wt" );
  x = IO_readint("insira o numero:\n");
    while (x>0)
    {
        printf("\n%d", x*6);
        fprintf(arquivo, "\n%d", x*6);
        x = x -1;

    }
    fclose (arquivo);
    IO_pause ("Apertar ENTER para terminar");
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