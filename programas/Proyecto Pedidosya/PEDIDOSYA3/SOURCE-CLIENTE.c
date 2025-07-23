#include "stdio.h"
#include "stdlib.h"
#include "FUNCIONES.h"
#include "string.h"

void menuusuario(struct perfilusuario *usuarios, struct perfilproveedor *proveedores, int num_proveedores)
{
    int opcmenu,menu=0,identificador=0,confirmacion=0;
    float carrito1=0,carrito2=0,carrito3=0;
    int usuarioid=0;
    int *pusuario=&usuarioid;
    int proveedorid=0;
    int *pproveedor=&proveedorid;

    confirmacion=validacion(usuarios, proveedores, identificador, pusuario, pproveedor);

    if (confirmacion<0)
    {
        limpiarpantalla();
        printf("\nUsuario o contrasena incorrecta\n");
        system("pause");
        system("cls");
        return;
    }

    while (menu==0)
    {
        printf("\nSeleccione su opcion:\n1) Hacer pedido\n2) Revisar pedidos\n3) Salir\n");
        scanf("%d", &opcmenu);

        switch (opcmenu)
        {
            case 1:
                hacerpedido(proveedores, usuarioid, &carrito1, &carrito2, &carrito3);
                break;
            case 2:
                revisarpedido(proveedores[*pusuario], pusuario); // Pasa el proveedor correcto
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


void hacerpedido(struct perfilproveedor *proveedores, int usuarioid, float *pcarrito1, float *pcarrito2, float *pcarrito3)
{
    extern int pedidosmc[3][3];
    extern int pedidosbk[3][3];
    extern int pedidosmotes[3][3];

    int itemordenado;
    int proveedorid = seleccionproveedorrand();  // Selección aleatoria del proveedor

    printf("\nBienvenido a %s!\nMenu:\n",proveedores[proveedorid].nombreproveedor);
    for (int i=0;i<3;i++)
    {
        printf("%d) %s $%.2f\n",i+1,proveedores[proveedorid].menu[i],proveedores[proveedorid].precios[i]);
    }

    itemordenado=seleccionitem();

    if (itemordenado==-1)
        return;

    if (strcmp(proveedores[proveedorid].nombreproveedor, "JuanMcdonanlds1234")==0)
    {
        pedidosmc[usuarioid][itemordenado-1]++;
    }
    else if (strcmp(proveedores[proveedorid].nombreproveedor, "Burger King")==0)
    {
        pedidosbk[usuarioid][itemordenado-1]++;
    }
    else if (strcmp(proveedores[proveedorid].nombreproveedor, "Los motes de la Magdalena")==0)
    {
        pedidosmotes[usuarioid][itemordenado-1]++;
    }

    printf("\nUsted ha ordenado: %s por $%.2f!\n", proveedores[proveedorid].menu[itemordenado-1], proveedores[proveedorid].precios[itemordenado - 1]);
}

void revisarpedido(struct perfilproveedor proveedor, int *pusuario)
{
    printf("\nPedidos para %s:\n",proveedor.nombreproveedor);
    imprimirordenes(proveedor,pusuario,0);
    system("pause");
    system("cls");
}



void imprimirordenes(struct perfilproveedor proveedor, int *pusuario, int restaurante)
{
    extern int pedidosmc[3][3];
    extern int pedidosbk[3][3];
    extern int pedidosmotes[3][3];

    for (int i=0;i<3; i++)
    {
        if (strcmp(proveedor.nombreproveedor, "JuanMcdonanlds1234")==0)
        {
            printf("\n%s: %d", proveedor.menu[i], pedidosmc[*pusuario][i]);
        }
        else if (strcmp(proveedor.nombreproveedor, "Burger King")==0)
        {
            printf("\n%s: %d", proveedor.menu[i], pedidosbk[*pusuario][i]);
        }
        else if (strcmp(proveedor.nombreproveedor, "Los motes de la Magdalena")==0)
        {
            printf("\n%s: %d", proveedor.menu[i], pedidosmotes[*pusuario][i]);
        }
    }
}
