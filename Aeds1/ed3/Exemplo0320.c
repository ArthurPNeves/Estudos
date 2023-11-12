#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double x = 0;
    double y = 0;
    int n = 0;
    double z = 0;
    int c = 0;
    int k = 0;
    double j = 0;
    printf("insira a e b, sendo ambos maiores que 0 e menor que 1, que serao o intervalo de valores em que sera testado os numeros:\n");
    printf("insira a:\n");
    scanf("%lf", &x);
    printf("insira b:\n");
    scanf("%lf", &y);
    if (x > 1 || x < 0 || y > 1 || x < 0)
    {
        printf("\na e b nao estao entre 0 e 1.\n");
        getchar();
        return 0;
    }

    printf("insira qnts valores devem ser testados:\n");
    scanf("%d", &n);
    printf("insira os valores quer serao testados:\n");

    while (n > 0)

    {
        scanf("%lf", &z);
        k = (int)z;
        j = z - k;

        if (y > j && j > x)
        {
            printf("\n%lf e um valor que passa no teste\n\n", z);
            c = c + 1;
        }
        if (x > j && j > y)
        {
            printf("\n%lf e um valor que passa no teste\n\n", z);
            c = c + 1;
        }

        n = n - 1;
    }

    printf("dos valores escolhidos tem %d numeros que tem sua parte fracionaria entre o intervalo %lf e %lf", c, x, y);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}