#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int x;

    printf("insira o valor de X: \n");

    scanf("%i", &x);
    printf("x = %i\n", x);

    if (x >= 15 && 45 >= x)
    {
        printf("X pertence ao intervalo fechado entre (15:45)");
    }

    else
    {
        printf("X nao pertence ao intervalo fechado entre (15:45)");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}