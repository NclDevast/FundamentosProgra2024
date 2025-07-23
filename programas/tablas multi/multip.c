#include "stdio.h"
int main (void)
{
    int num, n=1, resultado=0;
    printf("Escriba su numero\n");
    scanf("%d",&num);
    
    if((num>0)&&(num<=15));
    {
        do
        {
            resultado=num*n;
            printf("%d  %d\n",n,resultado);
            n++;
        }
        while(n<=15);
    }
    return 0;
}