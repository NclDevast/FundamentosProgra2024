#include "stdio.h"
#include "stdlib.h"
int main (void)
{
    float dinerousuario=0, ItemA=0.50, ItemB=0.25, ItemC=1.50, dinerofinal=0, ItemD=2.50, ItemE=0.75, precio, moneda, billete,espresso=0.50, capuccino=1.25, americano=1.00, preciocafe,preciofinal;
    int opcusuario=0, opccafe=0, confirmacionventa=0, confirmacioncafe, nivelazucar;
    
    do // Inicio de bucle indefinido del programa para que corra todo el tiempo
    {
     nivelazucar=0, dinerousuario=0,dinerofinal=0, precio=0,confirmacionventa=0, opccafe=0,opcusuario=0,preciocafe=0,moneda=0,billete=0,preciofinal=0,confirmacioncafe=0; // se inicializan las variables al inicio del bucle para que no se acumulen
     do
        {
        system("cls"); // se borra cualquier residuo de anteriores bucles
        printf("MENU\nSeleccione del 1 al 5 su item:\n1) Habas= $0.50\n2) Chicles= $0.25\n3) Cola=$1.50\n4) Sanduche=$2.50\n5) Papas $0,75\n6) Salir\n");
        scanf("%d",&opcusuario);
        system("cls");
        printf("Para ordenar cafe seleccione de nuestras opciones del 1 al 4:\n1) Espresso $0.50\n2) Capuccino $1.25\n3)Americano $1.00\n5) No deseo cafe\n");
        scanf("%d",&opccafe);
        if((opccafe>0)||(opccafe<4))
          {
          printf("Seleccione su nivel deseado de azucar del 1 al 5:\n1)Sin azucar\n2)25%% de azucar\n3)40%% de azucar\n4)50%% de azucar\n4)70%% de azucar\n");
          scanf("%d",&nivelazucar);
          }
        }
        while(((opcusuario<1)||(opcusuario>6))&&((opccafe<1)||(opccafe>4)));  //el bucle se repetirá mientras no se escoja una de las opciones validas
    
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
       else if (opcusuario==5)
       {
            confirmacionventa++;
            precio=ItemE;
       }
       else if(opcusuario==6)
       {
            confirmacionventa++; 
            precio=0;
       }
    }
       while(confirmacioncafe==0)  // el bucle se repetirá a menos de que se escoja una opcion  válida
    {
       if(opccafe==1)
       {
            confirmacioncafe++;
            preciocafe=espresso; 
       } 
       else if(opccafe==2)
       {
            confirmacioncafe++; 
            preciocafe=capuccino;
       }
       else if(opccafe==3)
       {
            confirmacioncafe++; 
            preciocafe=americano;
       }
       else if(opccafe==4)
       {
            confirmacioncafe++; 
            preciocafe=0;
       }
    }
     system("cls");
     preciofinal=preciocafe+precio;
    do{
    if(((precio==0)&&(preciocafe==0))||(dinerousuario==preciofinal)) // Si se escoge la opción de salir, el programa regreserá al bucle del inicio automáticamente
        break;
        printf("Inserte monedas de 1 dolar , 50 , 25 , 10 , 5 ctvs\n");
        scanf("%f",&moneda);
        if((moneda!=1)||(moneda!=50)||(moneda!=25)||(moneda!=10)||(moneda!=5))
        printf("Ingrese solo monedas de 1 dolar , 50 , 25 , 10 , 5 ctvs\n");
        printf("Inserte un billete de 5 dolares\n");
        scanf("%f",&billete);
        system("cls"); //Se encuentra despues del scanf para no borrar el saldo del usuario ni la orden de insertar monedas
        if((moneda==1)||(moneda==50)||(moneda==25)||(moneda==10)||(moneda==5)) // Solo se dará un valor a moneda si se satisface la condición
        moneda=moneda;
        else moneda=0;
        if(moneda==1)    
        moneda=100; //Se cambia el valor de 1 dolar para tener un calculo consitente
        if(billete==5)
        billete=billete;
        else 
        {
          billete=0;
          printf("Solo se aceptan billetes de 5, porfavor, ingrese un billete valido\n");
          system("pause");
        }
        dinerousuario=dinerousuario+billete+(moneda/100); // Se calcula el dinero que ingreso el usuario
        dinerofinal=dinerousuario-preciofinal; // Se calcula cuanto le falta al usuario para pagar al producto
        system("cls"); //Se borra el calulo para solo mostrar al usuario cuanto dinero ha ingresado y se reinicia el bucle
        printf("Su saldo actual es: %.2f\n",dinerousuario);
        }
    while(dinerofinal<=0); //El bucle continuirá hasta que el resultado del dinero usuario menos el precio sea igual o mayor al precio 
    printf("Su vuelto es: %.2f\n",dinerofinal); //En el caso de haber vuelto se imprime el vuelto para el usuario
    printf("\n");
    printf("\nRetire su producto\n");
    if(opccafe==1)
    {
     printf("Espere un momento para su cafe\n");
     printf("...");
     printf("Retire su producto\n");
    }
    system("pause");
    system("cls"); // Ultimo clear del bucle
  } while(1); //La condicion es verdadera, por lo que el bucle regreserá al principio

return 0;
}