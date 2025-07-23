#include <stdio.h>
void factorial(int n, int *result) 
{
    if (n == 0 || n == 1) 
    {
        *result = 1;
    } 
    else
    {
        factorial(n - 1, result);
        *result *= n;
    }
}
void potencia(int base, int exponente, int *result) 
{
    if (exponente == 0)
    {
        *result = 1;
    }
    else
    {
        potencia(base, exponente - 1, result);
        *result *= base;
    }
}
int main()
{
    int num, exp;
    int factResult, potResult;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &num);
    factorial(num, &factResult);
    printf("El factorial de %d es %d\n", num, factResult);
    printf("Ingrese la base y el exponente para calcular la potencia (base^exponente): ");
    scanf("%d %d", &num, &exp);
    potencia(num, exp, &potResult);
    printf("%d elevado a la %d es %d\n", num, exp, potResult);
}