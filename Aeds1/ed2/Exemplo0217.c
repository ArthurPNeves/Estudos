#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int x;
    int y;
    printf("insira o valor de Y: \n");

    scanf("%i", &y);

    printf("insira o valor de X: \n");

    scanf("%i", &x);

    printf("y = %i\nx = %i\n", y, x);

    if (y % 2 == 0 && 0 > y)
    {
        printf("Y = Par e negativo\n");
    }

    if (x % 2 != 0 && x > 0)
    {
        printf("X = impar e positivo\n");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}