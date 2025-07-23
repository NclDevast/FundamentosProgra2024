#include "proveedor.h"
#include "main.h"

void revisarPedidosProveedor(Proveedor *proveedor)
{
    printf("Pedidos del proveedor %s:\n", proveedor->nombre);
    for (int i=0; i<proveedor->numPedidos; i++)
    {
        printf("Pedido %d: Cliente %d\n", proveedor->pedidos[i].idPedido, proveedor->pedidos[i].cliente);
    }
}

void confirmarEntrega(Proveedor *proveedor)
{
    int idPedido;
    printf("Introduce el ID del pedido a confirmar: ");
    scanf("%d", &idPedido);

    int found=0;
    for (int i=0; i<proveedor->numPedidos; i++)
    {
        if (proveedor->pedidos[i].idPedido==idPedido)
        {
            found=1;
            for (int j=i; j<proveedor->numPedidos-1; j++)
            {
                proveedor->pedidos[j]=proveedor->pedidos[j + 1];
            }
            proveedor->numPedidos--;
            printf("Pedido %d entregado.\n", idPedido);
            break;
        }
    }

    if (!found)
    {
        printf("Pedido no encontrado.\n");
    }
}
