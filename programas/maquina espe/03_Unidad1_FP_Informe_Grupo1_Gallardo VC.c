#include "stdio.h"
#include "stdlib.h"
int main (void)
{
    float dinerousuario=0, ItemA=22.50, ItemB=15.25, ItemC=30.50, dinerofinal=0, ItemD=40.50, ItemE=61.75, precio, billete;
    int opcusuario=0, confirmacionventa=0;
    
    do // Inicio de bucle indefinido del programa para que corra todo el tiempo
    {
     dinerousuario=0,dinerofinal=0, precio=0,confirmacionventa=0; // se inicializan las variables al inicio del bucle para que no se acumulen
     do
        {
        system("cls"); // se borra cualquier residuo de anteriores bucles
        printf("MENU\nSeleccione del 1 al 5 su item:\n1) Habas= $22.50\n2) Chicles= $15.25\n3) Cola=$30.50\n4) Sanduche=$40.50\n5) Papas $61,75\n6) Salir\n");
        scanf("%d",&opcusuario);
        }
        while((opcusuario<1)||(opcusuario>6));  //el bucle se repetirá mientras no se escoja una de las opciones validas
    
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
     system("cls");
    do{
    if((precio==0)||(dinerousuario==precio)) // Si se escoge la opción de salir, el programa regreserá al bucle del inicio automáticamente
        break;
        printf("Inserte un billete de 1,5,10 o 20 dolares\n");
        scanf("%f",&billete);
        system("cls"); //Se encuentra despues del scanf para no borrar el saldo del usuario ni la orden de insertar monedas
        if((billete==1)||(billete==5)||(billete==10)||(billete==20))
        billete=billete;
        else 
        {
          billete=0;
          printf("Solo se aceptan billetes de 1,5,10,20, porfavor, ingrese un billete valido\n");
          system("pause");
        }
        dinerousuario=dinerousuario+billete; // Se calcula el dinero que ingreso el usuario
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