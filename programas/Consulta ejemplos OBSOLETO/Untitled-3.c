#include "stdio.h"
#include "stdlib.h"

int calculo1(int a, int b);
int calculo2(int a, int b);

int main (void)
{
    int a,b,opcusuario,s;
    int*ptr=&a,*ptr2=&b;
        printf("Calculadora de numeros naturales, suma y resta");
        printf("\nIngrese su primer numero mayor a cero: ");
        scanf("%d",ptr);
        if (*ptr<=0) // se comprueba que el numero sea parte de los numeros naturales
        {
            printf("\nNumero invalido");
            printf("\n");
            system("pause"); //se pausa el proceso hasta que el usuario presione una tecla
            abort(); // Si no es un numero natural, se cierra el proceso
        }
        printf("\nIngrese su segundo numero mayor a cero: ");
        scanf("%d",ptr2);
        if (*ptr2<=0) // se comprueba que el segundo numero sea parte de los numeros naturales
        {
            printf("\nNumero invalido");
            printf("\n");
            system("pause"); //se pausa el proceso hasta que el usuario presione una tecla
            abort(); // Si no es un numero natural, se cierra el proceso
        }
        system("cls"); // se borra los datos impresos en la terminal, solo funciona en windows
        printf("\nSeleccione su operacion\n1) Suma\n2) Resta\n");
        scanf("%d",&opcusuario);
        switch (opcusuario)
        {
            case 1:
            {
                system ("cls"); // se borra los datos impresos en la terminal, solo funciona en windows
                s = calculo1(a,b); //llamado a la funcion calculo1
                if (s<0) //se verifica si el resultado no forma parte de los reales
                {
                    printf("Hubo un error en el calculo\n"); // se imprime un mensaje de error
                    printf("\n");
                    system("pause"); //se pausa el proceso hasta que el usuario presione una tecla 
                    abort();  // Si el resultado no es un numero natural, se cierra el proceso
                }
                else printf("\nEl resultado es: %d",s);
                printf("\n");
                system("pause");
                break;
            }
            case 2:
            {
                system ("cls"); // se borra los datos impresos en la terminal, solo funciona en windows
                s = calculo2(a,b); //llamado a la funcion calculo2
                if (s<0) //se verifica si el resultado no forma parte de los reales
                {
                    printf("Hubo un error en el calculo\n"); //se imprime un mensaje de error
                    printf("\n");
                    system("pause"); //se pausa el proceso hasta que el usuario presione una tecla 
                    abort(); // Si el resultado no es un numero natural, se cierra el proceso
                }
                else printf("El resultado es: %d",s);
                printf("\n");
                system ("pause");
                break;
            }
            default: //Control si la opcion escogida no es valida
            {
                system("cls"); // se borra los datos impresos en la terminal, solo funciona en windows
                printf("Opción no valida\n"); //se imprime un mensaje de error
                printf("\n");
                system("pause"); //se pausa el proceso hasta que el usuario presione una tecla 
                abort(); // Si el resultado no es un numero natural, se cierra el proceso
            }
        }
    return 0;
}

int calculo1(int a,int b)
{
    return a+b;
}
int calculo2(int a,int b)
{
    return a-b;
}