#ifndef FUNCIONES1_H_INCLUDED
#define FUNCIONES1_H_INCLUDED

//void menuprincipal(int *perfilusuario, int *perfilproveedor);
void menuusuario(int *perfilusuario, int *perfilproveedor); // muestra el menu del usuario y sus opciones
int seleccionusuario(int *confirmacion, int *seleccionusuario); // permite ingresar al programa como un usuario especifico, retorna una confirmacion de inicio de sesion
void hacerpedido (int *perfilusuario, int usuario, int *perfilproveedor); // permite hacer una orden al usuario seleccionado
int opcionrestaurante(int *perfilusuario); // Permite al usuario seleccionar un restaurante para ordener
/*void restauranteacumlador(int *perfilusuario); vestigio */
void seleccionproveedorrand (int *perfilproveedor, int eleccionrestaurante); // Asigna a un proveedor aleatoriamente cuando a la orden hecha por el usuario
void menuproveedor(int *perfilproveedor, int  *perfilusuario); //realizar
int seleccionproveedor(int *confirmacion, int *perfilproveedor); //realizar
void imprimirMatriz(int perfilusuario[6][3]); //Funcion debugging




#endif // FUNCIONES1_H_INCLUDED
