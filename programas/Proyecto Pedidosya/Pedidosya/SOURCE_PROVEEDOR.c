#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "FUNCIONES1.h"

void seleccionproveedorrand (int *perfilproveedor, int eleccionrestaurante)
{
    int proveedor;
    srand(time(NULL));
    proveedor=rand()%(2-0+1)+0;
    *(perfilproveedor+eleccionrestaurante*3+proveedor)=*(perfilproveedor+eleccionrestaurante*3+0)+1;
    return;
}

void menuproveedor(int *perfilproveedor, int  *perfilusuario)
{
    int confirmacion=0,usuario,opcusuario=0,confirmacionmenu=0;
    int *pconfirmacion=&confirmacion; //se puede realizar sin la necesidad de puntero

    usuario=seleccionproveedor(pconfirmacion,perfilproveedor);

    if (*pconfirmacion==!0)//se verifica si la confirmacion no fue exitosa por cualquier razon
    {
        printf("\nUsuario invalido, retornando al menu.");
        return;
    }
    while(confirmacionmenu==0) //falta agregar condicion de salida de loop
    {
    printf("\nBienvenido!, seleccione su opcion:\n1)Hacer Entrega\n2)Revisar Pedido\n3)Salir\n");
    scanf("%d",&opcusuario);
    switch(opcusuario)
        {
        case 1:
           {

               break;
           }
        case 2:
            {
                break; //agregar opciones de verificar orden SOLO PARA EL USUARIO
            }
        case 3:
            {
                break; //agregar opcion de eliminar orden, puede eliminarse
            }
        default:
            {
                return ;
            }
        }
    }
}
int seleccionproveedor(int *confirmacion, int *perfilproveedor)
{
    int opcusuario=0,seleccion;
    printf("\nSeleccione su usuario:\n1)Usuario 1\n1)Usuario 2\n1)Usuario 3\n");
    scanf("%d",&opcusuario);
    switch(opcusuario)
        {
        case 1:
           {
               seleccion=*(perfilproveedor+0*3+0); //
               *confirmacion=0;
               return seleccion;
           }
        case 2:
            {
                seleccion=*(perfilproveedor+0*3+1);
                *confirmacion=0;                    // se vuelve a inicializar el puntero de confirmacion por si acaso
                return seleccion;
            }
        case 3:
            {
                seleccion=*(perfilproveedor+0*3+2);
                *confirmacion=0;
                return seleccion;
            }
        default:
            {
                return -1;
            }
        }
}
