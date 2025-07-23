#include "main.h"
#include "cliente.h"
#include "proveedor.h"

Cliente clientes[NUM_CLIENTES];
Proveedor proveedores[NUM_PROVEEDORES];

void menucliente()
 {
    int opcion;
    printf("Menu Cliente\n");
    printf("1. Hacer Pedido\n");
    printf("2. Revisar Pedidos\n");
    printf("3. Cancelar Pedido\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    int clienteIndex;
    printf("Seleccione su usuario (0 a 2): ");
    scanf("%d", &clienteIndex);

    switch(opcion)
    {
        case 1:
            hacerPedido(&clientes[clienteIndex]);
            break;
        case 2:
            revisarPedidos(&clientes[clienteIndex]);
            break;
        case 3:
            cancelarPedido(&clientes[clienteIndex]);
            break;
        default:
            printf("Opción no válida\n");
    }
}

void menuproveedor()
{
    int opcion;
    printf("Menu Proveedor\n");
    printf("1. Revisar Pedidos\n");
    printf("2. Confirmar Entrega\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    int proveedorIndex;
    printf("Seleccione su usuario (0 a 2): ");
    scanf("%d", &proveedorIndex);

    switch(opcion)
    {
        case 1:
            revisarPedidosProveedor(&proveedores[proveedorIndex]);
            break;
        case 2:
            confirmarEntrega(&proveedores[proveedorIndex]);
            break;
        default:
            printf("Opción no válida\n");
    }
}
int numrand(int max)
{
    return rand()%max;
}

int main()
{
    srand(time(NULL));
    int opcion;
    printf("Bienvenido a PedidosYa\n");
    printf("1. Iniciar como Cliente\n");
    printf("2. Iniciar como Proveedor\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            menucliente();
            break;
        case 2:
            menuproveedor();
            break;
        default:
            printf("Opción no válida\n");
    }
}
