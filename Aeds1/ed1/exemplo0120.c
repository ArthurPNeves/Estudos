#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
printf ("99999999_AED1\n");
double x; // raio
double y; // area circulo
printf ("Escrava o valor real do raio do circulo:\n");
scanf ("%lf", &x);
printf ("x = %lf\n", x);

x = (x/8)*3;
y = x*x*M_PI;
printf ("Logo o circulo 3/8 do raio encerido sera de:\n%lf", y);

printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}