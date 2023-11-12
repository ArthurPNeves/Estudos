#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    double y;
    double x;
    printf("insira o valor de Y: \n");

    scanf("%lf", &y);

    printf("insira o valor de X: \n");

    scanf("%lf", &x);

    printf("y = %lf\nx = %lf\n", y, x);

    if (y > x)
    {
        printf("Y > X\n");
    }
    if (y < x)
    {
        printf("Y < X\n");
    }
    if (y == x)
    {
        printf("Y = X\n");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}