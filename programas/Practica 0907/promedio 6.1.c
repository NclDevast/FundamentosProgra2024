#include "stdio.h"

double leer(double a);
double calculopromedio(double s, int i);

int main (void)
{
    int confirmacion=0, opcusuario=0,i=0;
    double a=0,s=0,promedio;
    while(confirmacion==0)
    {
        printf("\n1)Agregar un nuevo numero\n2)Encontrar promedio");
        scanf("%d",&opcusuario);
        switch(opcusuario)
        {
            case 1:
            {
                a=leer(a);
                s=a+s;
                i=i+1;
                printf("\nacum=%d, suma=%lf",i,s);
                break;
            }
            case 2:
            {
                promedio=calculopromedio(s,i);
                printf("\nEl promedio es igual a %.2lf\n",promedio);
                confirmacion++;
                break;
            }
            default:
            {
                printf("\nOpcion invalida");
            }
        }
    }


}

double leer(double a)
{
    printf("\nIngrese un numero: \n");
    scanf("%lf",&a);
    return a;
}

double calculopromedio(double s, int i)
{
    int resultado=0;
    printf("\nsuma=%lf,cont=%d",s,i);
    resultado=s/i;
    return resultado;
}