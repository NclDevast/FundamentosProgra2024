#include "stdio.h"
#include "stdlib.h"
#include "time.h" //se utiliza para obtener una semilla diferente para generar el numero pseudoaleatorio dependiente del tiempo actual
#include "stdbool.h" //se utiliza para simplificar la seleccion de usuario entre 2 parametros definidos

// las funciones de stdlib usadas fueron: exit (), rand(), srand(), system().

int dinerousuario=100; // se define dinerousuario como una variable global
int *ptr1=&dinerousuario; //se define ptr1 como puntero a la direccion de la variable global

int chohan (int *ptr1);
int main(void)
{
int opcusuario;

while(1) //El bucle correrá mientras el usuario seleccione seguir jugando
{
if (*ptr1<=0) //se analiza que el usuario tenga dinero para seguir jugando
    {
        printf("\nLo sentimos, parece que se ha quedado sin dinero, le pediremos que se retire.");
        printf("\n");   
        system("pause");
        exit(0); // si el jugador no tiene suficiente dinero se termina el programa
    }
printf("Bienvenido al casino, su dinero es $%d\n",*ptr1);
printf("Escoja su juego:\n1)Cho-han(par o impar)\n2)Salir\n");
scanf("%d",&opcusuario);
switch (opcusuario)
{
    case 1:
    {
        chohan(ptr1); //Llamado a funcion chohan
        system("cls"); // se limpia la consola despues de retornar de la funcion chohan
        break;
    }
    case 2:
    {
        system("cls");
        printf("\nSu dinero final es $%d",*ptr1);
        printf("\n");
        system("pause");
        exit(0); //si el jugador escoge salir se mostrará su saldo actual y se cerrará el programa
    }
    default:
    {
        printf("\nOpcion no valida");
        break;
    }
}
}
}

int chohan(int *ptr1)
{
int dado1=0, dado2=0, decision=0, apuesta, confirmacion=0,confirmacion2=0, suma=0;
bool par=false, impar=false;
//se inicializan todas las variables cada que se ejecuta el prototipo
int *d1=&dado1,*d2=&dado2, *a=&apuesta, *s=&suma;
system("cls"); // se limpia los mensajes impresos previamente
printf("Cho-Han significa par o impar, se lanzaran dos dados y debe adivinar si la suma es par o impar\n");
while(confirmacion==0)
{
    printf("Introduzca su apuesta: ");
    scanf("%d",a); // se lee el input del usuario y se lo guarda en la variable apuesta mediante el puntero "*a"
    if(*a>*ptr1||*a<=0) printf("\nSu apuesta es mas grande que su dinero actual, o es un numero invalido, intente de nuevo\n");
    else confirmacion++;
}
system ("cls");
printf("Escoja si su numero es: 1)par 2)impar\n");
while(confirmacion2==0)
{
scanf("%d",&decision);
switch(decision)
{
    case 1:
    {
        confirmacion2++;
        par=true;
        break;
    }
    case 2:
    {
        confirmacion2++;
        impar=true;
        break;
    }
    default:
    {
        printf("\nOpcion invalida\n");
        break;
    }
}
}
srand(time(NULL));
*d1=rand()%6+1;
// se determina el rango del numero aleatorio con la formula "NUM % (N - M + 1 ) + M " , donde M es el limite inferior y N el superior
// entonces para simular un dado el limite mayor es 6 y el menor 6 (6-1+1) + 1 = -> NUM % 6 + 1
printf("El primer dado es: %d",*d1);
printf("\n");
system("pause"); 
*d2=rand()%6+1; // Se aplica la misma logica
printf("\nEl segundo dado es: %d",*d2);
*s=*d1+*d2; // se calcula la suma de los dados
printf("\nLa suma de los dados es: %d",*s);
if(*s%2==0&&par==true) // se verifica si la suma de los dados es par y si la opcion escogida por el usuario es par
{
    *ptr1=*ptr1+(*a*2); //se duplica la cantidad apostada y se suma como contador
    printf("\nGanaste!, tu dinero actual es: $%d",*ptr1);
    printf("\n");
    system("pause");
}
else if (*s%2!=0&&impar==true) //se verifica si la suma de los dados es impar y si la opcion escogida por el usuario es impar
{
    *ptr1=*ptr1+(*a*2); //se duplica la cantidad apostada y se suma como contador
    printf("\nGanaste!, tu dinero actual es: $%d",*ptr1);
    printf("\n");
    system("pause");

}
else // de no cumplir las condiciones para ganar, el usuario pierde
{
    *ptr1=*ptr1-*a;
    printf("\nPerdiste, tu dinero actual es: $%d",*ptr1);
    printf("\n");
    system("pause");

}
return *ptr1;
}