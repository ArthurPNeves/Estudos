#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
printf ("99999999_AED1\n");
double x; //lado quadrado
double y;// volume quadrado
printf ("Escrava o valor do lado do quadrado:\n");
scanf ("%lf", &x);
printf ("x = %lf\n", x);
x = x/5;
y = pow(x,3);
printf ("logo se um quinto de x = %lf, o volume de seu cubo sera = %lf", x, y);

printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}