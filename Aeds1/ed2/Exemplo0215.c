#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int x;

    printf("insira o valor de X: \n");

    scanf("%i", &x);
    printf("x = %i\n", x);

    if ((x >= 15 && 45 >= x) && (x >= 20 && 40 >= x))
    {
        printf("X pertence ao intervalo fechado entre (15:45) e (20:40)");
        printf("\nApertar ENTER para terminar.\n");
        getchar();
        return 0;
    }

    else if ((x >= 15 && 45 >= x) || (x >= 20 && 40 >= x))
    {
        printf("X pertence ao intervalo fechado entre (15:45) ou (20:40)");
    }

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}