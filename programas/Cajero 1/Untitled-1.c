#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"
#include "time.h"
#include "string.h"

void autenti(bool *autenticacion);
void menu(float *saldo);
void consulta(bool *autenticacion, float *saldo);
void retiro(bool *autenticacion, float *saldo);
void deposito(bool *autenticacion, float *saldo);
int depositoaleatorio(int *xdeposito, float *saldo);

int main (void)
{
    float saldo=0;
    do
    {
        menu(&saldo);
    }
    while (1);
}

void menu(float *saldo)
{
    *saldo=100;
    bool autenticacion=false;
    int opcusuario=0;

    while (1)
    {
        printf("\nBienvenido!\nEscoja su opcion:\n1)Consultar saldo\n2)Retirar Dinero\n3)Depositar Dinero\n4)Salir\n");
        scanf("%d",&opcusuario);
        
        switch(opcusuario)
        {
            case 1:
            {
                consulta(&autenticacion, saldo);
                break;
            }
            case 2:
            {
                retiro(&autenticacion, saldo);
                break;
            }
            case 3:
            {
                deposito(&autenticacion, saldo);
                break;
            }
            case 4:
            {
                return;
            }
            default:
            {
                printf("\nOpcion Invalida!\n");
            }
        }
    }
}

void consulta(bool *autenticacion, float *saldo)
{
    *autenticacion=false;
    autenti(autenticacion);
    if(*autenti==false)
    return;
    else
    {
        printf("\nSu saldo es $%.2f",*saldo);
    }
}

void retiro(bool *autenticacion, float *saldo)
{
    int xretiro=0;
    *autenticacion=false;
    autenti(autenticacion);
    if(*autenticacion==false)
        return;
    else
    {
        printf("\nIngrese la cantidad a retirar en multiplos de 5: ");
        scanf("%d",&xretiro);
        xretiro=ceil(xretiro);
        if (xretiro%5==0)
        {
            if((xretiro<=*saldo)&&(*saldo>0))
            {
            *saldo=*saldo-xretiro;
            printf("\nSu nuevo saldo es $%.2f\n", *saldo);
            }
            else 
            printf("\nSu Saldo es insuficiente para la transacción\n");
        }
    }
}

void deposito(bool *autenticacion, float *saldo)
{   
    int xdeposito;
    xdeposito=0;
    *autenticacion=false;
    autenti(autenticacion);
    if(*autenticacion==false)
        return;
    else    
        {
        printf("\nIngrese la cantidad a a depositar en multiplos de 5: ");
        scanf("%d",&xdeposito);
        if(xdeposito%5==0)
        { 
            xdeposito=depositoaleatorio (&xdeposito, saldo);
            *saldo=*saldo+xdeposito;
        }
        
        }
    return;
        
}
        


int depositoaleatorio(int *xdeposito, float *saldo)
{
    int denran, dinerodep, acum=0,acum5=0,acum10=0,acum20=0;
    srand(time(NULL));
    while(acum<*xdeposito)
    {
        dinerodep=0;
        denran= (rand() % (2 + 1));
        
        if (denran==0)
        {
            dinerodep=5;
            acum5++;
        }
        if ((denran==1)&&(*xdeposito-10>=0))
        {
            dinerodep=10;
            acum10++;
        }
        if ((denran==2)&&(*xdeposito-20>=0))
        {
            dinerodep=20;
            acum20++;
        }
        acum=acum+dinerodep;
    }
    printf ("\nBilletes ingresados\nBilletes de $5: %i\nBilletes de $10: %i\nBilletes de $20: %i",acum5,acum10,acum20);
    printf("\n%d",acum);
    return acum;
     
}

void autenti(bool *autenticacion)
{
    int numtarjetaref=4453, passwref=1234, numtar=0, passw=0,acum=3;
    bool confirm1=false, confirm2=false;
    
    printf("\nBienvenido! Ingrese su número de tarjeta: \nEscriba 0 para salir: ");
    while (confirm1==false)
    {
        scanf("%d",&numtar);
        numtar=ceil(numtar);
        if(numtar<0)
        {
            printf("\nFormato inválido, intente de nuevo:\n");
        }
        else if(numtar==numtarjetaref)
        {
            confirm1=true;
        }
        else if(numtar==0) 
        return;
        else 
        printf("\nTarjeta no reconocida, intentende nuevo");
    }
    while (confirm2==false&&acum>0)
    {
        printf("\nIngrese su contrasena: ");
        scanf("%d",&passw);
        passw=ceil(passw);
        if (passw==passwref)
        {
            confirm2=true;
            *autenticacion=true;
            printf("\nAutenticacion correcta!\n");
        }
        else 
        {
            acum--;
            printf("\nContrasena incorrecta, le quedan %d intentos",acum);
        }
    }
    if (acum==0)
    {
        printf("\nSu cuenta ha sido bloqueada\n");
        return;
    }

}
