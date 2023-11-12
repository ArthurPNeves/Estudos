#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"

void funcao (int x, int y, int z){


    if (x>y && y>z)
    {
        printf("Oredem decrecente\n");
    }
    else if(x< y && y<z)
    {
        printf("Oredem crecente\n");
    }
    else
    {
        printf("nao tem ordem\n");
        if (x>y && x>z)
        {
            printf("x E o maior\n");
        }
        else if (y>x && y>z)
        {
            printf("y E o maior\n");
        }
        else if (z>y && z>x)
        {
            printf("z E o maior\n");
        }
        if (y>x && z>x)
        {
            printf("x E o menor\n");
        }
        else if (x>y && z>y)
        {
            printf("y E o menor\n");
        }
        else if (x>z && y>z)
        {
            printf("z E o menor\n");
        }
        
        
    }
    

}



int main ()
{
    double x = 0;
    double y = 0;
    double z = 0;
    x=IO_readdouble("insira x:\n");
    y=IO_readdouble("insira y:\n");
    z=IO_readdouble("insira z:\n");
    funcao(x,y, z);
    IO_pause ( "Apertar ENTER para continuar" );
    return (0);
}