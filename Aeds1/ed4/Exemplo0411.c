#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double x = 0;
    double y = 0;
    int n = 0;
    double z = 0.0;
    int c = 0;
    printf("insira x e y que serao o intervalo de valores  em que sera testado os numeros:\n");
    printf("insira x:\n");
    scanf("%lf", &x);
    printf("insira y:\n");
    scanf("%lf", &y);
    printf("insira qnts valores devem ser testados:\n");
    scanf("%d", &n);
    printf("insira os valores quer serao testados:\n");
    int k = n;
    while (k > 0)

    {
        scanf("%lf", &z);
        
        if (y > x)
        {

            if (y >= z && z >= x)
            {
                printf(" %lf e um valor que passa no teste\n", z);
                c = c + 1;
            }
        }

        if (x > y)
        {

            if (x >= z && z >= y)
            {
                printf(" %lf e um valor que passa no teste\n", z);
                c = c + 1;
            }
        }
        k = k -1;
    }
    
    int p = n - c; 
    printf (" dos valores escolhidos tem %d numeros que estao entre o intervalo %lf e %lf e %d que nao estao no intervalo", c, x, y, p);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}
