#include <stdio.h>
#include <stdlib.h>
int main (void)
{
printf ("99999999_AED1\n");
int x; //lado quadrado
double y;// resultado final
printf ("Escrava o valor do lado do quadrado:\n");
scanf ("%d", &x);
printf ("x = %d\n", x);
y = (x*x)/4.0;
printf ("logo se x = %d um quarto da area do quadrado = %lf", x, y);


printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}