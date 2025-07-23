#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

extern struct cliente[3];
extern struct proveedor[3];


void menuproveedor(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor)
{
    int confirmacion,identificador=1,usua,prov,opc;
    int *pusuario=&usua, *pprovedor=&prov;

    confirmacion=validacion(cliente,proveedor,numClientes,numProveedor,identificador,pusuario,pprovedor);

    if(confirmacion!=0)
    {
        printf("\nContrasena incorrecta!");
        limpiarpantalla();
        return;
    }

    else
    while(1)
    {
        printf("\nBienvenido %s! Selecciona una opcion:\n1)Revisar Pedidos\n2)Salir\n",proveedor[*pprovedor].nombre);
        scanf("%d",&opc);
        getchar();
        switch(opc)
        {
            case 1:
            revisarpedidosproveedor(cliente,proveedor,*pprovedor);
            break;

            case 2:
            limpiarpantalla();
            exit(0);

            default:
            printf("\nOpcion invalida!");
            break;
        }
    }

return;
}

void revisarpedidosproveedor(struct perfilcliente cliente[3],struct perfilproveedor proveedor[3],int pproveedor)
{
    int i,j;
    for(i=0;i<MAXCLIENTES;i++)
    {
        printf("\nPedidos pendientes de %s:\n",cliente[i].nombre);
        for(j=0;j<MAXCLIENTES;j++)
            {
            printf("Nombre\t\tCantidad\tPrecio Unitario\n");
            printf("-------------------------------------------------\n");

            for (int j=0;j<3;j++)
            {
                printf("%-16s\t%-8d\t$%.2f\n", proveedor[pproveedor].productos[j], proveedor[pproveedor].pedidos[pproveedor][j], proveedor[pproveedor].precios[j]);
            }
            printf("\n");
        }
        system("pause");
        limpiarpantalla();
    }
    return;
}
