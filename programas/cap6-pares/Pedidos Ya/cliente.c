#include "cliente.h"
#include "main.h"

void hacerPedido(Cliente *cliente)
{
    if (cliente->numPedidos>=MAX_PEDIDOS)
    {
        printf("Has alcanzado el numero maximo de pedidos.\n");
        return;
    }

    int restaurante;
    printf("Selecciona un restaurante (0 a 4): ");
    scanf("%d", &restaurante);

    Pedido pedido;
    pedido.idPedido=cliente->numPedidos+1;
    pedido.restaurante=restaurante;

    cliente->pedidos[cliente->numPedidos]=pedido;
    cliente->numPedidos++;

    int proveedorIndex=numrand(NUM_PROVEEDORES);
    printf("Tu pedido ha sido asignado al proveedor %d\n", proveedorIndex);
}

void revisarPedidos(Cliente *cliente)
{
    printf("Pedidos del cliente %s:\n", cliente->nombre);
    for (int i=0; i< cliente->numPedidos; i++)
    {
        printf("Pedido %d: Restaurante %d\n", cliente->pedidos[i].idPedido, cliente->pedidos[i].restaurante);
    }
}

void cancelarPedido(Cliente *cliente)
 {
    int idPedido;
    printf("Introduce el ID del pedido a cancelar: ");
    scanf("%d", &idPedido);

    int found=0;
    for (int i=0; i<cliente->numPedidos; i++)
    {
        if (cliente->pedidos[i].idPedido==idPedido)
        {
            found=1;
            for (int j=i; j<cliente->numPedidos-1; j++)
            {
                cliente->pedidos[j]=cliente->pedidos[j + 1];
            }
            cliente->numPedidos--;
            printf("Pedido %d cancelado.\n", idPedido);
            break;
        }
    }

    if (!found)
    {
        printf("Pedido no encontrado.\n");
    }
}

