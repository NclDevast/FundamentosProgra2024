#include "stdio.h"
#include "stdlib.h"
#include "math.h"
// las funciones de c.math utilizadas son POW, SQRT, COS,

float catetoopuesto, catetoadyacente, anguloadyancente, anguloopuesto, hip=0;
const float pi=3.1416; //se define a pi como una constante para cambiar de radianes a gradianes y visceversa
// se definen variables globales para la funcion main y los prototipos
float *CO=&catetoopuesto, *CA=&catetoadyacente, *AA=&anguloadyancente, *AO=&anguloopuesto,*HIP=&hip;
// se indican las variables globales a punteros para optimización de memoria

float hip1catetos (float *CO,float *CA); //calculo de hipotenusa segun catetos
float hip2opuestosCA (float *AO,float *CO); //calculo de hipotenusa segun angulos y catetos opuestos
float hip3adyacentesCA (float *AA,float *CA); //calculo de hipotenusa segun angulos y catetos adyacentes


// definicion de prototipos

int main (void)
{
    while (1)
    {
        int opcusuario=0;
        hip=0; //se inicializa la hipotenusa para que no se acumule
        printf("Calculadora de hipotenusas de triangulos rectangulos\nEscoja una opcion:\n1)Conozco la magnitud de 2 catetos\n");
        printf("2)Conozco la magnitud del cateto opuesto y el angulo opuesto\n");
        printf("3)Conozco la magnitud del cateto opuesto y angulo opuesto\n4)Salir\n");
        scanf("%d",&opcusuario);
        switch(opcusuario)
        {
            case 1:
            {
                hip1catetos(CO,CA); //lamado a hip1catetos
                printf("\nLa magnitud de la hipotenusa es %.2f\n",*HIP); // se imprime HIP retornado por la funcion con 2 decimales
                system("pause");
                system("cls");
                break;
            }
            case 2:
            {
                hip2opuestosCA (AO,CO); //llamado a hip2opuestoCA
                printf("\nLa magnitud de la hipotenusa es %.2f\n",*HIP); // se imprime HIP retornado por la funcion con 2 decimales
                system("pause");
                system("cls");
                break;
            }
            case 3:
            {
                hip3adyacentesCA (AA,CA); //llamado a hip3adyacentesCA
                printf("\nLa magnitud de la hipotenusa es %.2f\n",*HIP); // se imprime HIP retornado por la funcion con 2 decimales
                system("pause");
                system("cls");
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("\nOpcion invalida\n");
                system("pause");
                system("cls");
                break;
            }
            
        }
    }
    return 0;
}
float hip1catetos (float *CO,float *CA)
{
    system ("cls");
    printf("\nIndique la magnitud del cateto opuesto: ");
    scanf("%f",CO); // se lee el valor del cateto opuesto y se guarda su valor usando el puntero CO
    printf("\nIndique la magnitud del cateto adyacente: ");
    scanf("%f",CA); // se lee el valor del cateto adyacente y se guarda su valor usando el puntero CA
    *HIP=sqrt(pow(*CA,2)+pow(*CO,2)); // se calcula la hipotnusa usando el teorema de pitagoras
    return *HIP; //se retorna el valor de la hipotenusa a la funcion main a traves del puntero *HIP
}
float hip2opuestosCA (float *AO,float *CO)
{
    system ("cls");
    printf("\nIndique en gradianes el angulo opuesto: ");
    scanf("%f",AO); // se lee el valor del angulo opuesto y se guarda su valor usando el puntero AO
    printf("\nIndique la magnitud del cateto opuesto: ");
    scanf("%f",CO); // se lee el valor del cateto opuesto y se guarda su valor usando el puntero CO
    *HIP=*CO/cos(*AO*(pi/180)); //la funcion cos devuelve valores en radianes, para facilidad del usuario promedio se pide el angulo en gradianes
    //y el programa lo transforma a radianes usando la constante global pi establecida
    return *HIP; //se retorna el valor de la hipotenusa a la funcion main a traves del puntero *HIP
}
float hip3adyacentesCA (float *AA,float *CA)
{
    system ("cls");
    printf("\nIndique en gradianes el angulo opuesto: ");
    scanf("%f",AA); // se lee el valor del angulo adyacente y se guarda su valor usando el puntero AA
    printf("\nIndique la magnitud del cateto opuesto: ");
    scanf("%f",CA); // se lee el valor del cateto adyacente y se guarda su valor usando el puntero CA
    *HIP=*CO/cos(*AA*(pi/180)); //la funcion cos devuelve valores en radianes, para facilidad del usuario promedio se pide el angulo en gradianes
    //y el programa lo transforma a radianes usando la constante global pi establecida
    return *HIP; //se retorna el valor de la hipotenusa a la funcion main a traves del puntero *HIP
}

