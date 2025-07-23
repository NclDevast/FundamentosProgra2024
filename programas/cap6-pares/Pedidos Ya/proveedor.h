#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#define MAX_PEDIDOS 3
#define NUM_PROVEEDORES 3

typedef struct
{
    int idPedido;
    int cliente;
}
PedidoProveedor;
typedef struct
{
    char nombre[50];
    PedidoProveedor pedidos[MAX_PEDIDOS];
    int numPedidos;
}
Proveedor;
void revisarPedidosProveedor(Proveedor *proveedor);
void confirmarEntrega(Proveedor *proveedor);

#endif
