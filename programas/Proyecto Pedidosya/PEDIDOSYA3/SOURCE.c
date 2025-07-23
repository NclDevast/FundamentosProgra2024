#include "stdio.h"
#include "stdlib.h"
#include "FUNCIONES.h"
#include "string.h"
#include "windows.h"
#include "unistd.h"

void revisarpedidoproveedor(struct perfilproveedor *proveedores, int *pproveedor, struct perfilusuario *usuarios)
{
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
                    printf("\n %d %s (%.2f)", pedidosmc[z][i], proveedores[*ppproveedor].menu[i], proveedores[*ppproveedor].precios[i]);
                }
            }
            break;
        case 1:  // Burger King
            for (z=0;z<3;z++)
            {
                printf("\nUsuario %s", usuarios[z].nombreusuario);
                for (i=0;i<3;i++)
                {
                    printf("\n %d %s (%.2f)", pedidosbk[z][i], proveedores[*pproveedor].menu[i], proveedores[*pproveedor].precios[i]);
                }
            }
            break;
        case 2:
            for (z=0;z<3;z++)
            {
                printf("\nUsuario %s", usuarios[z].nombreusuario);
                for (i=0;i<3;i++)
                {
                    printf("\n %d %s (%.2f)", pedidosmotes[z][i], proveedores[*ppproveedor].menu[i], proveedores[*pproveedor].precios[i]);
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

void imprimirMatriz(int pedidos[3][3]) // debug
{
    printf("\n");
    for (int i=0;i<3;i++)
        {
        for (int j=0;j<3;j++)
        {
            printf("%d ", pedidos[i][j]);
        }
        printf("\n");
    }
}

void limpiarpantalla()
{
    sleep(1.5);
    system(cls);
    printf("\nCargando...");
    sleep(1.2);
    printf("Cargando...");
    sleep(1.2);
    system(cls);
}
