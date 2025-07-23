#include "stdio.h"
#include "stdlib.h"
#include "FUNCIONES.h"

void menuusuario(int *perfilusuario, int *perfilproveedor)
{
    int opcusuario=0,usuario=-1;
    confirmacion=validacionusuario(perfilusuario);
    if(usuario<0);
    {
        printf("\nUsuario o contrasena incorrecta");
        return;
    }
    else
    printf("\nBienvenido!");
}
int validacionusuario(int *perfilusuario)
{
    int confirmacion=0,opcusuario=0;
    char contrasena;
    printf("\nEscoja su usuario:");
    for (int i=1;i<=3;i++)
    {
        printf("\n%i)Usuario %i.",i);
    }
    scanf("%d",opcusuario);
    printf("\nIngrese su contrasena: ");
    scanf("%c",&contrasena);
    if(contrasena=!perfilusuario[opcusuario-1]||opcusuario<1||opcusuario>3)
        return -1;
}
