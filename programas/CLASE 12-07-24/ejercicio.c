//generar dos vectores y hacer suma de elemento por elemento
//volver a hacer

#include "stdio.h"
int leer(int  a[1]);
int suma(int a[1],int b[1]);

int main (void)
{
    int vector1[1];
    int vector2[1];
    int resultado[1];
    vector1[1]=leer(&vector1[1]);
    vector2[1]=leer(&vector2[1]);

}

int leer(int  a[1])
{
    printf("\nIngrese la componente x del vector");
    scanf("%d",a[0]);
    printf("\nIngrese la componente y del vector");
    scanf("%d",a[1]);
    return a[1];
}

int suma(int a[1],int b[1])
{
    int resultado[1];
    resultado[1];
    resultado[1]=a[0]+b[0],resultado[1]=a[0]+b[0];
    return resultado[1];
}