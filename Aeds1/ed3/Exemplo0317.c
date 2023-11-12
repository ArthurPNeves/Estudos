#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x = 0;
    int y = 0;
    int n = 0;
    int z = 0;
    int c = 0;
    printf("insira x e y que serao o intervalo de valores  em que sera testado os numeros:\n");
    printf("insira x:\n");
    scanf("%d", &x);
    printf("insira y:\n");
    scanf("%d", &y);
    printf("insira qnts valores devem ser testados:\n");
    scanf("%d", &n);
    printf("insira os valores quer serao testados:\n");

    while (n > 0)

    {
        scanf("%d", &z);
        
        if (y > x)
        {

            if (z % 5 == 0 && y >= z && z >= x)
            {
                printf(" %d e um valor que passa no teste\n", z);
                c = c + 1;
            }
        }

        if (x > y)
        {

            if (z % 5 == 0 && x >= z && z >= y)
            {
                printf(" %d e um valor que passa no teste\n", z);
                c = c + 1;
            }
        }
        n = n -1;
    }

    printf (" dos valores escolhidos tem %d numeros que estao entre o intervalo %d e %d e e multiplo de 5", c, x, y);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}