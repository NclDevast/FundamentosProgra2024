#include "stdio.h"
#include "stdlib.h"
#include "time.h" //se incluye para poder usar semillas pseudoaleatorias segun la hora

int random (int numran);
int rand2(int numran2);
int main (void)
{
   while (1)
    {
    int opcusuario=0, resultado;
    int*ptr2=&opcusuario,*ptr3=&resultado;
    printf("Seleccione 1 para observar el funcionamiento de rand, seleccione 2 para observar el comportamiento de rand con srand\n");
    scanf("%d",ptr2);
    switch (*ptr2)
    {
        case 1:
        {
            *ptr3=random(0);
            break;
        }
        case 2:
        {
            *ptr3=rand2(0);
            break;
        }
        default:
        {
            printf("\nOpcion no valida");
        }
    }
    }


   
}
int random (int numran)
{
    srand(42); //se inicializa con una semilla especifica para obtener el mismo resultado sin importar las veces que se 
                //ejecuta el programa
    int *ptr = &numran; //se indica un puntero a la direccion de numran
    *ptr=rand(); //se genera un número pseudoaleatorio a numram meidante el puntero a la direccion de numran
    printf("\n%d\n",*ptr); //se imprime el dato almacenado en la direccion del puntero
    return *ptr; //se retorna el resultado al puntero interno
 //cabe notar que esta funcion solo genera un solo número pseudo aleatorio
}

int rand2(int numran)
{
    srand(time(NULL)); //Se genera una semilla dependiente del timepo actual, time(NULL) genera una semilla en el tiempo actual,
                        //por lo que se generará una semilla pseudoaleatoria nueva a cada segundo 
    int* ptr = &numran; //se indica un puntero a la direccion de numran
    *ptr=rand(); //se genera un número pseudoaleatorio a numram meidante el puntero a la direccion de numran
    printf("\n%d\n",*ptr);//se imprime el dato almacenado en la direccion del puntero
    return *ptr; //se retorna el resultado al puntero interno
 //cabe notar que esta funcion genera un numero aleatorio diferente cada segundo
}
