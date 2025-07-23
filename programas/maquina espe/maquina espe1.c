#include "stdio.h"
#include "stdlib.h"
int main (void)
{
    float dinerousuario=0, ItemA=0.50, ItemB=0.25, ItemC=1.50, dinerofinal=0, ItemD=2.50,precio, moneda;
    int opcusuario=0, confirmacionventa=0;
    
    do // Inicio de bucle indefinido del programa para que corra todo el tiempo
    {
     dinerousuario=0,dinerofinal=0, precio=0,confirmacionventa=0;
     do
        {
        system("cls");
        printf("MENU\nSeleccione del 1 al 5 su item:\n1) Habas= $0.50\n2) Chicles= $0.25\n3) Cola=$1.50\n4) Sanduche=$2.50\n5) Salir\n");
        scanf("%d",&opcusuario);
        }
        while((opcusuario<1)||(opcusuario>5));  //el bucle se repetirá mientras no se escoja una de las opciones validas
    
    while(confirmacionventa==0)  // el bucle se repetirá a menos de que se escoja una opcion  válida
    {
       if(opcusuario==1)
       {
            confirmacionventa++;
            precio=ItemA; 
       } 
       else if(opcusuario==2)
       {
            confirmacionventa++; 
            precio=ItemB;
       }
       else if(opcusuario==3)
       {
            confirmacionventa++; 
            precio=ItemC;
       }
       else if(opcusuario==4)
       {
            confirmacionventa++; 
            precio=ItemD;
       }
       else if(opcusuario==5)
       {
            confirmacionventa++; 
            precio=0;
       }
    }
     system("cls");
    do{
    if((precio==0)||(dinerousuario==precio)) // Si se escoge la opción de salir, el programa regreserá al bucle del inicio automáticamente
        break;
        printf("Inserte monedas de 1 dolar , 50 , 25 , 10 , 5 ctvs\n");
        scanf("%f",&moneda);
        system("cls"); //Se encuentra despues del scanf para no borrar el saldo del usuario ni la orden de insertar monedas
        if((moneda==1)||(moneda==50)||(moneda==25)||(moneda==10)||(moneda==5)) // Solo se dará un valor a moneda si se satisface la condición
        moneda=moneda;
        else moneda=0;
        if(moneda==1)    
        moneda=100; //Se cambia el valor de 1 dolar para tener un calculo consitente
        dinerousuario=dinerousuario+(moneda/100); // Se calcula el dinero que ingreso el usuario
        dinerofinal=dinerousuario-precio; // Se calcula cuanto le falta al usuario para pagar al producto
        system("cls"); //Se borra el calulo para solo mostrar al usuario cuanto dinero ha ingresado y se reinicia el bucle
        printf("Su saldo actual es: %.2f\n",dinerousuario);
        }
    while(dinerofinal<=0); //El bucle continuirá hasta que el resultado del dinero usuario menos el precio sea igual o mayor al precio 
    printf("Su vuelto es: %.2f\n",dinerofinal); //En el caso de haber vuelto se imprime el vuelto para el usuario
    printf("\n");
    printf("\nRetire su producto\n");
    system("pause");
    system("cls"); // Ultimo clear del bucle
  } while(1); //La condicion es verdadera, por lo que el bucle regreserá al principio

return 0;
}