#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (char x[], char y[], char z[]){


    if  (strcmp(y,x) < 0  && strcmp(y,z) > 0)
    {
        printf("Oredem decrecente\n");
    }
    else if( strcmp(y,z) < 0  && strcmp(y,x) > 0)
    {
        printf("Oredem crecente\n");
    }
    else
    {
        printf("nao tem ordem\n");
    }
    
// nao consegui fazer
}



int main ()
{
    char x [2];
    char y [2];
    char z [2];
    scanf("%s", x);
    scanf("%s", y);
    scanf("%s", z);
    funcao(x,y,z);
    IO_pause ( "Apertar ENTER para continuar" );
    return (0);
}