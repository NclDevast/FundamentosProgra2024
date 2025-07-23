#include "stdio.h"
int main (void)
{
    float capitalf=0, capitali, interes;
    int n=1;
    printf("Esciba su capital inicial\n");
    scanf("%f",&capitali);
    printf("Escriba su tasa de interes\n");
    scanf("%f",&interes);
    if((capitali>0)&&(interes>0)&&(interes<100))
        {
            do 
            {
            capitalf=capitali*(1+(interes*n));
            n++;
            }
            while(capitalf <= (2*capitali));
            n=n-1;
        printf("Su capital se doblara a los %i años",n);
        }
return 0;
}