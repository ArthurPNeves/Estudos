#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int x;
    int y;
    printf("insira o valor de X: \n");

    scanf("%i", &x);

    printf("insira o valor de Y: \n");

    scanf("%i", &y);

    printf("x = %i\ny = %i\n", x, y);

    if (x % 2 != 0)
    {
        printf("X = impar\n");
    }

    if (y % 2 == 0)
    {
        printf("Y = Par");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}