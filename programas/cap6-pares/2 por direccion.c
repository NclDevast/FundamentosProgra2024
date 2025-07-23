#include "stdio.h"

void mayor(int *resultado, int a, int b, int c);
void leer(int *a);

int main(void)
{
    int num1,num2,num3,resultado;
    leer(&num1);
    leer(&num2);
    leer(&num3);
    mayor(&resultado,num1,num2,num3);
    if (resultado==0)
    printf("\nlos numeros son iguales.");
    else
    printf("El mayor n�mero es: %d\n", resultado);
}

void leer(int *a)
{
    printf("Ingrese un n�mero: ");
    scanf("%d",a);
}

void mayor(int *resultado, int a, int b,int c)
{
    if (a>b&&a>c)
    {
        *resultado=a;
    }
    else if (b>a&&b>c)
    {
        *resultado=b;
    }
    else if (c>a&&c>b)
    {
        *resultado=c;
    }
    else
    {
        *resultado=0;
    }
}