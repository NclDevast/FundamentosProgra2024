#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "FUNCIONES.h"

int seleccionproveedorrand()
{
    return rand()%3;
}


void menuproveedor(struct perfilusuario *usuarios, struct perfilproveedor *proveedores, int num_proveedor)
{
    int opcmenu, identificador=1, proveedor, usuario, confirmacion, menu=0;
    int *pproveedor=&proveedor;
    int *pusuario=&usuario;

    confirmacion=validacion(usuarios,proveedores,identificador,pusuario,pproveedor);

    if (confirmacion<0)
    {
        limpiarpantalla();
        printf("\nUsuario o contrasena incorrecta\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        while (menu==0)
        {
            printf("\nSeleccione su opcion:\n1) Revisar Pedidos\n2) Realizar Pedidos\n3) Salir\n");
            scanf("%d", &opcmenu);
            switch (opcmenu)
            {
                case 1:
                    limpiarpantalla();
                    revisarpedidoproveedor(proveedores, pproveedor, usuarios);
                    break;
                case 2:
                    menu++;
                    break;
                case 3:
                    menu++;
                    break;
                default:
                    printf("\nOpcion invalida!\n");
                    break;
            }
        }
    }
}


void revisarpedidoproveedor(struct perfilproveedor *proveedores, int *pproveedor, struct perfilusuario *usuarios)
{
    extern int pedidosmc[3][3];
    extern int pedidosbk[3][3];
    extern int pedidosmotes[3][3];

    int z=0,i=0;

    limpiarpantalla();

    switch (*pproveedor)
    {
        case 0:  // McDonald's
            for (z=0;z<3;z++)
                {
                printf("\nUsuario %s", usuarios[z].nombreusuario);
                for (i=0;i<3;i++)
                {
                    printf("\n %d %s (%.2f)",pedidosmc[z][i],proveedores[*pproveedor].menu[i],proveedores[*pproveedor].precios[i]);
                }
            }
            break;
        case 1:  // Burger King
            for (z=0;z<3;z++)
                {
                printf("\nUsuario %s", usuarios[z].nombreusuario);
                for (i=0;i<3;i++)
                {
                    printf("\n %d %s (%.2f)", pedidosbk[z][i],proveedores[*pproveedor].menu[i],proveedores[*pproveedor].precios[i]);
                }
            }
            break;
        case 2:  // Los Motes de la Magdalena
            for (z=0;z<3;z++)
                {
                printf("\nUsuario %s", usuarios[z].nombreusuario);
                for (i=0;i<3;i++)
                {
                    printf("\n %d %s (%.2f)", pedidosmotes[z][i],proveedores[*pproveedor].menu[i],proveedores[*pproveedor].precios[i]);
                }
            }
            break;
        default:
            printf("\nProveedor no válido\n");
            break;
    }

    printf("\n");
    system("pause");
    limpiarpantalla();
}
