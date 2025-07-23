#include "stdio.h"

int main()
{
    FILE *archivo;

    archivo=fopen("datos.txt","w");

    if(archivo==NULL)
    {
        printf("No se pudo abrir el archivo. \n");
        return 1;
    }

    fprintf(archivo, "hola mundo!");

    fclose(archivo);

    fopen("datos.txt","r");

    if(archivo==NULL)
    {
        printf("No se pudo abrir el archivo. \n");
        return 1;
    }
    char buffer[100];
    fscanf(archivo,"%[^\n]",buffer);
    printf("Contenido del archivo: %s\n",buffer);
    return 0;
}
