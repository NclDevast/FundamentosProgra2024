#include "stdio.h"
#include "stdlib.h"
#include "FUNCIONES.h"

extern struct cliente[3];
extern struct proveedor[3];

void menuusuario(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor)
{
    int confirmacion,identificador=0,usua,prov,opc;
    int *pusuario=&usua, *pprovedor=&prov;

    confirmacion=validacion(cliente,proveedor,numClientes,numProveedor,identificador,pusuario,pprovedor);
    limpiarpantalla();

    if(confirmacion!=0)
    {
        printf("\nContrasena incorrecta!");
        return;
    }

    else
    while(1)
    {
    printf("\nBienvenido %s! Selecciona una opcion:\n1)Hacer Pedido\n2)Revisar Carrito\n3)Salir\n",cliente[*pusuario].nombre);
    scanf("%d",&opc);
    getchar();
    switch(opc)
    {
        case 1:
        hacerpedido(cliente,proveedor,*pusuario);
        break;

        case 2:
        revisarcarrito(cliente,proveedor,pusuario);
        break;

        case 3:
        limpiarpantalla();
        return;

        default:
        printf("\nOpcion no valida!");
        break;
    }
    }

}

void hacerpedido(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int pusuario)
{
    int proveedorrand, seleccion;
    proveedorrand=proveedoraleatorio();

    limpiarpantalla();

    printf("\nBienvenido a %s!\nMenu:\n",proveedor[proveedorrand].nombre);

    for(int i=0;i<3;i++)
    {
        printf("%d) %s, $%.2f\n",i+1,proveedor[proveedorrand].productos[i],proveedor[proveedorrand].precios[i]);
    }

    printf("\nHaga su eleccion: ");
    scanf("%d",&seleccion);
    getchar();
    seleccion--;

    printf("\nUsted ha seleccionado %s por %.2f!",proveedor[proveedorrand].productos[seleccion],proveedor[proveedorrand].precios[seleccion]);
    proveedor[proveedorrand].pedidos[pusuario][seleccion]++;

    printf("\n");
    system("pause");
    limpiarpantalla();

    return;
}

void revisarcarrito(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int *pusuario)
{
    if (*pusuario<0||*pusuario>=MAXCLIENTES)
    {
        printf("Error: usuario fuera de rango.\n");
        return;
    }
    limpiarpantalla();
    printf("\nSu Carrito actual es:\n");
    for (int i=0;i<MAXPROVEEDORES;i++)
    {
        printf("\nProveedor: %s\n", proveedor[i].nombre);
        printf("Nombre\t\tCantidad\tPrecio Unitario\n");
        printf("-------------------------------------------------\n");

        for (int j=0;j<3;j++)
        {
            printf("%-16s\t%-8d\t$%.2f\n", proveedor[i].productos[j], proveedor[i].pedidos[*pusuario][j], proveedor[i].precios[j]);
        }
    }
    limpiarpantalla();
    return;
}
