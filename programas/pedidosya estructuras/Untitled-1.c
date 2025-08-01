#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "unistd.h"
#include "windows.h"

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

struct perfilcliente asignacioncliente(int i);
struct perfilproveedor asignacionproveedor(int i);
void menuusuario(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor);
int validacion(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor,int identificador,int *pusuario, int *pprovedor);
void hacerpedido(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int pusuario);
int proveedoraleatorio();
void revisarcarrito(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int pusuario);
void menuproveedor(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor);
void revisarpedidosproveedor(struct perfilcliente cliente[3],struct perfilproveedor proveedor[3],int pproveedor);
void limpiarpantalla();


int main(void)
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
        revisarcarrito(cliente,proveedor,usua);
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

    printf("\nUsted ha seleccionado %s por $%.2f!",proveedor[proveedorrand].productos[seleccion],proveedor[proveedorrand].precios[seleccion]);
    proveedor[proveedorrand].pedidos[pusuario][seleccion]++;

    printf("\n");
    system("pause");
    limpiarpantalla();

    return;
}

void revisarcarrito(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int pusuario)
{
    if (pusuario<0||pusuario>=MAXCLIENTES) 
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
            printf("%-16s\t%-8d\t$%.2f\n", proveedor[i].productos[j], proveedor[i].pedidos[pusuario][j], proveedor[i].precios[j]);
        }
    }
    printf("\n");
    system("pause");
    limpiarpantalla();
    return;
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

int proveedoraleatorio()
{
    int num;
    return num=rand()%3;
}

void menuproveedor(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor)
{
    int confirmacion,identificador=1,usua,prov,opc;
    int *pusuario=&usua, *pprovedor=&prov;

    confirmacion=validacion(cliente,proveedor,numClientes,numProveedor,identificador,pusuario,pprovedor);
    limpiarpantalla();

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
            return;

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
            printf("Nombre\t\tCantidad\tPrecio Unitario\n");
            printf("-------------------------------------------------\n");

            for (int j=0;j<3;j++) 
            {
                printf("%-16s\t%-8d\t$%.2f\n", proveedor[pproveedor].productos[j], proveedor[pproveedor].pedidos[i][j], proveedor[pproveedor].precios[j]);
            }
            printf("\n");
        
    }

    system("pause");
    limpiarpantalla();
    return;
}

void limpiarpantalla()
{
    sleep(1.25);
    printf("Cargando...");
    sleep(1.25);
    printf("Cargando...");
    system("cls");
}