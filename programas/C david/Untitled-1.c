#include "stdio.h"
int main (void)
{
    float Tmax=1,tmin=1,Tmediamax=0,tmediamin=0, pe, Sumamax=0, sumamin=0;
    int e=0, d=1;
    while(Tmax!=0&&tmin!=0)
        {
            printf("Ingrese la temperatura maxima: ");
            scanf("%f",&Tmax);
            printf("\nIngrese la temperatura minima: ");
            scanf("%f",&tmin);
            
            if(Tmax==9||tmin==9)
            e++;
        
            Sumamax=Sumamax+Tmax;
            Tmediamax=(Sumamax)/d;
            sumamin=sumamin+tmin;
            tmediamin=(sumamin)/d;
            d++;    
        }
    pe=(e/d)*100;
    printf("\n%f, %f, %f, %i, %i", pe, Tmediamax, tmediamin, d, e);
} 