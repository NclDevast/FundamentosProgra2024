#include "stdio.h"
int mayor(int a, int b);
int leer (int a);
int main(void) 
{
    int num1, num2,resultado;
    num1=leer(num1); //se asigna el valor retornado por la funcion leer a num1
    num2=leer(num2); //se asigna el valor retornado por la funcion leer a num2
    resultado = mayor(num1, num2); // se asigna el valor retornado por la funcion leer a resultado
    if (resultado!=0) //se verifica que los numeros sean iguales
    printf("El mayor número es: %d\n", resultado);
}

int leer(int a) //la funcion lee un numero ingresado por usuario y lo retorna
{
    printf("Ingrese un número: ");
    scanf("%d", &a);
    return a;
}

int mayor(int a, int b) //La funcion verifica el numero mayor entre los parametros ingresados
{
    int s=0;
    if (a>b) 
    {
        return a;
    }
    else if (a==b) // se verifica si los numeros son iguales
    {
        printf("Los numeros son iguales\n");
        return s; //si los numeros son iguales se retorna cero al parametro
    }
    else 
    {
        return b;
    }

}