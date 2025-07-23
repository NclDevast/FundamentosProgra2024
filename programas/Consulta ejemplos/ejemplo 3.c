#include "stdio.h"
#include "math.h"

const double pi=3.1416; // se define a pi como constante global 

int main (void)
{
    double x=1, y=1, s; //se define x, y como catetos
    s=atan(x/y); // se encuentra el angulo formado entre catetos e hipotenusa
    s=s*180/pi; // la funcion atan da resultados en radianes, asi que se transforma a gradianes
    printf("%.1f °",s);
    return 0;
}