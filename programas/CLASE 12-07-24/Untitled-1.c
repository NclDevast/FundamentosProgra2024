#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main (void)
{
    int num=0;
    srand(time(NULL));
    num=rand()%(84+1-1)+1;
    printf("%d",num);
    
}