#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//void menuprincipal(int *perfilusuario, int *perfilproveedor);
void menuusuario(int *perfilusuario);
int seleccionusuario(int *confirmacion, int *seleccionusuario);
void hacerpedido (int *perfilusuario);
void menuproveedor();
void seleccionproveedor();

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

void menuusuario(int *perfilusuario)
{
    int confirmacion=0,usuario,opcusuario=0,confirmacionmenu=0;
    int *pconfirmacion=&confirmacion;

    usuario=seleccionusuario(*pconfirmacion,*perfilusuario);

    if (*pconfirmacion=!0)
    {
        printf("\nUsuario invalido, retornando al menu.");
        return;
    }
    while(confirmacionmenu==0)
    {
    printf("\nBienvenido!, seleccione su opcion:\n1)Hacer Pedido\n2)Revisar Pedido\n3)Cancelar Pedido\n4)Salir\n");
    scanf("%d",opcusuario);
    switch(opcusuario)
        {
        case 1:
           {
               hacerpedido();
               break;
           }
        case 2:
            {
                break;
            }
        case 3:
            {
                break;
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
    printf("\nSeleccione su usuario:\n1)Usuario 1\n1)Usuario 2\n1)Usuario 3");
    switch(opcusuario)
        {
        case 1:
           {
               seleccion=perfilusuario[0][0];
               *confirmacion=0;
               return seleccion;
           }
        case 2:
            {
                seleccion=perfilusuario[0][1];
                *confirmacion=0;
                return seleccion;
            }
        case 3:
            {
                seleccion=perfilusuario[0][2];
                *confirmacion=0;
                return seleccion;
            }
        default:
            {
                return -1;
            }
        }
}
void hacerpedido(int *perfilusuario)
{
 return;
}
#endif // FUNCIONES_H_INCLUDED
