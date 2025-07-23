#include "stdio.h"
#include "stdbool.h"
int main (void)
{
    int num1, i=2;
    bool esprimo=true;
    scanf("%d",&num1);

    do {
        if(num1%i==0)
        esprimo=false;
        break;
    }
    while (i<num1);
        {
        i++;
        }
    if (esprimo==true)
    printf("Primo");
    else printf("No primo");
return 0;
}