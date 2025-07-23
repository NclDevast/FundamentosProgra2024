#include "stdio.h"
#include "stdlib.h"

int main (void)
{
    char str [] = "40", str2 [] = "20"; //se declara a las variables como cadenas
    int num1=atoi(str); //se convierte la primera cadena en un dato de numero entero
    int num2=atoi(str2); //se convierte la segunda cadena en un dato de numero entero
    int s;
    s=num1+num2;  // la suma de los datos enteros nos devuelve otro numero entero
    printf("La suma de los numeros es: %d",s);
    return 0;
}