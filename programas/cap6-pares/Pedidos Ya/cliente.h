#ifndef CLIENTE_H
#define CLIENTE_H
#define MAX_PEDIDOS 3
#define NUM_CLIENTES 3
#define NUM_RESTAURANTES 5

typedef struct
{
    int idPedido;
    int restaurante;
}
Pedido;
typedef struct
{
    char nombre[50];
    Pedido pedidos[MAX_PEDIDOS];
    int numPedidos;
}
Cliente;
void hacerPedido(Cliente *cliente);
void revisarPedidos(Cliente *cliente);
void cancelarPedido(Cliente *cliente);

#endif
