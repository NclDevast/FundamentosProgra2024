#include "stdio.h"
#include "math.h"

int main(void)
{
    int x,y,s,s1;
    x=4;
    y=3;
    s=pow(x,y); // s= 4 elevado a la 3 potencia
    s1=sqrt(x); // s1= raiz cuadrada de 4
    printf("%d",s);
    printf("\n%d",s1);
    return 0;
}