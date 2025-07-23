#include "stdio.h"
#include "string.h"

struct Persona
{
    char nombre[20];
    char apellido[20];
    int edad;
};

void imprimirpersona(struct Persona p);

int main(void)
{
    struct Persona p[3];
    int i;

    for (i=0; i<3; i++)
        {
        printf("Ingrese nombre: ");
        if (fgets(p[i].nombre, sizeof(p[i].nombre), stdin)!=NULL)
        {
            p[i].nombre[strcspn(p[i].nombre, "\n")]='\0';
        }

        printf("Ingrese apellido: ");
        if (fgets(p[i].apellido, sizeof(p[i].apellido), stdin)!=NULL)
        {

            p[i].apellido[strcspn(p[i].apellido, "\n")]='\0';
        }

        printf("Ingrese Edad: ");
        if (scanf("%d", &p[i].edad)!=1)
        {
            printf("Error al leer la edad.\n");
            return 1;
        }

        getchar();
    }
    for(i=0;i<3;i++)
    imprimirpersona(p[i]);
    }


void imprimirpersona(struct Persona p)
{
        printf("\nNombre: %s", p.nombre);
        printf("\nApellido: %s", p.apellido);
        printf("\nEdad: %d", p.edad);
        printf("\n");
}
