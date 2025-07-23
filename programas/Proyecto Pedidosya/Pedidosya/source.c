#include "stdio.h"
#include "string.h"
#include "FUNCIONES1.h"

/*void menuprincipal(int *perfilusuario, int *perfilproveedor)
{
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
               menuusuario(*perfilusuario);
               break;
           }
        case 2:
            {
                menuproveedor();
                break;
            }
        default:
            {
                printf("\nOpcion invalida")
            }
        }
    }

}*/

void menuusuario(int *perfilusuario, int *perfilproveedor)
{
    int confirmacion=0,usuario,opcusuario=0,confirmacionmenu=0;
    int *pconfirmacion=&confirmacion; //se puede realizar sin la necesidad de puntero

    usuario=seleccionusuario(pconfirmacion,perfilusuario);

    if (*pconfirmacion==!0)//se verifica si la confirmacion no fue exitosa por cualquier razon
    {
        printf("\nUsuario invalido, retornando al menu.");
        return;
    }
    while(confirmacionmenu==0) //falta agregar condicion de salida de loop
    {
    printf("\nBienvenido!, seleccione su opcion:\n1)Hacer Pedido\n2)Revisar Pedido\n3)Cancelar Pedido\n4)Salir\n");
    scanf("%d",&opcusuario);
    switch(opcusuario)
        {
        case 1:
           {
               hacerpedido(perfilusuario, usuario, perfilproveedor);
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
        case 4:
            {
                return;
            }
        default:
            {
                return ;
            }
        }
    }
}

int seleccionusuario(int *confirmacion, int *perfilusuario)
{
    int opcusuario=0,seleccion;
    printf("\nSeleccione su usuario:\n1)Usuario 1\n1)Usuario 2\n1)Usuario 3\n");
    scanf("%d",&opcusuario);
    switch(opcusuario)
        {
        case 1:
           {
               seleccion=*(perfilusuario+0*3+0); //
               *confirmacion=0;
               return seleccion;
           }
        case 2:
            {
                seleccion=*(perfilusuario+0*3+1);
                *confirmacion=0;                    // se vuelve a inicializar el puntero de confirmacion por si acaso
                return seleccion;
            }
        case 3:
            {
                seleccion=*(perfilusuario+0*3+2);
                *confirmacion=0;
                return seleccion;
            }
        default:
            {
                return -1;
            }
        }
}

void hacerpedido(int *perfilusuario, int usuario, int *perfilproveedor)
{
    int eleccionrestaurante;
    switch(usuario)
     {
    case 0:
        {
            eleccionrestaurante=opcionrestaurante(perfilusuario);
            *(perfilusuario+eleccionrestaurante*3+0)=*(perfilusuario+eleccionrestaurante*3+0)+1; // para extraer un valor de un arreglo tipo puntero se u
            seleccionproveedorrand(perfilproveedor,eleccionrestaurante);                         //*(identificador + fila elemento*n total Columnas + Columna elemento)
            break;
        }
    case 1:
        {
            eleccionrestaurante=opcionrestaurante(perfilusuario);
            *(perfilusuario+eleccionrestaurante*3+1)=*(perfilusuario+eleccionrestaurante*3+1)+1;
            seleccionproveedorrand(perfilproveedor,eleccionrestaurante);
            break;
        }
    case 2:
        {
            eleccionrestaurante=opcionrestaurante(perfilusuario);
            *(perfilusuario+eleccionrestaurante*3+2)=*(perfilusuario+eleccionrestaurante*3+2)+1;
            seleccionproveedorrand(perfilproveedor,eleccionrestaurante);
            break;
        }
     }
}

int opcionrestaurante(int *perfilusuario) //agregar
{
    int opcusuario=0;
    const char * restaurantes[5]={"McDonnalds "," KFC"," Burger King "," Los motes de la Magdalena "," Mayflower "};
    printf("\nEscoja su restaurante a eleccion:");
    for(int i=0;i<5;i++)
    {
        printf("%s ",restaurantes[i]);
    }
    scanf("%d",&opcusuario);
    switch (opcusuario)
    {
        case 1:
            {
                printf("\nUsted ha escogido %s, Su orden se ha realizado con exito.",restaurantes[0]);
                return 1;
            }
        case 2:
            {
                printf("\nUsted ha escogido %s, Su orden se ha realizado con exito.",restaurantes[1]);
                return 2;
            }
        case 3:
            {
                printf("\nUsted ha escogido %s, Su orden se ha realizado con exito.",restaurantes[2]);
                return 3;
            }
        case 4:
            {
                printf("\nUsted ha escogido %s, Su orden se ha realizado con exito.",restaurantes[3]);
                return 4;
            }
        case 5:
            {
                printf("\nUsted ha escogido %s, Su orden se ha realizado con exito.",restaurantes[4]);
                return 5;
            }
        default:
            {
                printf("\nOpcion invalida!");
                return 0;
            }
    return 0;
    }
}


void imprimirMatriz(int perfilusuario[6][3]) //debug
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", perfilusuario[i][j]);
        }
        printf("\n");
    }
}
