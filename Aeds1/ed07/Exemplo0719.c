#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"


void method01a ( chars fileName )
{

 FILE* arquivo = fopen ( fileName, "rt" );
 chars linha = IO_new_chars ( STR_SIZE );

 strcpy ( linha, IO_freadln ( arquivo ) );

 while ( ! feof (arquivo) &&
 strcmp ( "PARAR", linha ) != 0 )
 {

 printf ( "%s\n", linha );
 
 strcpy ( linha, IO_freadln ( arquivo ) );
 } 
 fclose ( arquivo );
} 


void method00 ( )
{

} 

void method01 ( )
{

  printf ("paredetijolos.txt");

  IO_pause ( "Apertar ENTER para continuar" );
} 





int main ( )
{

 int x = 0; 

 do
 {
 IO_printf ( "\nOpcoes \n" );
 IO_printf ( " 0 - parar   " );
 IO_printf ( " 1 -  contar pares palvras \n" );

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