#include <stdio.h>
#include <math.h>

// Definición de la nueva función que combina fabs() y ceil()
double fabs_ceil(double num);

int main() 
{
    double num1;
    printf("Ponga su numero decimal negativo\n");
    scanf("%f",num1);
    printf("fabs_ceil(%.1f) = %.1f\n", num1, fabs_ceil(num1));
    return 0;
}

double fabs_ceil(double num)
{
    // Primero obtenemos el valor absoluto de num
    double abs_value = fabs(num);
    // Luego redondeamos el valor absoluto hacia arriba
    return(abs_value);
}
