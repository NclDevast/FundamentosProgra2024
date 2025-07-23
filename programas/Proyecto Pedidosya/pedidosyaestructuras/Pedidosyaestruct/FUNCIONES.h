#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct perfilcliente asignacioncliente(int i);
struct perfilproveedor asignacionproveedor(int i);
void menuusuario(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor);
int validacion(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor,int identificador,int *pusuario, int *pprovedor);
void hacerpedido(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int pusuario);
int proveedoraleatorio();
void revisarcarrito(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int *pusuario);
void menuproveedor(struct perfilcliente cliente[3], struct perfilproveedor proveedor[3], int numClientes, int numProveedor);
void revisarpedidosproveedor(struct perfilcliente cliente[3],struct perfilproveedor proveedor[3],int pproveedor);
void limpiarpantalla();


#endif // FUNCIONES_H_INCLUDED
