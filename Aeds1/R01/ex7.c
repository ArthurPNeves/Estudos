#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (int a, int b){
    double x = 1.0;
    double soma = 0.0;
    double soma2 = 0.0;
    double menora = 0.0;
    double maiorb = 0.0;
    printf("Insira os valores:\n");
    while (x!=0)
    {
        x = IO_readdouble("");
        if ( x>a && x<b )
        {
            soma = soma + 1;
        }
        else{
            soma2 = soma2 + 1;
            if (x<=a)
            {
                menora = menora + 1;
            }
            else if (x>=b)
            {
                maiorb = maiorb + 1;
            }
        }
    }
    printf("%lf\n ", soma);
    printf("%lf\n", soma2);
    printf("%lf\n", menora/soma2);
    printf("%lf\n", maiorb/soma2);
}



int main ()
{
    double a = 0;
    double b = 0;
    a=IO_readdouble("insira a:\n");
    b=IO_readdouble("insira b:\n");
    funcao(a,b);
    IO_pause ( "Apertar ENTER para continuar" );
    return (0);
}