#include "stdio.h"
#include "stdlib.h"

int leerarreglo(int arreglo[],int indice);
int compare_asc(const void *a,const void *b);
int compare_desc(const void *a,const void *b);
int sumaarreglo(int arreglo1[],int arreglo2[],int resultado[]);
int restaarreglo(int arreglo1[],int arreglo2[],int resultado[]);
void ordenarascendente(int arreglo[]);
void ordenardescendente(int arreglo[]);
void imprimirarreglo(int arreglo[]);

int main(void)
{
    int i=0;
    int arreglo1[3], arreglo2[3];
    int resultado_suma[3], resultado_resta[3];

    while (i<3)
    {
        arreglo1[i]=leerarreglo(arreglo1,i);
        i++;
    }

    i=0;
    while (i<3)
    {
        arreglo2[i]=leerarreglo(arreglo2, i);
        i++;
    }
    sumaarreglo(arreglo1,arreglo2,resultado_suma);
    printf("\nSuma de los arreglos: ");
    imprimirarreglo(resultado_suma);
    restaarreglo(arreglo1,arreglo2,resultado_resta);
    printf("\nResta de los arreglos: ");
    imprimirarreglo(resultado_resta);
    ordenarascendente(arreglo1);
    ordenarascendente(arreglo2);
    printf("\nArreglo 1 ordenado ascendentemente: ");
    imprimirarreglo(arreglo1);
    printf("\nArreglo 2 ordenado ascendentemente: ");
    imprimirarreglo(arreglo2);
    ordenardescendente(arreglo1);
    ordenardescendente(arreglo2);
    printf("\nArreglo 1 ordenado descendente: ");
    imprimirarreglo(arreglo1);
    printf("\nArreglo 2 ordenado descendente: ");
    imprimirarreglo(arreglo2);
}

int leerarreglo(int arreglo[],int indice)
{
    printf("Elemento[%i]: ",indice);
    scanf("%i",&arreglo[indice]);
    return arreglo[indice];
}

int compare_asc(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int compare_desc(const void *a,const void *b)
{
    return (*(int*)b-*(int*)a);
}

void ordenarascendente(int arreglo[])
{
    qsort(arreglo,3,sizeof(int),compare_asc);
}

void ordenardescendente(int arreglo[])
{
    qsort(arreglo,3,sizeof(int),compare_desc);
}

void imprimirarreglo(int arreglo[])
{
    for(int i=0;i<3;i++)
    {
        printf("%d ",arreglo[i]);
    }
    printf("\n");
}

int sumaarreglo(int arreglo1[],int arreglo2[],int resultado[])
{
    for(int i=0;i<3;i++)
    {
        resultado[i]=arreglo1[i]+arreglo2[i];
    }
}

int restaarreglo(int arreglo1[],int arreglo2[],int resultado[])
{
    for (int i=0;i<3;i++)
    {
        resultado[i]=arreglo1[i]-arreglo2[i];
    }
}
