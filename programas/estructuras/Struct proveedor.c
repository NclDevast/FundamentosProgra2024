#include"stdio.h"
#include"string.h"
struct Persona
{
    char nombre[20];
    char apellido[20];
    int edad;
};

void imprimirPersona(struct Persona p);

struct Persona lecturaPersona();

int main(void)
{
    struct Persona a[3];
    int i;

    for(i=0;i<3;i++)
    {
        printf("Lectura de Datos Persona[%i]\n",i);
        a[i]=lecturaPersona();
    }


    for(i=0;i<3;i++)
    {
        printf("\n");
        imprimirPersona(a[i]);
    }
}
void imprimirPersona(struct Persona p)
{
    printf("Nombre>%s           ",p.nombre);
    printf("Apellido>%s           ",p.apellido);
    printf("Edad>%i           ",p.edad);
}
struct Persona lecturaPersona()
{
    struct Persona p;
    printf("Ingrese nombre:");
    fgets(p.nombre,20,stdin);
    p.nombre[strcspn(p.nombre,"\n")]=0;

    printf("Ingrese apellido:");
    fgets(p.apellido,20,stdin);
    p.apellido[strcspn(p.apellido,"\n")]=0;

    printf("Ingrese edad:");
    scanf("%i",&p.edad);
    getchar();

    return p;
}
