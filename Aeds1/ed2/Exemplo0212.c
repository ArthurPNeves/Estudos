#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int x;

    printf("insira o valor de X: \n");

    scanf("%i", &x);
    printf("x = %i\n", x);

    if (x % 2 == 0 && x > -30)
    {
        printf("X = par e maior que -30");
    }
    else if (x % 2 != 0 && x < 30)
    {
        printf("X = impar e menor que 30");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}