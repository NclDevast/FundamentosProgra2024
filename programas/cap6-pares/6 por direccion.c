#include "stdio.h"

void esBisiesto(int *anio, int *bisiesto);
void verificacionmes(int *mes, int *mes_valido);
void verificaciondia(int *dia, int *mes, int *anio, int *dia_valido, int *mes_valido, int *anio_valido, int *bisiesto); //se agregaron punteros respectivos
void verificacionanio(int *anio, int *anio_valido);

int main(void)
{
    int dia=0,mes=0,anio=0,diavalido=0,mes_valido=0,anio_valido=0,bisiesto=0;//se agregaron variables para los parametros de verificaciondia
    int*dia_valido=&diavalido;//se establecio el puntero *dia_valido
    printf("Escriba el dia: ");
    scanf("%d", &dia);
    printf("\nEscriba el mes: ");
    scanf("%d", &mes);
    printf("\nEscriba el anio: ");
    scanf("%d", &anio);
    verificaciondia(&dia, &mes, &anio, dia_valido, &mes_valido, &anio_valido, &bisiesto);
    printf("\n%d", *dia_valido);
    if (*dia_valido == 1)
        printf("\nLa fecha %d/%d/%d es valida.", dia, mes, anio);
    else
        printf("\nLa fecha %d/%d/%d no es valida.", dia, mes, anio);
}

void verificaciondia(int *dia, int *mes, int *anio, int *dia_valido, int *mes_valido, int *anio_valido, int *bisiesto)
{
    *dia_valido=0; //se inicializo punteros correctamente
    *bisiesto=0;
    *mes_valido=0;
    *anio_valido=0;
    verificacionmes(mes, mes_valido);
    verificacionanio(anio, anio_valido);
    esBisiesto(anio, bisiesto); //no se agrega ampersand porque los parametros son punteros
   /* printf("\nmes: %d anio: %d bisiesto: %d",*mes_valido,*anio_valido,*bisiesto); linea para comprobar que los meses sean validos */ 

    if (*mes==2&&*bisiesto==1&&(*dia>0&&*dia<=29))
    {
        *dia_valido=1;
        printf("\nPrimera condicion");
    }
    else if (*mes_valido==1&&(*mes==1||*mes==3||*mes==5|| *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12) && (*dia > 0 && *dia <= 31))
    {
        *dia_valido=1;
        printf("\nSegunda condicion");
    }
    else if ((*mes_valido==1)&&(*mes==4||*mes==6||*mes==9||*mes==11)&&(*dia>0&&*dia<=30)) //se cambio condicion del if que incorrectamente tomaba a febrero dentro de esta condicion
    {
        *dia_valido=1;
        printf("\nTercera condicion");
    }
}

void esBisiesto(int *anio, int *bisiesto)
{
    *bisiesto=0;
    int q=0,r=0,s=0;
    if (*anio%4==0)
        (q)++;
    if (*anio%100!=0)
        (r)++;
    if (*anio%400==0)
        (s)++;
    if (q==1&&(r==1||s==1))
	    *bisiesto=1; //se cambio el puntero p a *bisiesto para que las funciones anteriores puedan leerla
}

void verificacionmes(int *mes, int *mes_valido)
{
    if (*mes<=0||*mes>12)
    {
        *mes_valido=0;
    }
    else
    {
        *mes_valido=1;
    }
}

void verificacionanio(int *anio, int *anio_valido)
{
    if (*anio<1582)
    {
        *anio_valido=0;
    }
    else
    {
        *anio_valido=1;
    }
}