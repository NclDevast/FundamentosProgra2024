#include "stdio.h"
#include "math.h"

void valorAbsoluto(double *num);
void raiz(double *num);

int main(void) 
{
    double numero;
    double *num=&numero;
    printf("Introduce un número: ");
    scanf("%lf",num);
    valorAbsoluto(num);
    printf("El valor absoluto es: %.2lf\n",*num);
    raiz(num);
    printf("La raiz es %.2lf\n",*num);
}
void valorAbsoluto(double *num) // funcion que calcula el valor absoluto de un numero
{
    if (*num<0)  // solo es necesario editar el contenido del puntero si es negativo
    {
        *num=-1*(*num);
    }
}
void raiz(double *num)
{
    *num=sqrt(*num);
}
