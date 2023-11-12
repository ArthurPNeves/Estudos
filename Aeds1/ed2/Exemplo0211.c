#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int x;

    printf("insira o valor de X: \n");

    scanf("%i", &x);
    printf("x = %i\n", x);

    if (x % 2 == 0)
    {
        printf("X = par");
    }
    else
    {
        printf("X = impar");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}
