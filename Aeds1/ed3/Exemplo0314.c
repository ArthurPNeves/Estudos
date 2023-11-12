#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char x [80];
    int t = 0;
    int c = 0;
    printf("escrava a palvra:\n");
    scanf("%s", x);
    printf("sua palavra e:%s\n", x);
    t = strlen (x) ;  
    int y = 0;

    while (y<t)
    {
        
        if ((x[y]>='a' && x[y]<='z') || (x[y]>='A' && x[y]<='Z')  )
        {
            
            printf ("%c\n", x[y]);
            c = c + 1;
        }
        
     y = y + 1;   
    }
    printf (" tem %d letras ", c);
    
    printf("\nApertar ENTER para terminar.\n");
    getchar();
    return 0;
}