#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

int funcao (char palavra[], int tamanho )
{
    int i = 0;
    int contador = 0;
    if (tamanho > i )
    {

        if (palavra[tamanho] >= '0' && palavra[tamanho] <= '9' )
        {
            if (palavra[tamanho] % 2 == 0)
            {
                contador = 1;
            }

            
        }
        contador = contador + funcao(palavra, tamanho -1);
    }
    
    return(contador);
} 

void method00 ( )
{

} 

void method01 ( )
{

    char palavra [80];
   strcpy(palavra, "12345688");
    printf("%d", funcao(palavra, strlen(palavra)));

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