#include "stdio.h"
#include "string.h"
struct colecciones_cd
{
    char titulo[30];
    char artista [30];
    int num_canciones;
    float precio;
    char fecha[8];
};
struct artista
{
    char nombre[20];
    char apellido[20];
    int edad;
    char ciudad[20];

};
int main(void)
{
    struct colecciones_cd cd1;
    strcpy(cd1.titulo,"Animales");
    strcpy(cd1.artista,"Maroon5");
    cd1.num_canciones=18;
    cd1.precio=88.5;
    strcpy(cd1.fecha,"12/9/05");

    printf("Su objeto incializado es>\n");
    printf("\nAlbum:%s",cd1.titulo);
    printf("\nArtista %s",cd1.artista);
    printf("\nCanciones %i",cd1.num_canciones);
    printf("\nPrecio:%2f",cd1.precio);
    printf("\nFecha:%s\n",cd1.fecha);

    struct artista artista1;
    strcpy(artista1.nombre,"Animales");
    strcpy(artista1.apellido,"Maroon5");
    strcpy(artista1.ciudad,"Mexico");
    artista1.edad=18;
    printf("\nSu objeto incializado es>\n");
    printf("\nAlbum:%s",artista1.nombre);
    printf("\nArtista:%s",artista1.apellido);
    printf("\nCanciones:%s",artista1.ciudad);
    printf("\nEdad:%i",artista1.edad);
}
