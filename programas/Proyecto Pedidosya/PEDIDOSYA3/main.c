#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"
#include "string.h"

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
