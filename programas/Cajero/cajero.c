#include "stdio.h"
#include "stdlib.h"
int main (void)
{
    int opcusuario, numtarjeta, pin, confirmacionauti, confirmaciontrans, erroraut, numtarjetaref=1234, PINref=1234, conterr=0;
    float saldousuario=1000, retiro, deposito, saldonuevo=0;
    do
    {
        confirmacionauti=0, confirmaciontrans=0, erroraut=0, saldonuevo=0,conterr=3;
        
            printf("Bienvenido al cajero, escoja una opcion:\n1)Consulte su saldo\n2)Retirar dinero\n3)Depositar dinero\n4)Salir\n");
            scanf("%d",&opcusuario);

            switch(opcusuario)
            {
                case 1:

                while(confirmacionauti==0&&erroraut<3)
                {
                system("cls");
                printf("Ingrese su numero de tarjeta: ");
                scanf("%d",&numtarjeta);
                printf("\nIngrese su PIN: ");
                scanf("%d",&pin);
                if((pin==PINref)&&(numtarjeta==numtarjetaref))
                confirmacionauti++;
                else 
                {
                    erroraut++;
                    conterr=conterr-erroraut;
                    printf("\nNumero de tarjeta o PIN incorrecto. Le quedan %d intentos",conterr);
                    system("pause");
                }
                }
                if(confirmacionauti>0)
                {
                    printf("\nSu dinero saldo actual es: %.2f",saldousuario);
                    printf("\n");   
                    system("pause");
                }
                if(erroraut==3)
                {
                    printf("\nSu cuenta ha sido bloqueada");
                    printf("\n");
                    system("pause");
                }
                confirmaciontrans++;
                break;

                case 2:

                while(confirmacionauti==0&&erroraut<3)
                {
                system("cls");
                printf("Ingrese su numero de tarjeta: ");
                scanf("%d",&numtarjeta);
                printf("\nIngrese su PIN: ");
                scanf("%d",&pin);
                if((pin==PINref)&&(numtarjeta==numtarjetaref))
                confirmacionauti++;
                else  
                {
                    erroraut++;
                    conterr=conterr-erroraut;
                    printf("\nNumero de tarjeta o PIN incorrecto. Le quedan %d intentos",conterr);
                }
                }
                if(confirmacionauti>0)
                {
                    printf("\nIngrese por teclado la cantidad que va a retirar: ");
                    scanf("%f",&retiro);
                    saldonuevo=saldousuario-retiro;
                    if(saldonuevo<0)
                    {
                    printf("\nNo tiene el sado suficiente para continuar.");
                    printf("\n");
                    system("pause");
                    }
                    else 
                    {
                    printf("\nSu dinero saldo actual es: %.2f",saldonuevo);
                    saldousuario=saldonuevo;
                    system("pause");
                    }
                }
                
                if(erroraut==3)
                {
                printf("\nSu cuenta ha sido bloqueada");
                printf("\n");
                system("pause");
                } 
                confirmaciontrans++;
                break;
                
                case 3:

                while(confirmacionauti==0&&erroraut<3)
                {
                system("cls");
                printf("Ingrese su numero de tarjeta: ");
                scanf("%d",&numtarjeta);
                printf("\nIngrese su PIN: ");
                scanf("%d",&pin);
                if((pin==PINref)&&(numtarjeta==numtarjetaref))
                confirmacionauti++;
                else 
                {
                    erroraut++;
                    conterr=conterr-erroraut;
                    printf("\nNumero de tarjeta o PIN incorrecto. Le quedan %d intentos",conterr);
                }
                }
                if(confirmacionauti>0)
                {
                    printf("\nIngrese por teclado la cantidad que va a depositar: ");
                    scanf("%.2f",&deposito);
                    saldonuevo=saldousuario+deposito;
                    saldousuario=saldonuevo;
                    printf("\nSu saldo actual es $%f",saldousuario);
                    printf("\n");
                    system("pause");
                }
                if(erroraut==3)
                {
                printf("\nSu cuenta ha sido bloqueada");
                printf("\n");
                system("pause");
                }
                confirmaciontrans++;
                break;

                case 4:
            
                system("cls");
                confirmaciontrans++;
                break;

                default: 
                system("cls");
                printf("\nSeleccione una opción valida");
                }
                
                system("cls");
                printf("\nGracias por confiar en nosotros.");
                printf("\n");
                system("pause");
                system("cls");
            }
    while(1);
        
    }
