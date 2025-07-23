#include <stdio.h>
int esBisiesto(int *anio);
int verificacionmes(int *mes);
int verificaciondia(int *dia, int *mes, int *anio);
int verificacionanio(int *anio);

int main(void)
{
    int dia = 0, mes = 0, anio = 0, dia2 = 0;
    printf("Escriba el dia: ");
    scanf("%d", &dia);
    printf("\nEscriba el mes: ");
    scanf("%d", &mes);
    printf("\nEscriba el anio: ");
    scanf("%d", &anio);
    dia2 = verificaciondia(&dia, &mes, &anio);
    printf("\n%d", dia2);
    if (dia2 == 1)
        printf("\nLa fecha %d/%d/%d es valida.", dia, mes, anio);
    else
        printf("\nLa fecha %d/%d/%d no es valida.", dia, mes, anio);
}

int verificaciondia(int *dia, int *mes, int *anio)
{
    int bisiesto = 0, mes2 = 0, dia2 = 0, anio2 = 0;

    mes2 = verificacionmes(mes);
    anio2 = verificacionanio(anio);
    bisiesto = esBisiesto(anio);
    if (*mes == 2 && bisiesto == 1 && (*dia > 0 || *dia <= 29))
    else if ((*mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12) && (*dia > 0 || *dia <= 31))
    else if ((*mes == 2 || *mes == 4 || *mes == 6 || *mes == 9 || *mes == 11) && (*dia > 0 || *dia <= 30))
}

int esBisiesto(int *anio)
{
    int p = 0, q = 0, r = 0;

    if (*anio % 4 == 0)
        p++;
    if (*anio % 100 != 0)
        q++;
    if (*anio % 400 == 0)
        r++;
    if (p == 1 && (q == 1 || r == 1))
}

int verificacionmes(int *mes)
{
    if (*mes <= 0 || *mes > 12)
}

int verificacionanio(int *anio)
{
    if (*anio < 1582)
}
