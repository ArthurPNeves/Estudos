#include <stdio.h>
#include <stdlib.h>
int main (void)
{
printf ("99999999_AED1\n");
int x; //lado quadrado
double y;// area quadrado
printf ("Escrava o valor do lado do quadrado:\n");
scanf ("%d", &x);
printf ("x = %d\n", x);
y = (x*x);
printf ("A area do quadrado = %lf\n e seu perimetro = %d", y, x*4);
x = x*3;
y = (x*x);
printf ("\n Caso multiplaco o lado do quadrado por 3 teremos como lado:\n %d\n sua Area:\n %lf\n e como perimetro:\n%d ", x, y,x*4);

printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}