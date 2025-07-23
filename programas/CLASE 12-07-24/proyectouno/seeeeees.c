#include "stdio.h"
int repetidor(int num)
{
    num--;
    if(num==0)
        return 0;
    printf("\nValor actual %i\n",num);
    return repetidor(num);
}
