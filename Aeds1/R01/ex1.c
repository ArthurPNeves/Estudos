#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (int n){
    int x = 0;
    int y = 0;
    printf("Insira os valores:\n");
    while (n>0)
    {
        scanf("%d", &x);
        printf("%d =",x);
        y = 1;
        while (y<=x)
        {
            if (x % y == 0)
            {
                printf("%d ", y);
                
            }
            else{}
            y = y + 1;
        }
        printf ("\n");
        n = n - 1;
    }
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