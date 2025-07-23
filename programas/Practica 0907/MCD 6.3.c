#include "stdio.h"

int leer();
void mcd(int *num1,int *num2,int *num3,int *num4, int *mcdre);

int main (void)
{
int numero1=0, numero2=0, numero3=0, numero4=0,mcdresultado=0;
int *num1=&numero1,*num2=&numero2,*num3=&numero3,*num4=&numero4,*mcdre=&mcdresultado;

*num1=leer();
*num2=leer();
*num3=leer();
*num4=leer();
printf("%d,%d,%d,%d",*num1,*num2,*num3,*num4);
mcd(num1,num2,num3,num4,mcdre);
printf("\nSu mcd es igual a: %d",*mcdre);
return 0;
}

int leer()
{
    int a;
    printf("\nIngrese su numero: ");
    scanf("%d",&a);
    return a;
}

void mcd(int *num1,int *num2,int *num3,int *num4, int *mcdre)
{
    int i=2;
    *mcdre=1;
    while((i<=*num1==1||i<=*num2==1||i<=*num3==1||i<=*num4==1))
    {
        if(*num1%i==0)
        {
            *num1=*num1/i;
            printf("\nprimer num=%d",*num1);
        }
        if (*num2%i==0)
        {
            *num2=*num2/i;
            printf("\nsegundo num=%d",*num2);
        }
        if (*num3%i==0)
        {
            *num3=*num3/i==0;
            printf("\ntercer num=%d",*num3);
        }
        if (*num4%i==0)
        {
            *num4=*num4/i==0;
            printf("\ncuarto num=%d",*num4);
        }
        if(*num1%i!=0&&*num2%i!=0&&*num3%i!=0&&*num4%i!=0)
        {
        i++;
        *mcdre=*mcdre*i;
        }
        printf("\nmcd igual a= %d",*mcdre);
    }
}
