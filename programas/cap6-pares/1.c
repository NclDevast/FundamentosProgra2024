#include "stdio.h"
#include "stdlib.h"
#include "windows.h" // se agrega la libreria windows.h para asegurar que system("pause") no genere problemas

void leer (int *a); // funciones void, no retornan valores
void factorial (int *s, int *a);

int main (void)
{
    int a,s;
    printf("Ingrese su número para encontrar el factorial: ");
    leer(&a);
    printf("\nSu número es: %d",a);
    factorial(&s,&a);
    printf("\nSu resultado es: %d",s);
    printf("\n");
}
void leer (int *a) //lee el numero para encontrar el factorial
{
    scanf("%i",a);
    if(*a<=0||*a>100)
    {
        printf("\nMath Error!");
        printf("\n");
        system("pause");
        exit(0);
    }
}
void factorial (int *s, int *a) //se desreferencia el valor de *a y se retorna el valor de s a main mediante el puntero *s
{
    int acum=1; //se inicializa el contador en uno para que funcione con cero y con uno correctamente
    *s=1; // se inicializa el contador en uno para que devuelva la respuesta correcta en 0!=1
    do
    {
        *s=*s*(acum);
        acum++;
    }
    while (acum<=*a); //el contador acum se usa para repetir el bucle hasta que se cumpla el factorial de un numero n
}