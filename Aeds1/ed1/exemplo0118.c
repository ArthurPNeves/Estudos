#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
printf ("99999999_AED1\n");
double x; // comprimento
double z; // largura
double k; // altura
double y;// volume paralelepipedo
printf ("Escrava o valor real do comprimento, largura e altura do paralelpiedo respectivamente:\n");
scanf ("%lf\n%lf\n%lf", &x,&z,&k);
printf ("x = %lf\n", x);
printf ("z = %lf\n", z);
printf ("k = %lf\n", k);
x = x*6.0;
k = k*6.0;
z = z*6.0;
y = x*z*k;
printf ("logo caso esses lados desjam multiplicados por 6, o volume do paralelepipedo sera de:\n%lf", y);

printf ("\nApertar ENTER para terminar.\n");
getchar ();
return (0);


}