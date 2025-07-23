#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"

int main()
{
    const char *perfilusuario[2]={"EstrellaBonita2","contrasena1234","yy5bvUnFYc"};
    const char *perfilproveedor[2]={"JuanRepartidor1234","asdfgh666","un4PulG4aVentura2003"};
    int opcusuario=0;
    while(1)
    {
        printf("\nBienvenido! Escoja como desea iniciar\n1)Usuario\n2)Proveedor\n3)Salir\n");
        scanf("%d",&opcusuario);
        switch(opcusuario)
        {
        case 1:
            {
                menuusuario(perfilusuario,perfilproveedor);
                break;
            }
        case 2:
            {
                //menuproveedor(*perfilproveedor,*perfilproveedor);
                break;
            }
        case 3:
            {
                exit (0);
            }
        default:
            {
                printf("\nOpcion Invalida!");
            }
        }
    }
}
