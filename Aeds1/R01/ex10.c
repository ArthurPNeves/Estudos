#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (char x[]){
    int a = 0;
    int b = 0;
    int c = 0;
    a = strlen(x);

    bool teste = true;
    if (strcmp(x[a],x[0]) > 0)
    {
        teste = true;
        while (a>=0)
    {
        if (strcmp(x[a],x[a-1]) > 0 || strcmp(x[a],x[a-1]) == 0 )
        {
            teste = true;
        }
        else{
            teste = false;
        }
        if (teste = false )
        {
            printf ("nenhuma das ordens");
            break;
        }
        a = a -1;
    }
        if (a == 0)
    {
        printf ("crecente");
    }
    }




        a = strlen(x);
        if (strcmp(x[a],x[0]) < 0)
    {
        teste = false;
        while (a>=0)
    {
        if (strcmp(x[a],x[a-1]) < 0 || strcmp(x[a],x[a-1]) == 0 )
        {
            teste = false;
        }
        else{
            teste = true;
        }
        if (teste = true )
        {
            printf ("nenhuma das ordens");
            break;
        }
        a = a -1;
    }
    }
    if (a == 0)
    {
        printf ("decrescente");
    }

    

    

}



int main ()
{
    char x [80];
    char y [80];
    char z [80];
    scanf("%s", x);
    funcao(x);
    IO_pause ( "Apertar ENTER para continuar" );
    return (0);
}

// nao consgui fazer