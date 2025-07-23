#include "stdio.h"

void leer(float *num);
void suma(float *n);
int maint (void)
{
    float a, b;
    leer(&a);
    // leer(&b);
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