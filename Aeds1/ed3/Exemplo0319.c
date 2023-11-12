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
    printf("insira a e b, sendo a menor que b,que serao o intervalo de valores em que sera testado os numeros:\n");
    printf("insira a:\n");
    scanf("%lf", &x);
    printf("insira b:\n");
    scanf("%lf", &y);
    if (x>y)
    {
        printf("\nErro a maior que b\n");
        getchar();
        return 0;
    }
    
    printf("insira qnts valores devem ser testados:\n");
    scanf("%d", &n);
    printf("insira os valores quer serao testados:\n");

    while (n > 0)

    {
        scanf("%lf", &z);
        k = (int) z;
            if ( k % 2 != 0 && y > z && z > x)
            {
                printf("\n%lf e um valor que passa no teste\n\n", z);
                c = c + 1;
            }
        
        
        n = n -1;
    }

    printf (" dos valores escolhidos tem %d numeros que estao entre o intervalo %lf e %lf e e impar", c, x, y);

    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}