#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void method01a (int y, int x )
{
    if (y > 0)
    {
        method01a ( y - 1, x + 7 + (2*(y-1)) );
        if (y == 5)
        {
            printf ("%d ", 7 + (2*(y-1)));
        }
        else{
        printf ("%d + ", 7 + (2*(y-1)));
        }
    }

        if (y == 0)
    {
        printf ("%d =  ", x);
    }
    
} 

void method00 ( )
{

} 

void method01 ( )
{
  int y;
  
  y = IO_readint ("Digite a quatindade de impares depois do 7 que deseja:\n");
  method01a(y,0);
   IO_pause ( "Apertar ENTER para continuar" );
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