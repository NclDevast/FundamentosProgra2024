#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menuusuario(struct perfilusuario *usuarios, struct perfilproveedor *proveedores, int num_proveedores)
void menuproveedor(struct perfilusuario *usuarios, struct perfilproveedor *proveedores, int num_proveedor);
void hacerpedido(struct perfilproveedor *proveedores, int usuarioid, float *pcarrito1, float *pcarrito2, float *pcarrito3);
void revisarpedido(struct perfilproveedor proveedor, int *pusuario);
void imprimirordenes(struct perfilproveedor proveedor, int *pusuario, int restaurante);
void revisarpedidoproveedor(struct perfilproveedor *proveedores, int *pproveedor, struct perfilusuario *usuarios);
int seleccionproveedorrand ();
int validacion(struct perfilusuario *usuarios, struct perfilproveedor *proveedores, int identificador, int *pusuario, int *pproveedor);
void imprimirMatriz(int pedidos[3][3]);
void limpiarpantalla();
int seleccionitem();

#endif // FUNCIONES_H_INCLUDED
