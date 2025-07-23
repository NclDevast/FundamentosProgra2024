#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"
#include "string.h"
#include "windows.h"
#include "unistd.h"

struct perfilusuario
{
    char nombreusuario[50];
    char contrasenausuario[50];
} usuario1, usuario2, usuario3;

struct perfilproveedor
{
    char nombreproveedor[50];
    char contrasena[50];
    const char *menu[3];
    float precios[3];
} proveedor1, proveedor2, proveedor3;

    int pedidosmc[3][3]={0};
    int pedidosbk[3][3]={0};
    int pedidosmotes[3][3]={0};

int main(void)
{

strcpy(usuario1.nombreusuario, "Julia");
strcpy(usuario1.contrasenausuario, "EstrellaBonita2");

strcpy(usuario2.nombreusuario, "Jorge");
strcpy(usuario2.contrasenausuario, "contrasena1234");

strcpy(usuario3.nombreusuario, "Pedro");
strcpy(usuario3.contrasenausuario, "yy5bvUnFYc");


strcpy(proveedor1.nombreproveedor, "JuanMcdonanlds1234");
strcpy(proveedor1.contrasena, "asdfgh666");
proveedor1.menu[0] = "Big Mac";
proveedor1.menu[1] = "McMelt";
proveedor1.menu[2] = "McNuggets";
proveedor1.precios[0] = 6.5;
proveedor1.precios[1] = 8.99;
proveedor1.precios[2] = 4.99;

strcpy(proveedor2.nombreproveedor, "Burger King");
strcpy(proveedor2.contrasena, "un4PulG4aVentura2003");
proveedor2.menu[0] = "Whopper";
proveedor2.menu[1] = "Whopper Junior";
proveedor2.menu[2] = "Bk Nuggets";
proveedor2.precios[0] = 9.99;
proveedor2.precios[1] = 6.99;
proveedor2.precios[2] = 5.99;

strcpy(proveedor3.nombreproveedor, "Los motes de la Magdalena");
strcpy(proveedor3.contrasena, "contraseñaMotes");
proveedor3.menu[0] = "Mote con Chicharron";
proveedor3.menu[1] = "Motepillo";
proveedor3.menu[2] = "Llapingacho";
proveedor3.precios[0] = 5.25;
proveedor3.precios[1] = 3.00;
proveedor3.precios[2] = 5.99;

struct perfilusuario usuarios[] = {usuario1, usuario2, usuario3};
struct perfilproveedor proveedores[] = {proveedor1, proveedor2, proveedor3};

    int opcusuario=0;
    while(1)
    {
        printf("\nBienvenido! Escoja como desea iniciar\n1)Usuario\n2)Proveedor\n3)Salir\n");
        scanf("%d",&opcusuario);
        system("cls");
        switch(opcusuario)
        {
        case 1:
            {
                limpiarpantalla();
                menuusuario(usuarios,proveedores,3);
                break;
            }
        case 2:
            {
                limpiarpantalla();
                menuproveedor(usuarios,proveedores,3);
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
    //imprimirMatriz(pedidosmc); //debug
    }
}

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
                    printf("\n %d %s (%.2f)", pedidosmc[z][i], proveedores[*pproveedor].menu[i], proveedores[*pproveedor].precios[i]);
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
                    printf("\n %d %s (%.2f)", pedidosmotes[z][i], proveedores[*pproveedor].menu[i], proveedores[*pproveedor].precios[i]);
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
    system("cls");
    printf("\nCargando...");
    sleep(1.2);
    printf("Cargando...");
    sleep(1.2);
    system("cls");
}
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
            printf("\nProveedor no v�lido\n");
            break;
    }

    printf("\n");
    system("pause");
    limpiarpantalla();
}
