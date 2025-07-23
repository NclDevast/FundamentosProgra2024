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
    printf("Ingrese nombre de cd>");
    fgets(cd1.titulo,30,stdin);
    cd1.titulo[strcspn(cd1.titulo,"\n")]=0;

    printf("Ingrese nombre de artista>");
    fgets(cd1.artista,30,stdin);
    cd1.artista[strcspn(cd1.artista,"\n")]=0;

    printf("Ingrese cantidad de canciones>");
    scanf("%i",&cd1.num_canciones);
    getchar();

    printf("Ingrese precio>");
    scanf("%f",&cd1.precio);
    getchar();

    printf("Su objeto incializado es>\n");
    printf("\nAlbum:%s",cd1.titulo);
    printf("\nArtista %s",cd1.artista);
    printf("\nCanciones %i",cd1.num_canciones);
    printf("\nPrecio:%2f",cd1.precio);
    printf("\nFecha:%s\n",cd1.fecha);

    struct artista artista1;
    printf("Ingrese nombre de artista>");
    fgets(artista1.nombre,20,stdin);
    artista1.nombre[strcspn(artista1.nombre,"\n")]=0;

    printf("Ingrese apellido de artista>");
    fgets(artista1.apellido,20,stdin);
    artista1.apellido[strcspn(artista1.apellido,"\n")]=0;

    printf("Ingrese ciudad de artista>");
    fgets(artista1.ciudad,20,stdin);
    artista1.ciudad[strcspn(artista1.ciudad,"\n")]=0;

    printf("Ingrese edad>");
    scanf("%f",&artista1.edad);
    getchar();


    printf("\nSu objeto incializado es>\n");
    printf("\nAlbum:%s",artista1.nombre);
    printf("\nArtista:%s",artista1.apellido);
    printf("\nCanciones:%s",artista1.ciudad);
    printf("\nEdad:%i",artista1.edad);
}
