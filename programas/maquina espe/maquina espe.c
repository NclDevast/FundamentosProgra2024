#include "stdio.h"
int main (void)
{
    float dinerousuario, ItemA=0.50, ItemB=0.25, ItemC=1.50, dinerofinal=0, ItemD=2.50;
    int opcusuario=0, confirmacionventa=0;
    do{
        dinerousuario=0;
        printf("Bienvenido, los precios son los siguientes: \nItemA=0.50\nItemB=0.25\nItemC=1.50\nPor favor, ingrese de 0.25 a 5 dolares.\n");
        scanf("%f",&dinerousuario);
        }
        while ((dinerousuario<0.25)||(dinerousuario>5));
    do
        {
        printf("Seleccione del 1 al 5 su item:\nItemA=1\nItemB=2\nItemC=3\nItemD=2.50\nSalir\n");
        scanf("%d",&opcusuario);
        }
        while((opcusuario<0)||(opcusuario>6));

    while(confirmacionventa==0)
    {
       if((opcusuario==1)&&(ItemA<=dinerousuario))
       {
            dinerofinal=dinerousuario-ItemA;
            confirmacionventa++; 
            break;
       } 
       else if((opcusuario==2)&&(ItemB<=dinerousuario))
       {
            dinerofinal=dinerousuario-ItemB;
            confirmacionventa++; 
            break;
       }
       else if((opcusuario==3)&&(ItemC<=dinerousuario))
       {
            dinerofinal=dinerousuario-ItemC;
            confirmacionventa++; 
            break;
       }
       else if((opcusuario==4)&&(ItemD<=dinerousuario))
       {
            dinerofinal=dinerousuario-ItemD;
            confirmacionventa++; 
            break;
       }
       else if(opcusuario==5)
       {
            dinerofinal=dinerousuario;
            confirmacionventa++; 
            break;
       }
    }
    printf("Su vuelto es: %f",dinerofinal);
    return 0;
}