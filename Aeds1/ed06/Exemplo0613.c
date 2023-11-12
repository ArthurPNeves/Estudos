#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


int method01a (int y )
{

    
    if (y > 0 )
    {
        method01a ( y - 1);
        printf ("%d ",7*y);
    }
  if (y == 0)
  {
    printf ("1 ");
  }
  


}

void method00 ( )
{

} 

void method01 ( )
{
  int x;
  
  x = IO_readint ("Digite a quatindade de impares depois do 7 que deseja:\n");
  method01a(x);
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