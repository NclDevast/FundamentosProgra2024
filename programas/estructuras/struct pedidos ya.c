#include "stdio.h"
#include "string.h"

struct usuario
{
    char nombre_usuario[30];
    char contrasena[30];
};

int main(void)
{
    struct usuario usuario1;
    char contrasena_ingresada[30];

    printf("Ingrese su nombre: ");
    fgets(usuario1.nombre_usuario, 30, stdin);
    usuario1.nombre_usuario[strcspn(usuario1.nombre_usuario, "\n")]=0;

    printf("Cree su contrasena: ");
    fgets(usuario1.contrasena, 30, stdin);
    usuario1.contrasena[strcspn(usuario1.contrasena, "\n")]=0;

    printf("Ingrese su contrasena para acceder: ");
    fgets(contrasena_ingresada, 30, stdin);
    contrasena_ingresada[strcspn(contrasena_ingresada, "\n")]=0;
    if (strcmp(usuario1.contrasena, contrasena_ingresada)==0)
    {
        printf("\nAcceso concedido.\n");
        printf("Su objeto inicializado es:\n");
        printf("Nombre: %s\n", usuario1.nombre_usuario);
        printf("Contrasena: %s\n", usuario1.contrasena);
    }
    else
    {
        printf("\nAcceso denegado. Contraseña incorrecta.\n");
    }
}

