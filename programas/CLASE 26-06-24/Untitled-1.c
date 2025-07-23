#include "stdio.h"

void leer(float num); // ( ) el parametro define el tipo de dato que recibe el prototipo, 
// no el tipo de dato que se usa internamente necesariamente

int main (void)
{
    float a, b;
    leer(a); // en el llamado no se especifica el tipo de dato que se recibe, se asigna el valor que retorna num 
    // b=leer(b); // se asigna el dato retornado en num en cada instancia en la que se llama la función
    printf("\nUsted ha ingresado %f",a);
    // printf("\nUsted ha ingresado %f",b);
    return 0;
}

void leer(float num) // el tipo de dato void es vacio, y no retornará un numero
{
    printf("Ingrese un numero: ");
    scanf("%f",&num);
    return 0;
}