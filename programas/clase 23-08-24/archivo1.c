#include "stdio.h"
#include "string.h"

struct datos
{
    char nombre[50];
    char apellido[50];
    int edad;
};

struct datos leerdatos();
void imprimirdatos(struct datos d);

int main(void)
{
    FILE *archivo;

    struct datos inp[1];

    archivo=fopen("datos.txt","w");

    if(archivo==NULL)
    {
        printf("No se pudo abrir el archivo. \n");

        return 1;
    }

    inp[1]=leerdatos();

    imprimirdatos(inp[1]);

    fclose(archivo);

    return 0;
}

void imprimirdatos(struct datos d)
{
    FILE *archivo;
    fprintf(archivo,"Nombre>%s           ",d.nombre);
    fprintf(archivo,"Apellido>%s           ",d.apellido);
    fprintf(archivo,"Edad>%i ",d.edad);
}

struct datos leerdatos()
{
    struct datos d1;
    printf("\nIngrese el Nombre ");
    fgets(d1.nombre,50,stdin);
    d1.nombre[strcspn(d1.nombre,"\n")]='\0';
    printf("\nIngrese el Apellido ");
    fgets(d1.apellido,50,stdin);
    d1.apellido[strcspn(d1.apellido,"\n")]='\0';
    printf("\nIngrese la edad ");
    scanf("%d",&d1.edad);
    getchar();
}
