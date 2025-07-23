#include "stdio.h"

int main (void)
{
    int i=0;
    int conjunto[4];

    for(i=0;i<4;i++)
    {
        printf("\ningrese un elemtento[%i]",i);
        scanf("%i",&conjunto[i]);
    }
    for(i=0;i<4;i++)
    {
        printf("\nElemento=[%i]",i);
    }
}