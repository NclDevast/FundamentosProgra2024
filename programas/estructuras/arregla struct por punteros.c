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
    struct Persona *p1;
    int i;
    for(i=0;i<3;i++)
    {
        printf("Lectura de Datos Personas[%i]\n",i);
        printf("\nIngrese nombre:");
        fgets(p1->nombre,20,stdin);
        p1->nombre[strcspn(p1->nombre,"\n")]=0;

        printf("\nIngrese apellido:");
        fgets(p1->apellido,20,stdin);
        p1->apellido[strcspn(p1->apellido,"\n")]=0;

        printf("\nIngrese edad:");
        scanf("%i",p1->edad);
        getchar();
    }
    printf("ID       Nombre     Apellido     Edad");
    for(i=0;i<3;i++)
    {
        printf("[%i]        ",i);
        printf("%s        ",p1->nombre);
        printf("%s        ",p1->apellido);
        printf("%i        ",p1->edad);
    }
}
