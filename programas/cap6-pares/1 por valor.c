#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "windows.h" // se agrega la libreria windows.h para asegurar que system("pause") no genere problemas

int leer (int a); // funciones int, retornan valores
int factorial (int s, int a);

int main (void)
{
    int a,s;
    printf("Ingrese su número para encontrar el factorial: ");
    a=leer(a);
    printf("\nSu número es: %i",a);
    s=factorial(s,a);
    printf("\nSu resultado es: %d",s);
    printf("\n");
    system ("pause");
}
int leer (int a) //lee el numero para encontrar el factorial
{
    scanf("%i",&a);
    ceil(a); // Se redondea el numero al inmediato inferior
    if(a<0) //se comprueba que el numero sea mayor o igual a cero
    {
        printf("\nMath Error!");
        system("pause");
        exit (0);
    }
    return a;
}
int factorial (int s, int a) //se recibe a como parametro y se retorna s como valor
{
    int acum=1; //se inicializa el contador en uno para que funcione con cero y con uno correctamente
    s=1; // se inicializa el contador en uno para que devuelva la respuesta correcta en 0!=1
    do
    {
        s=s*(acum);
        acum++;
    }
    while (acum<=a); //el contador acum se usa para repetir el bucle hasta que se cumpla el factorial de un numero n
    return s;
}