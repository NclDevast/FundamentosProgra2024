#include "stdio.h"
#include "math.h"

double leer(double a);
double cartx(double a, double b);
double carty(double a, double b);

int main(void)
{
double a,b,s=0,s1=0;
printf("Ingrese el valor del Radio: \n");
a=leer(a);
printf("Ingrese el valor del angulo en radianes: \n");
b=leer(b);
s=cartx(a,b);
s1=carty(a,b);
printf("Las cordenadas cartesianas son x = %.2lf;y= %.2lf",s,s1);
}

double leer (double a)
{
    scanf("%lf",&a);
    return a;
}

double cartx(double a, double b)
{
    int s;
    s=a*cos(b);
    return s;
}

double carty(double a, double b)
{
    int s;
    s=a*sin(b);
    return s;
}