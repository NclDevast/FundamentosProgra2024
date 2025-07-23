#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"
#include "string.h"

#define MAXCLIENTES 3
#define MAXPROVEEDORES 3

struct perfilcliente
{
    char nombre[50];
    char contrasena[50];
};

struct perfilproveedor
{
    char nombre[50];
    char contrasena[50];
    char *productos[3];
    float precios[3];
    int pedidos[3][3];
};

int main()
{
    srand(time(NULL));
    struct perfilcliente cliente[3];
    struct perfilproveedor proveedor[3];

    int i, opc,menu=0,seleccion;
    for(i=0;i<3;i++) //asignacion de datos de clientes y proveedor
    {
        cliente[i]=asignacioncliente(i);
        proveedor[i]=asignacionproveedor(i);
    }

    while(menu==0)
    {
    printf("\nBienvenido! Elija si desea iniciar como\n1)Cliente\n2)Proveedor\n3)Salir\n");
    scanf("%d",&opc);
    getchar();

    switch(opc)
        {
            case 1:
            limpiarpantalla();
            menuusuario(cliente, proveedor,MAXCLIENTES, MAXPROVEEDORES);
            break;

            case 2:
            limpiarpantalla();
            menuproveedor(cliente, proveedor,MAXCLIENTES, MAXPROVEEDORES);
            break;

            case 3:
            exit(0);

            default:
            break;

        }
    }

}

struct perfilcliente asignacioncliente(int i)
{
    struct perfilcliente p;
    char *nombres[3]={"Julia","Jorge","David"};
    char *contrasenas[3]={"Julia1234","contrasena1234","asdf1234"};

    strcpy(p.nombre,nombres[i]);
    strcpy(p.contrasena,contrasenas[i]);

    return p;

}

struct perfilproveedor asignacionproveedor(int i)
{
    struct perfilproveedor p;
    char *nombres[3]={"McDonalds","KFC","Burger King"};
    char *contrasenas[3]={"RonaldMcdonald1234","JorgeKFC321","contrasenasegura1234"};
    char *menuMc[3]={"BigMac","McNuggets","Cuarto de libra"};
    char *menuKFC[3]={"Cubeta Familiar 16pc","Conazo","Combo economico"};
    char *menuBK[3]={"Whooper Jr","Bacon King","BK nuggets"};
    const float pmenuMC[3]={5.99,3.99,6.99};
    const float pmenuKFC[3]={12.99,4.99,2.99};
    const float pmenuBK[3]={5.99,9.99,4.99};
    int j,k;

    strcpy(p.nombre,nombres[i]);
    strcpy(p.contrasena,contrasenas[i]);

    switch(i)
{
    case 0:
        for(j=0;j<3;j++)
        {
        p.productos[j]=menuMc[j];
        p.precios[j]=pmenuMC[j];
        for(k=0;k<3;k++)
        p.pedidos[j][k]=0;
        }

        break;
    case 1:
    for(j=0;j<3;j++)
        {
        p.productos[j]=menuKFC[j];
        p.precios[j]=pmenuKFC[j];
        for(k=0;k<3;k++)
        p.pedidos[j][k]=0;
        }
        break;
    case 2:
        for(j=0;j<3;j++)
        {
        p.productos[j]=menuBK[j];
        p.precios[j]=pmenuBK[j];
        for(k=0;k<3;k++)
        p.pedidos[j][k]=0;
        }
        break;
    default:
        break;

}
return p;
}
