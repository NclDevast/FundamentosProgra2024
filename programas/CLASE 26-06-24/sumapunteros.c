#include "stdio.h"

void leer(float *num);
void suma(float *n);
int main (void)
{
    float a=2, b;
    leer(&a);
    printf("\nchau");
}
void leer (float *num)
{
    printf("Ingrese un numero: \n");
    scanf("%f",num);
    suma (num);
}
void suma(float *n)
{
    float b=7;
    printf("suma=%f",*n+b);
}