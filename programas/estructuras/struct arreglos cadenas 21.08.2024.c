#include "stdio.h"
#include "string.h"
struct Persona
{
    char nombre[20];
    char apellido[20];
    int edad;
};
int main (void)
{
    struct Persona p1[3];
    int i;
    for(i=0;i<3;i++)
    {
        printf("Lectura de Datos Personas[%i]\n",i);
        printf("\nIngrese nombre:");
        fgets(p1[i].nombre,20,stdin);
        p1[i].nombre[strcspn(p1[i].nombre,"\n")]=0;

        printf("\nIngrese apellido:");
        fgets(p1[i].apellido,20,stdin);
        p1[i].apellido[strcspn(p1[i].apellido,"\n")]=0;

        printf("\nIngrese edad:");
        scanf("%i",&p1[i].edad);
        getchar();
    }
    printf("ID       Nombre     Apellido     Edad");
    for(i=0;i<3;i++)
    {
        printf("[%i]        ",i);
        printf("%s        ",p1[i].nombre);
        printf("%s        ",p1[i].apellido);
        printf("%i        ",p1[i].edad);
    }

}
