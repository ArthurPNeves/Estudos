#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

int method01a (int y )
{
    int resultado;
    int c = 1;
    while (0<y)
    {
       IO_printf (" %d ",7*c);
        y = y -1;
        c = c +1;
        
    }
    
    resultado = y ;
    return (resultado);
} 

int method02a (int y )
{
    int resultado;
    int c = 1;
    while (0<y)
    {
 
      if (c*7 % 2 == 0)
      {
        IO_printf (" %d ",7*c);
        y = y -1;
        c = c +1;
      }
      else
      {
        
        c = c +1;
      }

    }
    
    resultado = y ;
    return (resultado);
} 

int method03a (int y )
{
    int resultado;
    int c = y*2;
    while (0<y)
    {
 
      if (c*7 % 2 == 0)
      {
      c = c -1;
      }
      else
      {
        IO_printf (" %d ",7*c);
        y = y -1;
        c = c -1;
        
      }

    }
    
    resultado = y ;
    return (resultado);
} 

int method04a (int y )
{
    int resultado;
    int c = 1;
    while (0<y)
    {
       IO_printf (" 1/%d ",(7*c));
        y = y -1;
        c = c +1;
        
    }
    
    resultado = y ;
    return (resultado);
} 

int method05a (int y )
{
    int resultado;
    double c = 0;
    double x = IO_readint ("Insira o valor da base do denominador:\n");
    while (0<y)
    {
    if (c == 0)
    {
        IO_printf ("1 ");
                y = y -1;
        c = c +1;
    }
    
    else{
       IO_printf (" 1/%lf ", pow(x,c));
        y = y -1;
        c = c +1;
    }
    }
    
    resultado = y ;
    return (resultado);
} 

void method00 ( )
{

} 

void method01 ( )
{
  int x;
  
  x = IO_readint ("Digite a quatindade de multiplos de 7 que deseja:\n");
  method01a(x);
   IO_pause ( "Apertar ENTER para continuar" );
} 

void method02 ( )
{
  int x;
  
  x = IO_readint ("Digite a quatindade de multiplos de 7 pares que deseja:\n");
  method02a(x);
   IO_pause ( "Apertar ENTER para continuar" );
} 

void method03 ( )
{
  int x;
  
  x = IO_readint ("Digite a quatindade de multiplos de 7 impares na ordem decrecente que deseja:\n");
  method03a(x);
   IO_pause ( "Apertar ENTER para continuar" );
} 

void method04 ( )
{
  int x;
  
  x = IO_readint ("Digite a quatindade de divisoes  de 1 pelos multiplos de 7 que deseja:\n");
  method04a(x);
   IO_pause ( "Apertar ENTER para continuar" );
} 

void method05 ( )
{
    int x;

  x = IO_readint ("Digite quantas vezes deseja repetir o processo:\n");
  method05a(x);
   IO_pause ( "Apertar ENTER para continuar" );
} 

void method06 ( )
{

} 

void method07 ( )
{

} 

void method08 ( )
{

}

void method09 ( )
{

} 

void method10 ( )
{

} 




int main ( )
{

 int x = 0; 

 do
 {
 IO_printf ( "\nOpcoes \n" );
 IO_printf ( " 0 - parar   " );
 IO_printf ( " 1 -  valores multiplos de 7 em ordem crescente \n" );
 IO_printf ( " 2 -  multiplos de 7 pares:" );
 IO_printf ( " 3 -  multiplos de 7 impares na ordem decrecente:\n" );
 IO_printf ( " 4 -  divisoes  de 1 pelos multiplos de 7:" );
 IO_printf ( " 5 -  1/x^^y\n" );
 IO_printf ( " 6 -   " );
 IO_printf ( " 7 - \n" );
 IO_printf ( " 8 -   " );
 IO_printf ( " 9 - \n" );
 IO_printf ( " 10 - \n" );
 IO_printf ( "" );

x = IO_readint ( "Entrar com uma opcao: \n" );

 switch ( x )
 {
 case 0:
 method00 ( );
 break;
 case 1:
 method01 ( );
 break;
 case 2:
 method02 ( );
 break;
 case 3:
 method03 ( );
 break;
 case 4:
 method04 ( );
 break;
 case 5:
 method05 ( );
 break;
 case 6:
 method06 ( );
 break;
 case 7:
 method07 ( );
 break;
 case 8:
 method08 ( );
 break;
 case 9:
 method09 ( );
 break;
 case 10:
 method10 ( );
 break;
 default:
 IO_printf ( "ERRO: Valor invalido." );
 } 

 }
 while ( x != 0 );

 IO_pause ("Apertar ENTER para terminar");
 return (0);
} 