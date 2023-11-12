#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (int n){
    int x = 0;
    int y = 0;
    int z = 0;
    printf("Insira os valores:\n");

    while (n>0)
    {
        scanf("%d", &x);
        printf("%d ",x);
        y = 1;
        z = 0;
        if (x > 0)
        {
        while (y<=x)
        {
            if (x % y == 0)
            {
                z = z + 1;
            }
            else{}
            y = y + 1;
        }
        if (z == 2)
        {
            printf("E primo");
        }
        else
        {
            printf("Nao E primo");
        }
        
        
        printf ("\n");
        n = n - 1;
        }

        else if(x == 0){
                IO_pause("Erro");
        }

        else if (0 > x){
            y = -1;
            while (y>=x)
        {
            if (x % y == 0)
            {
                z = z + 1;
            }
            else{}
            y = y - 1;
        }
        if (z == 2)
        {
            printf("E primo");
        }
        else
        {
            printf("Nao E primo");
        }
        
        
        printf ("\n");
        n = n - 1;
        }
        
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