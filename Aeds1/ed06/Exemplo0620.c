#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

int method01a ( char y [], int x )
{
    if (x > 0 )
    {
        if (y[x]>= 'A' && 'Z'>=y[x] )
    {  
        return method01a ( y, x - 1) + 1;
    }
    else{
        return method01a ( y, x - 1);
    }
    }
    
} 

void method00 ( )
{

} 

void method01 ( )
{
  char y[80];
  printf ("Palavra = ");
  scanf ("%s" , y);
  printf ("%d", method01a(y, strlen(y)));

  IO_pause ( "Apertar ENTER para continuar" );
} 





int main ( )
{

 int x = 0; 

 do
 {
 IO_printf ( "\nOpcoes \n" );
 IO_printf ( " 0 - parar   " );
 IO_printf ( " 1 -  contar maisculos palavra \n" );

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