#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "unistd.h"
#include "FUNCIONES.h"
#include "string.h"

extern struct cliente[3];
extern struct proveedor[3];


int proveedoraleatorio()
{
    int num;
    return num=rand()%3;
}

int validacion(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor,int identificador, int *pusuario, int *pprovedor)
{
    int i,opc=-1;
    char contrasenainput[50];

    switch(identificador)
    {
        case 0:
        printf("\nSeleccione quien va a comer hoy:\n");
        for(i=0;i<3;i++)
        {
            printf("%d)%s\n",i+1,cliente[i].nombre);
        }
        scanf("%d",&opc);
        getchar();
        opc--;
        if(opc<0||opc>MAXCLIENTES)
        {
            printf("\nOpcion Invalida!");
            limpiarpantalla();
            return -1;
        }

        limpiarpantalla();

        printf("\nIngrese su contrasena: ");

        fgets(contrasenainput,sizeof(contrasenainput),stdin);
        contrasenainput[strcspn(contrasenainput,"\n")]='\0';

        if(strcmp(contrasenainput,cliente[opc].contrasena)!=0)
        return -1;
        else
        {
            *pusuario=opc;
            return 0;
        }


        break;

        case 1:

        printf("\nSeleccione quien va a laburar hoy: ");
        for(i=0;i<3;i++)
        {
            printf("\n%d)%s\n",i+1,proveedor[i].nombre);
        }
        scanf("%d",&opc);
        getchar();
        opc--;
        if(opc<0||opc>MAXCLIENTES)
        {
            printf("\nOpcion Invalida!");
            limpiarpantalla();
            return -1;
        }

        limpiarpantalla();

        printf("\nIngrese su contrasena: \n");
        fgets(contrasenainput,sizeof(contrasenainput),stdin);
        contrasenainput[strcspn(contrasenainput,"\n")]='\0';

        if(strcmp(contrasenainput,proveedor[opc].contrasena)!=0)
        return -1;
        else
        {
            *pprovedor=opc;
            return 0;
        }

        break;
    }
}

void limpiarpantalla()
{
    sleep(1.25);
    printf("Cargando...");
    sleep(1.25);
    printf("Cargando...");
    system("cls");
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

