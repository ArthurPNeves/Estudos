#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char x [80];
    int t = 0;
    printf("escrava a palvra:\n");
    scanf("%s", x);
    printf("sua palavra e:%s\n", x);
    t = strlen (x) ;  
    int y = 0;

    while (y<t)
    {
        
        if (x[y]>='a' && x[y]<='z' )
        {
            printf ("%c\n", x[y]);
        }
        
     y = y + 1;   
    }
    





    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}
