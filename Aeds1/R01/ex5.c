#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (int n){
    double x = 0.0;
    int k = 0;
    int z = 0;
    int l = 0;
    double soma1 = 0;
    double soma2 = 0;
    double soma3 = 0;
    printf("Insira os valores:\n");
    while (n>0)
    {
        x = IO_readdouble("");
        if (x<-23.75)
        {
            soma1 = soma1 + x;
            k = k + 1;
        }
        else if(x>= -23.75 && x<= 65.25)
        {
            soma2 = soma2 + x;
            l = l + 1;
        }
        else if(x> 65.25)
        {
            soma3 = soma3 + x;
            z = z + 1;
        }
        n = n - 1;
    }
    printf ("\nmedia menores -23.75 = %lf\n", soma1/k);
    printf ("\nmedia entre -23.75 e 65.25 = %lf\n", soma2/l);
    printf ("\nmedia maiores 65.25 = %lf\n", soma3/z);
}



int main ()
{
    int n = 0;
    printf("Insira N:\n");
    scanf("%d", &n);
    funcao(n);
    IO_pause ( "Apertar ENTER para continuar" );
    return (0);
}