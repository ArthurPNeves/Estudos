#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (int a, int b){
    double x = 0.0;
    double soma = 0.0;
    printf("Insira os valores:\n");
    while (x!=-1)
    {
        x = IO_readdouble("");
        if ( x>a && x<b && (int)x%2 != 0 & x != 0)
        {
            soma = soma + 1/pow(x,3);
        }
        
    }
    printf("%lf", soma);
}



int main ()
{
    int a = 0;
    int b = 0;
    a=IO_readint("insira a:\n");
    b=IO_readint("insira b:\n");
    funcao(a,b);
    IO_pause ( "Apertar ENTER para continuar" );
    return (0);
}