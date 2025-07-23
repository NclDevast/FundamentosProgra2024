#include <stdio.h>
void fecha(int *dia, int *mes, int *ano);
int main() 
{
    int dia, mes, ano;
    printf("Ingrese el día: ");
    scanf("%d",&dia);
    printf("\nIngrese el mes: ");
    scanf("%d",&mes);
    printf("\nIngrese el año: ");
    scanf("%d",&ano);
    fecha(&dia,&mes,&ano);
}

void fecha(int *dia, int *mes, int *ano)
{
    int ano_corto=*ano%100;
    printf("\n%d/%d/%02d\n", *dia, *mes, ano_corto);
}