#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    double y;
    double x;
    double z;
    printf("insira o valor de Y: \n");

    scanf("%lf", &y);

    printf("insira o valor de X: \n");

    scanf("%lf", &x);

    printf("insira o valor de Z: \n");

    scanf("%lf", &z);

    printf("y = %lf\nx = %lf\nz = %lf\n", y, x, z);

    if ((x != y && x != z && z != y) && (y> z && y<x) || (y< z && y>x) )
    {
        printf("Y esta entre z e x");
    }
    else
    {
        printf("Y nao esta entre z e x");
    }
    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}