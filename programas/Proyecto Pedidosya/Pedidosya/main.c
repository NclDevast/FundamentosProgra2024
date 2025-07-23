#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "FUNCIONES1.h"

int main(void)
{
    int perfilusuario[6][3]={0,1,2}; // La primera dimension del arreglo representa el usuario, la segunda dimension representa el local del que se ordena
    int perfilproveedor[6][3]={0,1,2}; // La primera dimension del arreglo representa el proveedor, la segunda dimension representa el numero de ordenes del local
    int opcusuario;
    opcusuario=0;

    while(1)
    {
    printf("\nBienvenido a PedidosYa!, escoja su opcion:\n1)Iniciar como usuario\n2)Iniciar como proveedor ");
    scanf("%d",&opcusuario);
    switch(opcusuario)
        {
        case 1:
           {
               menuusuario(*perfilusuario,*perfilproveedor);
               printf("\nMatriz Cliente\n");
               imprimirMatriz(perfilusuario);
               printf("\nMatriz Proveedor\n"); //debug
               imprimirMatriz(perfilproveedor);
               break;
           }
        case 2:
            {
                menuproveedor(*perfilproveedor,*perfilusuario);
                break;
            }
        default:
            {
                printf("\nOpcion invalida");
            }
        }
    }

    return 0;
}
