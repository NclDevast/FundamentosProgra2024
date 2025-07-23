#include "stdio.h"
#include "math.h"
double ValorAbsoluto(double num);
int main(void)
{
    double num,valor;
    printf("Ingrese un numero> ");
    scanf("%lf", &num);
        valor=ValorAbsoluto(num);
        printf("El valor absoluto de %lf es %lf", num, valor);
}
double ValorAbsoluto(double num)
{
        return fabs(num);
}
